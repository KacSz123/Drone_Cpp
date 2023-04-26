
#include<iostream>
#include "rectangle.hpp"
#include <cmath>

Rectangle::Rectangle()
{
    Vector2d<double, 2> vec;
    for (int i=0; i<4; ++i)
    {
        this->coordinates[i]=vec;
    }
}

Rectangle::Rectangle(double startX, double startY, double lenX, double lenY)
{
    this->coordinates[0].setCoord(startX, startY);
    this->coordinates[1].setCoord(startX, startY-lenY);
    this->coordinates[2].setCoord(startX+lenX, startY-lenY);
    this->coordinates[3].setCoord(startX+lenX, startY);

}


std::ostream& operator << (std::ostream& ostrm, Rectangle rect)
{
    ostrm << rect.getCorner(0)<<"\n"<< rect.getCorner(1)
    <<"\n"<< rect.getCorner(2)<<"\n"<< rect.getCorner(3)<<"\n";
    return ostrm;
}



void Rectangle :: rotateRectangle(double angle)
{   
    double radians = angle*(M_PI/180.0);
    Matrix2x2 m(cos(radians), -sin(radians),
                sin(radians), cos(radians));

    for(int i=0; i<4; ++i)
    {
        this->coordinates[i] = m*this->coordinates[i];
    }

}


void Rectangle :: moveRectangle(Vector2d<double, 2> vec)
{
    for(int i=0; i<4;++i)
    {
        this->setCorner(i, this->getCorner(i)+vec);
    }
}



Rectangle& operator += (Rectangle& rect, Vector2d<double, 2> vec)
{
    for(int i=0; i<4;++i)
    {
        rect.setCorner(i, rect.getCorner(i)+vec);
    }

    return rect;
}
