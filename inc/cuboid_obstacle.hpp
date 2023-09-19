#ifndef CUBOID_OBSTACLE_HPP
#define CUBOID_OBSTACLE_HPP
#include "scene_obj.hpp"
#include "cuboid.hpp"

#include<string>

#define DATA_DIR "./data/"
class CuboidObstacle: public SceneObj
{
constexpr static double Xdefault = 30;
constexpr static double Ydefault = 50;
constexpr static double Zdefault = 100;

private:
   const uint _ID;
   Cuboid _obstacle;
   std::string  _filename;
   double _x,_y,_z;
public:
   static uint _cuboidObstCntr;
   uint getID()const{return _ID;}
    CuboidObstacle();
    CuboidObstacle(vector3D&,double x=Xdefault, double y=Ydefault,double z=Zdefault);
    ~CuboidObstacle();
    void writeToFile(){_obstacle.writeToFile(_filename);};
    std::string getFileName()const {return _filename;};
    Cuboid getCuboid()const {return _obstacle;};
   CuboidObstacle(const CuboidObstacle &d):_ID{d.getID()}
   {
      _obstacle = d.getCuboid();
      _filename = d.getFileName();
      this->setPosition(d.getPosition());
      this->setHeight(d.getHeight());
      this->setCircleRadius(d.getCircleRadius());
   }
}; 











#endif //CUBOID_OBSTACLE_HPP