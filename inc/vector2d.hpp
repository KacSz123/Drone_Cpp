#pragma once
#include<iostream>

template<typename T, unsigned int Size>
class Vector2d{
private:
T coordinates[2];
public:
Vector2d();
Vector2d(double, double);
void setCoord(double x, double y);
void setCoord(int i, T val){ this->coordinates[i]=val;};
inline double const getX(){return this->coordinates[0];};
inline double const getY(){return this->coordinates[1];};
inline double const getXorY(int i){return this->coordinates[i];};
inline T getCoord(int i){return this->coordinates[i];};
inline double operator[](int i){return this->coordinates[i];  };
}; 
template<typename T, unsigned int Size>
void Vector2d<T,Size>::setCoord(double x,double y)
{
    this->coordinates[0]=x;
    this->coordinates[1]=y;
}


// double const Vector2d::getX()
// {return this->coordinates[0];}
// double const Vector2d::getY()
// {
//     return this->coordinates[1];
// }
template<typename T, unsigned int Size>
Vector2d<T,Size>::Vector2d()
{
    this->coordinates[0]=0;
    this->coordinates[1]=0;
}
template<typename T, unsigned int Size>
Vector2d<T,Size>::Vector2d(double x, double y)
{
    this->coordinates[0]=x;
    this->coordinates[1]=y;
}
template<typename T, unsigned int Size>
Vector2d<T, Size> operator + (Vector2d<T,Size> vec1, Vector2d<T,Size> vec2)
{
    Vector2d<T, Size> wynik;
    for(int i =0; i<int(Size); ++i)
        wynik.setCoord(i, vec1.getCoord(i)+vec2.getCoord(i));
    return wynik;
}
template<typename T, unsigned int Size>
std::ostream& operator << (std::ostream& ostrm, Vector2d<T,Size> v)
{
    for(int i =0; i<int(Size); ++i)
        ostrm<<v.getCoord(i)<<" ";
    return ostrm;
}
template<typename T, unsigned int Size>
Vector2d<T,Size>& operator += (Vector2d<T,Size>& vec1, Vector2d<T,Size> vec2)
{
    for(int i =0; i<int(Size); ++i)
        vec1.setCoord(i, vec1.getCoord(i)+vec2.getCoord(i));
    return vec1;
}