#include "cuboid_obstacle.hpp"

uint CuboidObstacle::_cuboidObstCntr = 0;

CuboidObstacle::CuboidObstacle() : _ID{++_cuboidObstCntr}, _x{Xdefault}, _y{Ydefault}, _z{Zdefault}
{

    _obstacle = Cuboid(vector3D(0, 0, 0), Xdefault, Ydefault, Zdefault);
    _filename = "cuboid_obst_" + std::to_string(_ID) + ".dat";
    setPosition(_obstacle.getMidPoint());
    // _x=Xdefault;
    // _y=Ydefault;
    // _z=Zdefault;
    _heightRange = _z / 2.0;
    _circleRadius = sqrt(pow(_x, 2) + pow(_y, 2)) / 2.0;
}
CuboidObstacle::CuboidObstacle(vector3D &v, double x, double y, double z) : _ID{++_cuboidObstCntr}, _x{Xdefault}, _y{Ydefault}, _z{Zdefault}
{
    _obstacle = Cuboid(v, x, y, z, y / 2);
    _filename = std::string(DATA_DIR) + "cub_obst_" + std::to_string(_cuboidObstCntr) + ".dat";
    setPosition(_obstacle.getMidPoint());
    // _x=x;
    // _y=y;
    // _z=z;
    setHeight(_z / 2.0);
    setCircleRadius(sqrt(pow(_x / 2.0, 2) + pow(_y / 2.0, 2)));
    // set
}
CuboidObstacle::CuboidObstacle(const vector3D &v, double x, double y, double z) : _ID{++_cuboidObstCntr}, _x{Xdefault}, _y{Ydefault}, _z{Zdefault}
{
    _obstacle = Cuboid(v, x, y, z, y / 2);
    _filename = std::string(DATA_DIR) + "cub_obst_" + std::to_string(_cuboidObstCntr) + ".dat";
    setPosition(_obstacle.getMidPoint());
    // _x=x;
    // _y=y;
    // _z=z;
    setHeight(_z / 2.0);
    setCircleRadius(sqrt(pow(_x / 2.0, 2) + pow(_y / 2.0, 2)));
    // set
}

CuboidObstacle::~CuboidObstacle()
{
}