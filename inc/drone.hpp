#ifndef DRONE_HPP
#define DRONE_HPP

#include <iostream>
#include <vector>
#include <string>
#include "hexagonal_prism.hpp"
#include "cuboid.hpp"
#include "scene_obj.hpp"

#define DATA_DIR "./data/"

typedef std::vector<HexagonalPrism> rotorsVec;
typedef std::vector<std::string> fileVec;

class Drone: public SceneObj
{
    private:
        constexpr static double _basicBodyW=60;
        constexpr static double _basicBodyL=60;
        constexpr static double _basicBodyH=30;
        constexpr static double _basicRotorR=25;
        constexpr static double _basicRotorH=20;
        // double _scale;
        static unsigned int _droneNo;
        const unsigned int _ID;
        Cuboid _body;
        rotorsVec _rotors;
        vector3D _midPoint;
        fileVec fileNames;

    public:
        Drone();
        Drone(const Drone &v);
        Drone(vector3D midPoint, double scale=1.0);
        ~Drone(){};
        vector3D getMidPoint() const{ return (_midPoint); }
        const std::string operator[](unsigned i) { return fileNames[i]; }
        const std::string operator[](unsigned i)const { return fileNames[i]; }
        Cuboid getBody()const { return _body; }
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
        double getXYDistance(const SceneObj*) const;
        double getZDistance(const SceneObj*) const;
        void printBody(){_body.printVertexes();};
        void writeToFiles();
        HexagonalPrism getRotor(int i)const {return _rotors[i];}
        uint getID()const{return _ID;}
};

#endif //DRONE_HPP