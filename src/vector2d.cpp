
#include <iostream>
#include "vector2d.hpp"


void Vector2d::setCoord(double x,double y)
{
    this->coordinates[0]=x;
    this->coordinates[1]=y;
}


double Vector2d::getX()
{
    return this->coordinates[0];
}
double Vector2d::getY()
{
    return this->coordinates[1];
}
Vector2d::Vector2d()
{
    this->coordinates[0]=0;
    this->coordinates[1]=0;
}
Vector2d::Vector2d(double x, double y)
{
    this->coordinates[0]=x;
    this->coordinates[1]=y;
}

Vector2d operator + (Vector2d v1, Vector2d v2)
{
    Vector2d wynik;
    wynik.setCoord(v1.getX()+v2.getX(), v1.getY()+v2.getY());
    return wynik;
}

std::ostream& operator << (std::ostream& ostrm, Vector2d v)
{
    ostrm<<"["<<v.getX()<<","<<v.getY()<<"]\n";
    return ostrm;
}