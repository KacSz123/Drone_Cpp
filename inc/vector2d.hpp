#pragma once
#include<iostream>

template<typename T, unsigned int Size>
class Vector2d{
private:
T coordinates[Size];
public:
Vector2d();
Vector2d(double, double,double);
void setCoords(double x, double y, double z) {this->coordinates[0]=x;this->coordinates[1]=y;this->coordinates[2]=z;};
void setCoord(int i, T val){ this->coordinates[i]=val;};
inline T getCoord(int i){return this->coordinates[i];};
inline double& operator[](int i){return this->coordinates[i];  };

}; 

template<typename T, unsigned int Size>
Vector2d<T,Size>::Vector2d()
{
    this->coordinates[0]=0;
    this->coordinates[1]=0;
}
template<typename T, unsigned int Size>
Vector2d<T,Size>::Vector2d(double x, double y,double z)
{
    this->coordinates[0]=x;
    this->coordinates[1]=y;
    this->coordinates[2]=z;
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
Vector2d<T, Size> operator - (Vector2d<T,Size> vec1, Vector2d<T,Size> vec2)
{
    Vector2d<T, Size> wynik;
    for(int i =0; i<int(Size); ++i)
        wynik.setCoord(i, vec1.getCoord(i)-vec2.getCoord(i));
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

template<typename T, unsigned int Size>
Vector2d<T,Size>& operator -= (Vector2d<T,Size>& vec1, Vector2d<T,Size> vec2)
{
    for(int i =0; i<int(Size); ++i)
        vec1.setCoord(i, vec1.getCoord(i)-vec2.getCoord(i));
    return vec1;
}

template<typename T, unsigned int Size>
Vector2d<T,Size>& operator * (Vector2d<T,Size>& vec1, double a)
{
    for(int i =0; i<int(Size); ++i)
        vec1.setCoord(i, vec1.getCoord(i)*a);
    return vec1;
}

////
typedef Vector2d<double,3> vector3D;
