#pragma once

#include<iostream>
#include<vector>
#include<string>
#include "hexagonal_prism.hpp"
#include "cuboid.hpp"

typedef std::vector<HexagonalPrism> rotorsVec;
typedef std::vector<std::string> fileVec;
class Drone
{
    private:
    static unsigned int _droneNo;
    Cuboid *_body;
    rotorsVec _rotors;
    vector3D *_midPoint;
    fileVec fileNames;
    public:
    Drone(){};
    Drone(vector3D midPoint);
    ~Drone(){};
    vector3D getMidPoint(){return *(this->_midPoint);}
    
};
