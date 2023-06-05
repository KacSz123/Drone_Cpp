#include "cuboid_obstacle.hpp"



CuboidObstacle::CuboidObstacle():_ID{++_cuboidObstCntr}
{
    _obstacle = Cuboid(vector3D(0,0,0), Xdefault, Ydefault, Zdefault);
    _filename="cuboid_obst_"+std::to_string(_ID)+".dat";
}
CuboidObstacle::CuboidObstacle(vector3D&v,double x, double y,double z):_ID{++_cuboidObstCntr}
{
    _obstacle=Cuboid(v,x,y,z);
_filename =  std::string(DATA_DIR) + "cub_obst_" + std::to_string(_cuboidObstCntr);
}
CuboidObstacle::~CuboidObstacle()
{
}