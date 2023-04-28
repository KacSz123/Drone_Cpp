
#include <iostream>
#include "cuboid.hpp"
#include <cmath>

Cuboid::Cuboid()
{
    for (int i = 0; i < 3; ++i)
        this->orientation(i, i) = 1;
    Vector2d<double, 3> vec;
    for (int i = 0; i < 8; ++i)
    {
        this->coordinates[i] = vec;
    }
}

Cuboid::Cuboid(Vector2d<double, 3> midPt, double lenX, double lenY, double lenZ)
{
    for (int i = 0; i < 3; ++i)
        this->orientation(i, i) = 1;

    this->midPoint = midPt;
    std::cout << midPoint << std::endl
              << std::endl
              << std::endl;
    std::cout << this->orientation << std::endl;

    this->coordinates[0].setCoords(midPt[0] + lenX / 2, midPt[1] - lenY / 2, midPt[2] + lenZ / 2);
    this->coordinates[1].setCoords(midPt[0] + lenX / 2, midPt[1] + lenY / 2, midPt[2] + lenZ / 2);

    this->coordinates[2].setCoords(midPt[0] + lenX / 2, midPt[1] - lenY / 2, midPt[2] - lenZ / 2);
    this->coordinates[3].setCoords(midPt[0] + lenX / 2, midPt[1] + lenY / 2, midPt[2] - lenZ / 2);

    this->coordinates[6].setCoords(midPt[0] - lenX / 2, midPt[1] - lenY / 2, midPt[2] + lenZ / 2);
    this->coordinates[7].setCoords(midPt[0] - lenX / 2, midPt[1] + lenY / 2, midPt[2] + lenZ / 2);

    this->coordinates[4].setCoords(midPt[0] - lenX / 2, midPt[1] - lenY / 2, midPt[2] - lenZ / 2);
    this->coordinates[5].setCoords(midPt[0] - lenX / 2, midPt[1] + lenY / 2, midPt[2] - lenZ / 2);

}

std::ostream &operator<<(std::ostream &strm, Cuboid rect)
{
            Vector2d<double, 3> mLeft, mRight, x=rect.getCorner(0),y=rect.getCorner(1), m=rect.getMidPoint();

            mLeft.setCoords(m[0], x[1], m[2] );
            mRight.setCoords(m[0], y[1], m[2]);

            for (int i = 0; i<8; ++i)
            {
                if(i%2==0)
                    strm<<mLeft<<"\n";
                strm<<rect.getCorner(i)<<"\n";
                if (i%2==1)
                    strm<<mRight<<"\n\n";
            }

            strm<<mLeft<<"\n"<<rect.getCorner(0)<<"\n"<<rect.getCorner(1)<<"\n"<<mRight<<"\n";
            return strm;
}

void Cuboid ::rotateXaxis(double angle)
{

    double radians = angle * (M_PI / 180.0);
    Matrix2x2<double, 3> m;
    m.getXrotationMatrix(radians);
    this->orientation = (this->orientation * m);
    for (int i = 0; i < 8; ++i)
    {
        this->coordinates[i] -=this->midPoint;    
        this->coordinates[i] = m * this->coordinates[i];
        this->coordinates[i] += this->midPoint;
    }
}

void Cuboid ::rotateYaxis(double angle)
{
    double radians = angle * (M_PI / 180.0);
    Matrix2x2<double, 3> m;
    m.getYrotationMatrix(radians);
    this->orientation = (this->orientation * m);

    for (int i = 0; i < 8; ++i)
    {
        this->coordinates[i] -=this->midPoint;    
        this->coordinates[i] = m * this->coordinates[i];
        this->coordinates[i] += this->midPoint;
    }
}

void Cuboid ::rotateZaxis(double angle)
{
    

    double radians = angle * (M_PI / 180.0);
    Matrix2x2<double, 3> m;
    m.getZrotationMatrix(radians);
    this->orientation = (this->orientation * m);
    

    for (int i = 0; i < 8; ++i)
    {   
        this->coordinates[i] -=this->midPoint;    
        this->coordinates[i] = m * this->coordinates[i];
        this->coordinates[i] += this->midPoint;
    }

}


void Cuboid ::moveCuboidForward(double dist)
{
    Vector2d<double, 3> v;
    v.setCoords(dist, 0,0);
    // this->midPoint += this->orientation *v;

    this->midPoint +=this->orientation * v;

    for (int i = 0; i < 8; ++i)
    {
        this->coordinates[i]+=(this->orientation * v);
    }
}
Cuboid &operator+=(Cuboid &rect, Vector2d<double, 3> vec)
{
    for (int i = 0; i < 8; ++i)
    {
        rect.setCorner(i, rect.getCorner(i) + vec);
    }

    return rect;
}


        std::ostream& Cuboid :: writingToFle(std::ostream& strm)
        {
            Vector2d<double, 3> mLeft, mRight;
            mLeft.setCoords(this->midPoint.getCoord(0), this->coordinates[0].getCoord(1), this->midPoint.getCoord(2) );
            mRight.setCoords(this->midPoint.getCoord(0), this->coordinates[1].getCoord(1), this->midPoint.getCoord(2) );


            for (int i = 0; i<8; ++i)
            {
                if(i%2==0)
                    strm<<mLeft<<"\n";
                strm<<this->coordinates[i]<<"\n";
                if (i%2==1)
                    strm<<mRight<<"\n\n";
            }
        return strm;
    // this->coordinates[0].setCoords(midPt[0] - lenX / 2, midPt[1] - lenY / 2, midPt[2] - lenZ / 2);
    // this->coordinates[1].setCoords(midPt[0] + lenX / 2, midPt[1] - lenY / 2, midPt[2] - lenZ / 2);

    // this->coordinates[2].setCoords(midPt[0] - lenX / 2, midPt[1] + lenY / 2, midPt[2] - lenZ / 2);
    // this->coordinates[3].setCoords(midPt[0] + lenX / 2, midPt[1] + lenY / 2, midPt[2] - lenZ / 2);

    // this->coordinates[6].setCoords(midPt[0] - lenX / 2, midPt[1] - lenY / 2, midPt[2] + lenZ / 2);
    // this->coordinates[7].setCoords(midPt[0] + lenX / 2, midPt[1] - lenY / 2, midPt[2] + lenZ / 2);

    // this->coordinates[4].setCoords(midPt[0] - lenX / 2, midPt[1] + lenY / 2, midPt[2] + lenZ / 2);
    // this->coordinates[5].setCoords(midPt[0] + lenX / 2, midPt[1] + lenY / 2, midPt[2] + lenZ / 2);
        }

