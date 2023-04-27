#pragma once
#include "vector2d.hpp"
#include <iostream>
#include <cmath>
using std::istream;
using std::ostream;



template<typename T, unsigned int Size>
class Matrix2x2{
T matrix[Size][Size];
private:
public:
Matrix2x2();
Matrix2x2(double,double,double,double);
inline double const getValue(int i, int j){return this->matrix[i][j];}
inline void setValue(int i, int j, double val){ this->matrix[i][j]=val;}
void  getXrotationMatrix(const double angle);
void  getYrotationMatrix(const double angle);
void  getZrotationMatrix(const double angle);
friend std::istream& operator >> (std::istream& istrm, Matrix2x2<T, Size>& matrixx)
{
    T val = 0;
    for(int i=0; i<Size;++i)
    {   
         for(int j=0; j<Size;++j)
        {
            istrm>>val;
            matrixx.setValue(i,j,val);
        }
    }
    return istrm;
}

double operator ()(int i, int j )
{
    return this->matrix[i][j];
}
};
template<typename T, unsigned int Size>
void Matrix2x2<T, Size>::getXrotationMatrix(const double angle)
{
    if (Size==3)
    {
        Matrix2x2<T, Size> m;
        this(0,0) = 1;
        this(0,1) = 0;
        this(0,2) = 0;

        this(1,0) = 0;
        this(1,1)= cos(angle);
        this(1,2) = -sin(angle);

        this(2,0) = 0;
        this(2,1)= sin(angle);
        this(2,2) = cos(angle);
 
    }
    else    if (Size==2)
    {
        Matrix2x2<T, Size> m;
        m(0,0) = cos(angle);
        m(0,1) = -sin(angle);


        m(1,0) = sin(angle);
        m(1,1)= cos(angle);

    }
}
template<typename T, unsigned int Size>
void Matrix2x2<T, Size>::getYrotationMatrix(const double angle)
{
    if (Size==3)
    {
        Matrix2x2<T, Size> m;
        this(0,0) = cos(angle);
        this(0,1) = 0;
        this(0,2) = -sin(angle);

        this(1,0) = 0;
        this(1,1) = 1; 
        this(1,2) = 0;

        this(2,0) = sin(angle);
        this(2,1)= 0;
        this(2,2) = cos(angle);

    }
    else    if (Size==2)
    {
        Matrix2x2<T, Size> m;
        this(0,0) = cos(angle);
        this(0,1) = -sin(angle);


        this(1,0) = sin(angle);
        this(1,1)= cos(angle);
   

    }

}
template<typename T, unsigned int Size>
void Matrix2x2<T, Size>::getZrotationMatrix(const double angle)
{
        if (Size==3)
    {
        Matrix2x2<T, Size> m;
        this(0,0) =  cos(angle);
        this(0,1) = -sin(angle);
        this(0,2) = 0;

        this(1,0) = -sin(angle);
        this(1,1) =  cos(angle);
        this(1,2) = 0;

        this(2,0) = 0;
        this(2,1) = 0;
        this(2,2) = 1;
 
    }
    else    if (Size==2)
    {
        Matrix2x2<T, Size> m;
        m(0,0) = cos(angle);
        m(0,1) = -sin(angle);


        m(1,0) = sin(angle);
        m(1,1)= cos(angle);

    }
}


template<typename T, unsigned int Size>
Matrix2x2<T, Size>::Matrix2x2()
{

    for(int i=0; i<int(Size);++i)
    {
         for(int j=0; j<int(Size);++j)
        {
            this->matrix[i][j]=0;
        }
    }
}

template<typename T, unsigned int Size>
Matrix2x2<T, Size>::Matrix2x2(double a11, double a12, double a21, double a22)
{

    this->matrix[0][0]=a11;
    this->matrix[0][1]=a12;
    this->matrix[1][0]=a21;
    this->matrix[1][1]=a22;
}
template<typename T, unsigned int Size>
std::ostream& operator << (std::ostream& ostrm,Matrix2x2<T, Size> matrixx)
{
        for(int i=0; i<2;++i)
    {   
        ostrm<<"| ";
         for(int j=0; j<2;++j)
        {
            ostrm<<matrixx.getValue(i,j)<<" ";
        }
        ostrm<<"|";
        ostrm<<std::endl;
    }
    return ostrm; 
}

template<typename T, unsigned int Size>
Vector2d<T, Size> operator * (Matrix2x2<T, Size> m, Vector2d<T, Size> v)
{
    Vector2d<T, Size> result;
    for (int i =0; i<int(Size); ++i)
    {
        for(int j=0; j<int(Size);++j)
        {
            result.setCoord(i, result[i]+(m(i,j)*v[j]));
        }
    }

    return result;
}
