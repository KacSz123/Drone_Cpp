#pragma once
#include "vector2d.hpp"
#include "iostream"
template<typename T, unsigned int Size>
class Matrix2x2{
T matrix[Size][Size];
private:
public:
Matrix2x2();
Matrix2x2(double,double,double,double);
inline double const getValue(int i, int j){return this->matrix[i][j];}
inline void setValue(int i, int j, double val){ this->matrix[i][j]=val;}
friend std::istream& operator >> (std::istream& istrm, Matrix2x2& matrixx)
{
    double val = 0;
    for(int i=0; i<2;++i)
    {   
         for(int j=0; j<2;++j)
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
using std::istream;
using std::ostream;

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
Vector2d<double, 2> operator * (Matrix2x2<T, Size> m, Vector2d<double, 2> v)
{
    Vector2d<double, 2> result;
    for (int i =0; i<2; ++i)
    {
        for(int j=0; j<2;++j)
        {
            result.setCoord(i, result[i]+(m(i,j)*v[j]));
        }
    }

    return result;
}
