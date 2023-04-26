#pragma once
#include "vector2d.hpp"
#include "iostream"
class Matrix2x2{
double matrix[2][2];
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


std::ostream& operator << (std::ostream& ostrm,Matrix2x2 const matrixx);

Vector2d<double, 2> operator * (Matrix2x2 m, Vector2d<double, 2> v);
