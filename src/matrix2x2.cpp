
#include <iostream>
#include "matrix2x2.hpp"
using std::istream;
using std::ostream;


Matrix2x2::Matrix2x2()
{

    for(int i=0; i<2;++i)
    {
         for(int j=0; j<2;++j)
        {
            this->matrix[i][j]=0;
        }
    }
}

Matrix2x2::Matrix2x2(double a11, double a12, double a21, double a22)
{

    this->matrix[0][0]=a11;
    this->matrix[0][1]=a12;
    this->matrix[1][0]=a21;
    this->matrix[1][1]=a22;
}

std::ostream& operator << (std::ostream& ostrm,Matrix2x2 matrixx)
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


Vector2d<double, 2> operator * (Matrix2x2 m, Vector2d<double, 2> v)
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