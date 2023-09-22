
#include <iostream>
#include <cmath>
#include "cuboid.hpp"
#include "geometric_obj.hpp"
#include <fstream>
Cuboid::Cuboid(const vector3D &midPt,const double lenX, const double lenY,const double lenZ, const double y) : GeometricObj(8), y{y}
{

    // std::cout<<midPt<<std::endl;
    

    this->setMidPoint(midPt);

    this->setVertexCoords(0, midPt[0] + lenX / 2, midPt[1] - lenY / 2, midPt[2] + lenZ / 2);
    this->setVertexCoords(1, midPt[0] + lenX / 2, midPt[1] + lenY / 2, midPt[2] + lenZ / 2);
    this->setVertexCoords(2, midPt[0] + lenX / 2, midPt[1] - lenY / 2, midPt[2] - lenZ / 2);
    this->setVertexCoords(3, midPt[0] + lenX / 2, midPt[1] + lenY / 2, midPt[2] - lenZ / 2);
    this->setVertexCoords(4, midPt[0] - lenX / 2, midPt[1] - lenY / 2, midPt[2] - lenZ / 2);
    this->setVertexCoords(5, midPt[0] - lenX / 2, midPt[1] + lenY / 2, midPt[2] - lenZ / 2);
    this->setVertexCoords(6, midPt[0] - lenX / 2, midPt[1] - lenY / 2, midPt[2] + lenZ / 2);
    this->setVertexCoords(7, midPt[0] - lenX / 2, midPt[1] + lenY / 2, midPt[2] + lenZ / 2);
}

std::ostream &operator<<(std::ostream &strm, Cuboid &rect)
{
    vector3D *x = new vector3D(rect.getVertex(0)), *m = new vector3D(rect.getMidPoint()), *y = new vector3D(rect.getVertex(1));
    // (*x) = ;
    // (*y) = rect.getVertex(1);
    // (*m) = rect.getMidPoint();
    
    vector3D *mLeft = new vector3D((*m)[0], rect.getMidPoint()[1]-rect.getY(), (*m)[2]), *mRight = new vector3D((*m)[0],  (*m)[1]+rect.getY(), (*m)[2]);

    
    Matrix3x3 ma=rect.getOrientation();
    (*mLeft) = (*mLeft) - rect.getMidPoint();
    (*mLeft) = ma*(*mLeft);
    (*mLeft) = (*mLeft) + rect.getMidPoint();

    (*mRight) = (*mRight) - rect.getMidPoint();
    (*mRight) = ma*(*mRight);
    (*mRight) = (*mRight) + rect.getMidPoint();
    for (int i = 0; i < 8; ++i)
    {
        if (i % 2 == 0)
            strm << (*mLeft) << "\n";
        strm << rect.getVertex(i) << "\n";
        if (i % 2 == 1)
            strm << (*mRight) << "\n\n";
    }
    strm << (*mLeft) << "\n"
         << rect.getVertex(0) << "\n"
         << rect.getVertex(1) << "\n"
         << (*mRight) << "\n";

    // cleaning up
    delete mLeft;
    delete mRight;
    delete x;
    delete y;
    delete m;

    return strm;
}

bool Cuboid::writeToFile(const std::string &filename)
{
    using namespace std;
    ofstream file_stream;
    file_stream.open(filename);
    if (!file_stream.is_open())
    {
        cerr << ":(  File opening to write \"" << filename << "\"" << endl
             << ":(  failed." << endl;
        return false;
    }
    this->WriteToStreamExample(file_stream);
    file_stream.close();
    return !file_stream.fail();
}