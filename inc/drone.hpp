#ifndef DRONE_HPP
#define DRONE_HPP

#include <iostream>
#include <vector>
#include <string>
#include "hexagonal_prism.hpp"
#include "cuboid.hpp"
#define DATA_DIR "./data/"

typedef std::vector<HexagonalPrism> rotorsVec;
typedef std::vector<std::string> fileVec;

class Drone //: public SceneObj
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
        Drone(vector3D midPoint, double scale=1.0);
        ~Drone(){};
        vector3D getMidPoint() { return *(this->_midPoint); }
        const std::string operator[](unsigned i) { return fileNames[i]; }
        Cuboid getBody() { return *_body; }
        HexagonalPrism getRotor(int i) { return _rotors[i]; }
        void generateNames();
        void printNamesOnStd();
        void moveDrone(const double x, double speed=1, double rotorsSpeed=1);
        // void moveDroneAnimation(const double x);
        void soarDrone(const double x, const double angle, double speed=1, double rotorsSpeed=1);
        // void soarDroneAnimation(const double x, const double angle);
        void rotateDrone(const double angle, double speed=1, double rotorsSpeed=1);
        void spinRotors(const double distance, double speed=1, bool direction=true);
        // void rotateDroneAnimation(const double angle);
};

#endif //DRONE_HPP