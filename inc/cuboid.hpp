#pragma once
#include "vector2d.hpp"
#include "matrix2x2.hpp"
#include "gnuplot_link.hpp"
class Cuboid
{

    private:
        Vector2d<double, 3> coordinates[8]; //leftUp, LeftDown, RightDown, LeftUp
        Vector2d<double, 3> midPoint;
        Matrix2x2<double, 3> orientation;
        // Vector2d<double, 3> startCoord[8];
    public:
        Cuboid();
        Cuboid(Vector2d<double, 3>, double, double, double);
        Vector2d<double, 3> const getCorner(int i) {return this->coordinates[i];};
        void rotateXaxis(double angle);
        void rotateYaxis(double angle);
        void rotateZaxis(double angle);
        void setCorner(int i, Vector2d<double, 3> vec){this->coordinates[i]=vec;};
        void moveCuboidForward(double );
        void goToZeroPt(Vector2d<double, 3> );
        Vector2d<double, 3> getMidPoint(){return this->midPoint;}
        // void goToMyPose();
        // void setCorner(int i, Vector2d<double,3> vec){this->coordinates[i]=vec;};
        

};


std::ostream& operator << (std::ostream&, Cuboid);
Cuboid& operator += (Cuboid& rect, Vector2d<double, 3> vec);