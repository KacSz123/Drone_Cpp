#pragma once

#include<iostream>
#include<vector>
#include<string>
#include "hexagonal_prism.hpp"
#include "cuboid.hpp"
#define DATA_DIR "./data/"
typedef std::vector<HexagonalPrism> rotorsVec;
typedef std::vector<std::string> fileVec;

class Drone
{
    private:
    static unsigned int _droneNo;
    const unsigned int _ID;
    Cuboid *_body;
    rotorsVec _rotors;
    vector3D *_midPoint;
    fileVec fileNames;
    public:
    Drone();
    Drone(vector3D midPoint);
    ~Drone(){};
    vector3D getMidPoint(){return *(this->_midPoint);}
    const std::string operator [](unsigned i){return fileNames[i];}
    Cuboid getBody(){return *_body;}
    HexagonalPrism getRotor(int i){return _rotors[i];}
    void generateNames();
    void printStdNames();
    void moveDrone(double x);
};
