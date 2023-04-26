
#include<iostream>
#include "cuboid.hpp"
#include <cmath>

Cuboid::Cuboid()
{
    Vector2d<double, 2> vec;
    for (int i=0; i<4; ++i)
    {
        this->coordinates[i]=vec;
    }
}

Cuboid::Cuboid(double startX, double startY, double lenX, double lenY)
{
    this->coordinates[0].setCoord(startX, startY);
    this->coordinates[1].setCoord(startX, startY-lenY);
    this->coordinates[2].setCoord(startX+lenX, startY-lenY);
    this->coordinates[3].setCoord(startX+lenX, startY);

}


std::ostream& operator << (std::ostream& ostrm, Cuboid rect)
{
    ostrm << rect.getCorner(0)<<"\n"<< rect.getCorner(1)
    <<"\n"<< rect.getCorner(2)<<"\n"<< rect.getCorner(3)<<"\n";
    return ostrm;
}



void Cuboid :: rotateCuboid(double angle)
{   
    double radians = angle*(M_PI/180.0);
    Matrix2x2<double, 2> m(cos(radians), -sin(radians),
                sin(radians), cos(radians));

    for(int i=0; i<4; ++i)
    {
        this->coordinates[i] = m*this->coordinates[i];
    }

}


void Cuboid :: moveCuboid(Vector2d<double, 2> vec)
{
    for(int i=0; i<4;++i)
    {
        this->setCorner(i, this->getCorner(i)+vec);
    }
}



Cuboid& operator += (Cuboid& rect, Vector2d<double, 2> vec)
{
    for(int i=0; i<4;++i)
    {
        rect.setCorner(i, rect.getCorner(i)+vec);
    }

    return rect;
}
