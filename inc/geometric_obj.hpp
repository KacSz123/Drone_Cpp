#pragma once

#include "matrix2x2.hpp"
#include<vector>
#include "vector2d.hpp"
#include "matrix2x2.hpp"
typedef std::vector<Vector2d<double,3>> VertexVec;
class GeometricObj
{
    private:
        VertexVec _vertexes;
        Vector2d<double,3> _midPoint;
        Matrix3x3 _orientMatrix;

    public:
        void insertVertex(vector3D  v){this->_vertexes.push_back(v);}
        void setVertex(int i, vector3D vec){this->_vertexes[i]=vec;}
        void setVertexCoords(int i, vector3D vec){this->_vertexes[i] = vec;}
        void setVertexCoords(int i, double x, double y, double z){this->_vertexes[i].setCoords(x,y,z);}
        void setMidPoint(double x, double y, double z){this->_midPoint.setCoords(x,y,z);}
        void setMidPoint(vector3D v){this->_midPoint=v;}
        void setOrientation(Matrix3x3 m){this->_orientMatrix = m;}
        Matrix3x3 getOrientation(){return this->_orientMatrix;}
        vector3D getVertex(int i){return this->_vertexes[i];}
        void moveObject(vector3D vec);
        void moveObjectForward(double x);
        void rotateObject(double angle, char axis);

        vector3D const getCorner(int i) {return this->_vertexes[i];};
        vector3D getMidPoint(){return this->_midPoint;}
        GeometricObj();
        ~GeometricObj(){this->_vertexes.clear();    this->_vertexes.shrink_to_fit();}


};