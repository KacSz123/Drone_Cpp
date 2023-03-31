#pragma once
#include<iostream>
class Vector2d{
private:
double coordinates[2];
public:
Vector2d();
Vector2d(double, double);
void setCoord(double, double);
double getX();
double getY();
}; 

std::ostream& operator << (std::ostream&, Vector2d );
Vector2d operator + (Vector2d, Vector2d);