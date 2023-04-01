#pragma once
#include<iostream>
class Vector2d{
private:
double coordinates[2];
public:
Vector2d();
Vector2d(double, double);
void setCoord(double x, double y);
void setCoord(int i, double val){this->coordinates[i]=val;};
double const getX();
double const getY();
double const getXorY(int i){return this->coordinates[i];};

double operator[](int i)
{
    return this->coordinates[i];
}
}; 

std::ostream& operator << (std::ostream&, Vector2d );
Vector2d operator + (Vector2d, Vector2d);
Vector2d& operator += (Vector2d& vec1, Vector2d vec2);