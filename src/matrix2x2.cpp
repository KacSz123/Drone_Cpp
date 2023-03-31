
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