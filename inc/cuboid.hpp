#ifndef CUBOID_HPP
#define CUBOID_HPP

#include "vector2d.hpp"
#include "matrix2x2.hpp"
#include "gnuplot_link.hpp"
#include "geometric_obj.hpp"
// #include "scene_obj.hpp"
class Cuboid:public GeometricObj//,public SceneObj
{

    private:

    public:
        Cuboid():GeometricObj(8){};
        Cuboid(vector3D, double, double, double);

};
std::ostream& operator << (std::ostream&, Cuboid);
Cuboid& operator += (Cuboid& rect, Vector2d<double, 3> vec);





#endif // CUBOID_HPP