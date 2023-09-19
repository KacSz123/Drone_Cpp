#ifndef CUBOID_HPP
#define CUBOID_HPP

#include "vector2d.hpp"
#include "matrix2x2.hpp"
#include "geometric_obj.hpp"
#include <list>
// #include "scene_obj.hpp"
class Cuboid : public GeometricObj //,public SceneObj
{

private:
    std::list<vector3D> _flyPath;
public:
    Cuboid() : GeometricObj(8){};
    Cuboid(const vector3D &, const double, const double, const double);

    void printVertexes()
    {
        for (VertexVec::iterator i = _vertexes.begin(); i != _vertexes.end(); ++i)
            std::cout << *i << std::endl;
        std::cout << std::endl;
    };
    ~Cuboid(){ this->_vertexes.clear(); this->_vertexes.shrink_to_fit();};
    friend std::ostream &operator<<(std::ostream &, Cuboid &);
    void WriteToStreamExample(ostream &output_stream) { output_stream << (*this) << "\n"; }
    bool writeToFile(const std::string &fileName);
    // std::ostream& operator << (std::ostream&);
};

Cuboid &operator+=(Cuboid &rect, Vector2d<double, 3> vec);

#endif // CUBOID_HPP