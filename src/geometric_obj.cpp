
#include "geometric_obj.hpp"


GeometricObj::GeometricObj()
{
    for (int i = 0; i < 3; ++i)
    {
        this->_orientMatrix(i, i) = 1;
    }
}
GeometricObj::GeometricObj(int a)
{   vector3D *vec = new vector3D;
    for (int i = 0; i < 3; ++i)
    {
        this->_orientMatrix(i, i) = 1;
    }
    for(int i = 0; i<a; ++i)
        this->_vertexes.push_back(*vec);

    delete vec;
}
void GeometricObj::move(Vector2d<double,3> vec)
{
 for(VertexVec::iterator i = this->_vertexes.begin(); i!=this->_vertexes.end(); i++)
    *i = *i+vec;
}
void GeometricObj::moveForward(double x)
{
    vector3D v;
    v.setCoords(x, 0,0);
    // this->midPoint += this->orientation *v;

    this->setMidPoint( this->getMidPoint() + this->getOrientation() * v);

    for (int i=0; i<int(this->_vertexes.size()); i++)
    {
         this->setVertex(i, this->getCorner(i)+(this->getOrientation() * v));
        
    }
}


void GeometricObj::rotate(double angle, char axis)
{
    double radians = angle * (M_PI / 180.0);
    Matrix3x3 m;
    if (axis =='X' ||axis =='x'){
    m.getXrotationMatrix(radians);
    }
    else if (axis =='Y' ||axis =='y') 
    {
        m.getYrotationMatrix(radians);
    }
    else if (axis =='Z' ||axis =='z') 
    {
        m.getZrotationMatrix(radians);
    }
    else
    {
        std::cout<<"nie rozpoznano znaku\n nastepuje rotacja wokol osi \'Z\'\n";

        m.getZrotationMatrix(radians);
    }
    this->setOrientation(this->getOrientation() * m);
for(VertexVec::iterator i = this->_vertexes.begin(); i!=this->_vertexes.end(); i++)
    {
        *i = *i-this->_midPoint;
        *i = m*(*i);
        *i = *i+this->_midPoint;
    }
}


