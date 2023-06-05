
#include "geometric_obj.hpp"


GeometricObj::GeometricObj()
{
    _orientMatrix = Matrix3x3::getIdentityMatrix();
}
GeometricObj::GeometricObj(int a)

{
    _orientMatrix = Matrix3x3::getIdentityMatrix();
    vector3D vec;
    for(int i = 0; i<a; ++i)
        this->_vertexes.push_back(vec);
    // delete vec;
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

    this->setMidPoint( this->getMidPoint() + this->getOrientation() * v);
    for (uint i=0; i<this->_vertexes.size(); i++)
         this->setVertex(i, this->getCorner(i)+(this->getOrientation() * v));

    // std::cout<<this->getMidPoint()<<std::endl<<std::endl;
}


void GeometricObj::soarForward(double x,double z)
{
    vector3D *v=new vector3D;
    v->setCoords(x, 0,z);


    this->setMidPoint( this->getMidPoint() + this->getOrientation() * (*v));

    for (uint i=0; i<this->_vertexes.size(); i++)
         this->setVertex(i, this->getCorner(i)+(this->getOrientation() * (*v)));

    delete v;
}


void GeometricObj::rotate(double angle, char axis, bool aroundOwnAxis, vector3D extraVec)
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
        std::cout<<"Not accurate sign. Proceed rotation in \'Z\' axis\n";
        m.getZrotationMatrix(radians);
    }
    this->setOrientation(this->getOrientation() * m);
    
for(VertexVec::iterator i = this->_vertexes.begin(); i!=this->_vertexes.end(); ++i)
    {
        if(aroundOwnAxis)
        {
            *i = *i-this->_midPoint;
            *i = m*(*i);
            *i = *i+this->_midPoint;
        }
        else
        {   
            *i = *i-extraVec;
            *i = m*(*i);
            *i = *i+extraVec;
        }
    }
            this->setMidPoint(this->getMidPoint() - extraVec);
            this->setMidPoint(m*this->getMidPoint());
            this->setMidPoint(this->getMidPoint() + extraVec);
}


void GeometricObj::rotateWithStaticOrient(double angle, char axis)
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
    
for(VertexVec::iterator i = this->_vertexes.begin(); i!=this->_vertexes.end(); ++i)
    {
        *i = *i-this->_midPoint;
        *i = m*(*i);
        *i = *i+this->_midPoint;
    }
}

