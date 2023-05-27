#pragma once
#include "vector2d.hpp"
#include "matrix2x2.hpp"
#include "gnuplot_link.hpp"
#include "geometric_obj.hpp"
class Cuboid:public GeometricObj
{

    private:

    public:
        Cuboid():GeometricObj(8){};
        Cuboid(vector3D, double, double, double);
    Cuboid& operator = (const Cuboid &C){/*this->setMidPoint(C.getMidPoint());*/ return *this;}
};
std::ostream& operator << (std::ostream&, Cuboid);
Cuboid& operator += (Cuboid& rect, Vector2d<double, 3> vec);