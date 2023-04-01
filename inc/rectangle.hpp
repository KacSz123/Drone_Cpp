#pragma once
#include "vector2d.hpp"
#include "matrix2x2.hpp"
class Rectangle
{

    private:
        Vector2d coordinates[4]; //leftUp, LeftDown, RightDown, LeftUp
    public:
        Rectangle();
        Rectangle(double startX, double startY, double lenX, double lenY);
        Vector2d getCorner(int i) {return this->coordinates[i];};
        void rotateRectangle(double angle);
        void setCorner(int i, Vector2d vec){this->coordinates[i]=vec;};
        void moveRectangle(Vector2d vec);
        void setCorner(int i, double x, double y)
        {this->coordinates[i].setCoord(x,y);};


};


std::ostream& operator << (std::ostream&, Rectangle);
Rectangle& operator += (Rectangle& rect, Vector2d vec);