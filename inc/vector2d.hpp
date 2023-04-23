#pragma once
#include<iostream>
class Vector2d{
private:
double coordinates[2];
public:
Vector2d();
Vector2d(double, double);
void setCoord(double x, double y);
inline void setCoord(int i, double val){this->coordinates[i]=val;};
inline double const getX(){return this->coordinates[0];};
inline double const getY(){return this->coordinates[1];};
inline double const getXorY(int i){return this->coordinates[i];};

inline double operator[](int i){return this->coordinates[i];  };
}; 

std::ostream& operator << (std::ostream&, Vector2d );
Vector2d operator + (Vector2d, Vector2d);
Vector2d& operator += (Vector2d& vec1, Vector2d vec2);