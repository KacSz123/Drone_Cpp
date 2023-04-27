#pragma once
#include "vector2d.hpp"
#include "matrix2x2.hpp"
#include "gnuplot_link.hpp"
class Cuboid
{

    private:
        Vector2d<double, 3> coordinates[8]; //leftUp, LeftDown, RightDown, LeftUp
        Vector2d<double, 3> midPoint;
    public:
        Cuboid();
        Cuboid(Vector2d<double, 3>, double, double, double);
        Vector2d<double, 3> const getCorner(int i) {return this->coordinates[i];};
        void rotateXaxis(double angle);
        void rotateYaxis(double angle);
        void rotateZaxis(double angle);
        void setCorner(int i, Vector2d<double, 3> vec){this->coordinates[i]=vec;};
        void moveCuboid(Vector2d<double, 3> vec);
        // void setCorner(int i, Vector2d<double,3> vec){this->coordinates[i]=vec;};
        

};


std::ostream& operator << (std::ostream&, Cuboid);
Cuboid& operator += (Cuboid& rect, Vector2d<double, 3> vec);