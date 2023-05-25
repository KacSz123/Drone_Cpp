#include "geometric_obj.hpp"
#include "hexagonal_prism.hpp"
#include<cmath>
HexagonalPrism::HexagonalPrism(vector3D midPt, double height, double radius):GeometricObj(12)
{
    Matrix3x3 *m = new Matrix3x3;
    vector3D *vup = new vector3D;
    vector3D *vdown = new vector3D;
    double angle = 2.0*(M_PI/6.0);
    m->getZrotationMatrix(angle);

    (*vup).setCoords(radius,0, height/2.0);
    (*vup) = (*vup) + midPt;
    (*vdown).setCoords(radius,0, -height/2.0);
    (*vdown)=(*vdown)+midPt;

    this->setMidPoint(midPt);
    for(int i =0; i<6; ++i)
    {
        this->setVertex(i,(*vup));
        this->setVertex(i+6,(*vdown));

        (*vup)=(*m)*(*vup);
        (*vdown)=(*m)*(*vdown);
    }

    delete m;
    delete vup;
    delete vdown;
}
std::ostream& operator<< (std::ostream& ostr, HexagonalPrism hex)
{
    vector3D mup=hex.getMidPoint(), mDown=hex.getMidPoint();
    mup.setCoord(2, hex.getVertex(0).getCoord(2));
    mDown.setCoord(2, hex.getVertex(6).getCoord(2));

    for(int i =0; i<6; ++i)
    {
        ostr<<mup<<"\n"<<hex.getVertex(i)<<"\n"<<hex.getVertex(i+6)<<"\n"<<mDown<<"\n\n";    
    }
     ostr<<mup<<"\n"<<hex.getVertex(0)<<"\n"<<hex.getVertex(6)<<"\n"<<mDown<<"\n";
    return ostr;
}