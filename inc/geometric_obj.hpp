#ifndef GEOMMETRIC_OBJ_HPP
#define GEOMMETRIC_OBJ_HPP

#include "matrix2x2.hpp"
#include <vector>
#include "vector2d.hpp"
#include "matrix2x2.hpp"
typedef std::vector<Vector2d<double, 3>> VertexVec;
class GeometricObj
{
private:
protected:
    VertexVec _vertexes;
    Vector2d<double, 3> _midPoint;
    Matrix3x3 _orientMatrix;

public:
    void insertVertex(vector3D v) { this->_vertexes.push_back(v); }
    void setVertex(int i, const vector3D &&vec) { this->_vertexes[i].setCoords(vec.getCoord(0),
                                                            vec.getCoord(1),vec.getCoord(2)); }
    void setVertexCoords(int i, vector3D &vec) { this->_vertexes[i] = vec; }
    void setVertexCoords(int i, double x, double y, double z) { this->_vertexes[i].setCoords(x, y, z); }
    void setMidPoint(double x, double y, double z) { this->_midPoint.setCoords(x, y, z); }
    void setMidPoint(vector3D v) { this->_midPoint = v; }
    void setOrientation(Matrix3x3 m) { this->_orientMatrix = m; }
    void move(vector3D vec);
    void moveForward(double x);
    void soarForward(double x,double y);
    void rotate(double angle, char axis, bool aroundOwnAxis =true, vector3D extraVec = vector3D(0,0,0));
    void rotateWithStaticOrient(double angle, char axis);

    vector3D getMidPoint()const  { return this->_midPoint; }
    vector3D getCorner(int i)const { return this->_vertexes[i]; };
    vector3D getVertex(int i)const { return this->_vertexes[i]; }
    Matrix3x3 getOrientation()const { return this->_orientMatrix; }
    GeometricObj();
    GeometricObj(int a);
    virtual ~GeometricObj(){};

    
    virtual bool writeToFile(const std::string& ) = 0;
};


#endif //GEOMMETRIC_OBJ_HPP