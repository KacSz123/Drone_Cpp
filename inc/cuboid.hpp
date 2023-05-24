#pragma once
#include "vector2d.hpp"
#include "matrix2x2.hpp"
#include "gnuplot_link.hpp"
#include "geometric_obj.hpp"
class Cuboid:GeometricObj
{

    private:
        // Vector2d<double, 3> coordinates[8];
        // Vector2d<double, 3> midPoint;
        // Matrix2x2<double, 3> orientation;
    public:
        Cuboid();
        Cuboid(vector3D, double, double, double);
        void rotateXaxis(double angle);
        void rotateYaxis(double angle);
        void rotateZaxis(double angle);
        void setCorner(int i, vector3D vec){this->GeometricObj::insertVertex(vec);};
        void moveCuboidForward(double );
        vector3D getCorner(int i){return this->GeometricObj::getCorner(i);}
        vector3D getMidPoint(){return this->GeometricObj::getMidPoint();}
        std::ostream& writingToFle(std::ostream&);
};
std::ostream& operator << (std::ostream&, Cuboid);
Cuboid& operator += (Cuboid& rect, Vector2d<double, 3> vec);