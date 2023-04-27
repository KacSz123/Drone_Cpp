
#include<iostream>
#include "cuboid.hpp"
#include <cmath>

Cuboid::Cuboid()
{
    Vector2d<double, 3> vec;
    for (int i=0; i<8; ++i)
    {
        this->coordinates[i]=vec;
    }
}

Cuboid::Cuboid(Vector2d<double, 3> midPt, double lenX, double lenY, double lexZ)
{

    this->midPoint=midPt;
    // this->coordinates[0].setCoord(startX, startY);
    // this->coordinates[1].setCoord(startX, startY-lenY);
    // this->coordinates[2].setCoord(startX+lenX, startY-lenY);
    // this->coordinates[3].setCoord(startX+lenX, startY);

}


std::ostream& operator << (std::ostream& ostrm, Cuboid rect)
{

    for (int i  = 0; i<8; ++i)
    ostrm << rect.getCorner(i)<<"\n";

    return ostrm;
}



void Cuboid :: rotateXaxis(double angle)
{   
    double radians = angle*(M_PI/180.0);
    Matrix2x2<double, 3> m;
    m.getXrotationMatrix(angle);
    for(int i=0; i<8; ++i)
    {
        this->coordinates[i] = m*this->coordinates[i];
    }

}

void Cuboid :: rotateYaxis(double angle)
{   
    double radians = angle*(M_PI/180.0);
    Matrix2x2<double, 3> m;
    m.getYrotationMatrix(angle);
    for(int i=0; i<8; ++i)
    {
        this->coordinates[i] = m*this->coordinates[i];
    }

}

void Cuboid :: rotateXaxis(double angle)
{   
    double radians = angle*(M_PI/180.0);
    Matrix2x2<double, 3> m;
    m.getYrotationMatrix(angle);
    for(int i=0; i<8; ++i)
    {
        this->coordinates[i] = m*this->coordinates[i];
    }

}


void Cuboid :: moveCuboid(Vector2d<double, 3> vec)
{
    for(int i=0; i<8;++i)
    {
        this->setCorner(i, this->getCorner(i)+vec);
    }
}



Cuboid& operator += (Cuboid& rect, Vector2d<double, 3> vec)
{
    for(int i=0; i<8;++i)
    {
        rect.setCorner(i, rect.getCorner(i)+vec);
    }

    return rect;
}
