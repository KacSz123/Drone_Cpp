
#include<iostream>
#include "cuboid.hpp"
#include <cmath>

Cuboid::Cuboid()
{
    Vector2d<double, 3> vec;
    for (int i=0; i<8; ++i)
    {
        this->coordinates[i]=vec;
    }
}

Cuboid::Cuboid(Vector2d<double, 3> midPt, double lenX, double lenY, double lenZ)
{

    this->midPoint=midPt;
    std::cout<<midPoint<<std::endl<<std::endl<<std::endl;


    this->coordinates[0].setCoords(midPt[0]-lenX/2, midPt[1]-lenY/2, midPt[2]-lenZ/2);
    this->coordinates[1].setCoords(midPt[0]+lenX/2, midPt[1]-lenY/2, midPt[2]-lenZ/2);
    
    this->coordinates[2].setCoords(midPt[0]-lenX/2, midPt[1]+lenY/2, midPt[2]-lenZ/2);
    this->coordinates[3].setCoords(midPt[0]+lenX/2, midPt[1]+lenY/2, midPt[2]-lenZ/2);


    this->coordinates[6].setCoords(midPt[0]-lenX/2, midPt[1]-lenY/2, midPt[2]+lenZ/2);
    this->coordinates[7].setCoords(midPt[0]+lenX/2, midPt[1]-lenY/2, midPt[2]+lenZ/2);

    this->coordinates[4].setCoords(midPt[0]-lenX/2, midPt[1]+lenY/2, midPt[2]+lenZ/2);
    this->coordinates[5].setCoords(midPt[0]+lenX/2, midPt[1]+lenY/2, midPt[2]+lenZ/2);
    // this->coordinates[1].setCoord(startX, startY-lenY);
    // this->coordinates[2].setCoord(startX+lenX, startY-lenY);
    // this->coordinates[3].setCoord(startX+lenX, startY);

}


std::ostream& operator << (std::ostream& ostrm, Cuboid rect)
{

    for (int i  = 0; i<8; ++i){
        ostrm << rect.getCorner(i)<<"\n";
        if(i%2==1)
            ostrm<<"\n";
}
    // ostrm<<rect.getCorner(0)<<"\n";
    // ostrm<<rect.getCorner(1)<<"\n";
    return ostrm;
}



void Cuboid :: rotateXaxis(double angle)
{   
    double radians = angle*(M_PI/180.0);
    Matrix2x2<double, 3> m;
    m.getXrotationMatrix(radians);
    for(int i=0; i<8; ++i)
    {
        this->coordinates[i] = m*this->coordinates[i];
    }

}

void Cuboid :: rotateYaxis(double angle)
{   
    double radians = angle*(M_PI/180.0);
    Matrix2x2<double, 3> m;
    m.getYrotationMatrix(radians);
    for(int i=0; i<8; ++i)
    {
        this->coordinates[i] = m*this->coordinates[i];
    }

}

void Cuboid :: rotateZaxis(double angle)
{   
    double radians = angle*(M_PI/180.0);
    Matrix2x2<double, 3> m;
    m.getZrotationMatrix(radians);
    for(int i=0; i<8; ++i)
    {
        this->coordinates[i] = m*this->coordinates[i];
    }

}


void Cuboid :: moveCuboid(Vector2d<double, 3> vec)
{
    for(int i=0; i<8;++i)
    {
        this->setCorner(i, this->getCorner(i)+vec);
    }
}



Cuboid& operator += (Cuboid& rect, Vector2d<double, 3> vec)
{
    for(int i=0; i<8;++i)
    {
        rect.setCorner(i, rect.getCorner(i)+vec);
    }

    return rect;
}
