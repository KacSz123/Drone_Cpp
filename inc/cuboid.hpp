#pragma once
#include "vector2d.hpp"
#include "matrix2x2.hpp"
#include "gnuplot_link.hpp"
class Cuboid
{

    private:
        Vector2d<double, 2> coordinates[4]; //leftUp, LeftDown, RightDown, LeftUp
    public:
        Cuboid();
        Cuboid(double startX, double startY, double lenX, double lenY);
        Vector2d<double, 2> const getCorner(int i) {return this->coordinates[i];};
        void rotateCuboid(double angle);
        void setCorner(int i, Vector2d<double, 2> vec){this->coordinates[i]=vec;};
        void moveCuboid(Vector2d<double, 2> vec);
        void setCorner(int i, double x, double y){this->coordinates[i].setCoord(x,y);};
        void rotateCuboidAnimation(double angle, PzG::GnuplotLink link);

};


std::ostream& operator << (std::ostream&, Cuboid);
Cuboid& operator += (Cuboid& rect, Vector2d<double, 2> vec);