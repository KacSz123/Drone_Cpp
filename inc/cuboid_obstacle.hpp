#ifndef CUBOID_OBSTACLE_HPP
#define CUBOID_OBSTACLE_HPP
#include "scene_obj.hpp"
#include "cuboid.hpp"

#include<string>

#define DATA_DIR "./data/"
class CuboidObstacle//: public SceneObj
{
constexpr static double Xdefault = 30;
constexpr static double Ydefault = 50;
constexpr static double Zdefault = 100;

private:
   const uint _ID;
   Cuboid _obstacle;
   std::string  _filename;

public:
   static uint _cuboidObstCntr;
    CuboidObstacle();
    CuboidObstacle(vector3D&,double x, double y, double z);
    ~CuboidObstacle();
    void writeToFile(){_obstacle.writeToFile(_filename);}

};

uint CuboidObstacle::_cuboidObstCntr=0;










#endif //CUBOID_OBSTACLE_HPP