
#include <iostream>
#include <cmath>
#include "cuboid.hpp"
#include "geometric_obj.hpp"


Cuboid::Cuboid(vector3D midPt, double lenX, double lenY, double lenZ):GeometricObj(8)
{
    this->setMidPoint(midPt);
    
    this->setVertexCoords(0, midPt[0] + lenX / 2, midPt[1] - lenY / 2, midPt[2] + lenZ / 2);
    this->setVertexCoords(1, midPt[0] + lenX / 2, midPt[1] + lenY / 2, midPt[2] + lenZ / 2);
    this->setVertexCoords(6, midPt[0] - lenX / 2, midPt[1] - lenY / 2, midPt[2] + lenZ / 2);
    this->setVertexCoords(7, midPt[0] - lenX / 2, midPt[1] + lenY / 2, midPt[2] + lenZ / 2);
    this->setVertexCoords(2, midPt[0] + lenX / 2, midPt[1] - lenY / 2, midPt[2] - lenZ / 2);
    this->setVertexCoords(3, midPt[0] + lenX / 2, midPt[1] + lenY / 2, midPt[2] - lenZ / 2);
    this->setVertexCoords(4, midPt[0] - lenX / 2, midPt[1] - lenY / 2, midPt[2] - lenZ / 2);
    this->setVertexCoords(5, midPt[0] - lenX / 2, midPt[1] + lenY / 2, midPt[2] - lenZ / 2);
}

std::ostream &operator<<(std::ostream &strm, Cuboid rect)
{
    vector3D *x = new vector3D, *m = new vector3D, *y=new vector3D;
    (*x)= rect.getCorner(0);
    (*y) = rect.getCorner(1);
    (*m) = rect.getMidPoint();
    
    vector3D *mLeft= new vector3D((*m)[0], (*x)[1], (*m)[2]), *mRight =new vector3D((*m)[0], (*y)[1], (*m)[2]);

    for (int i = 0; i < 8; ++i)
    {
        if (i % 2 == 0)
            strm << (*mLeft) << "\n";
        strm << rect.getCorner(i) << "\n";
        if (i % 2 == 1)
            strm <<(*mRight) << "\n\n";
    }
    strm <<( *mLeft) << "\n"
         << rect.getCorner(0) << "\n"
         << rect.getCorner(1) << "\n"
         << (*mRight) << "\n";
    delete mLeft;
    delete mRight;
    delete x;
    delete y;
    delete m;
    return strm;
}
