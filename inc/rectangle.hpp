#pragma once
#include "vector2d.hpp"
#include "matrix2x2.hpp"
#include "gnuplot_link.hpp"
class Rectangle
{

    private:
        Vector2d<double, 2> coordinates[4]; //leftUp, LeftDown, RightDown, LeftUp
    public:
        Rectangle();
        Rectangle(double startX, double startY, double lenX, double lenY);
        Vector2d<double, 2> const getCorner(int i) {return this->coordinates[i];};
        void rotateRectangle(double angle);
        void setCorner(int i, Vector2d<double, 2> vec){this->coordinates[i]=vec;};
        void moveRectangle(Vector2d<double, 2> vec);
        void setCorner(int i, double x, double y){this->coordinates[i].setCoord(x,y);};
        void rotateRectangleAnimation(double angle, PzG::GnuplotLink link);

};


std::ostream& operator << (std::ostream&, Rectangle);
Rectangle& operator += (Rectangle& rect, Vector2d<double, 2> vec);