
#include <iostream>
#include <cmath>
#include "cuboid.hpp"
#include "geometric_obj.hpp"

Cuboid::Cuboid()
{
    vector3D vec;

       std::cout<<"dup1\n";
    for (int i = 0; i < 8; ++i)
    {
       std::cout<<"dup1\n";
        this->insertVertex(vec);
    }
}

Cuboid::Cuboid(vector3D midPt, double lenX, double lenY, double lenZ)
{

    std::cout<<"\n\n";
    std::cout<<"siema2\n";
    this->setMidPoint(midPt);
    std::cout<<"siema2\n";
    std::cout << this->getMidPoint() << std::endl
              << std::endl
              << std::endl;
    std::cout<<"siema2\n";
    std::cout << this->getOrientation() << std::endl;
    std::cout<<"siema2\n";
    vector3D vec;
    for (int i = 0; i < 8; ++i)
    {
       std::cout<<"dup1\n";
        this->insertVertex(vec);
    }
    this->setVertexCoords(0,midPt[0] + lenX / 2, midPt[1] - lenY / 2, midPt[2] + lenZ / 2);
    this->setVertexCoords(1,midPt[0] + lenX / 2, midPt[1] + lenY / 2, midPt[2] + lenZ / 2);
    this->setVertexCoords(2,midPt[0] + lenX / 2, midPt[1] - lenY / 2, midPt[2] - lenZ / 2);
    this->setVertexCoords(3,midPt[0] + lenX / 2, midPt[1] + lenY / 2, midPt[2] - lenZ / 2);
    this->setVertexCoords(6,midPt[0] - lenX / 2, midPt[1] - lenY / 2, midPt[2] + lenZ / 2);
    this->setVertexCoords(7,midPt[0] - lenX / 2, midPt[1] + lenY / 2, midPt[2] + lenZ / 2);
    this->setVertexCoords(4,midPt[0] - lenX / 2, midPt[1] - lenY / 2, midPt[2] - lenZ / 2);
    this->setVertexCoords(5,midPt[0] - lenX / 2, midPt[1] + lenY / 2, midPt[2] - lenZ / 2);

}

std::ostream &operator<<(std::ostream &strm, Cuboid rect)
{
            vector3D mLeft, mRight, x=rect.getCorner(0),y=rect.getCorner(1), m=rect.getMidPoint();

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
    this->rotateObject(angle, 'X');
}

void Cuboid ::rotateYaxis(double angle)
{
    this->rotateObject(angle, 'Y');
}

void Cuboid ::rotateZaxis(double angle)
{
    this->rotateObject(angle, 'Z');
}


void Cuboid ::moveCuboidForward(double dist)
{
    this->moveObjectForward(dist);
}
Cuboid &operator+=(Cuboid &rect, vector3D vec)
{
    for (int i = 0; i < 8; ++i)
    {
        rect.setCorner(i, rect.getCorner(i) + vec);
    }

    return rect;
}


        std::ostream& Cuboid :: writingToFle(std::ostream& strm)
        {
            vector3D mLeft, mRight;
            mLeft.setCoords(this->getMidPoint().getCoord(0), this->getCorner(0).getCoord(1), this->getMidPoint().getCoord(2) );
            mRight.setCoords(this->getMidPoint().getCoord(0), this->getCorner(1).getCoord(1), this->getMidPoint().getCoord(2) );


            for (int i = 0; i<8; ++i)
            {
                if(i%2==0)
                    strm<<mLeft<<"\n";
                strm<<this->getCorner(i)<<"\n";
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

