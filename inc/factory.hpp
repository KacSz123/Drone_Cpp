#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "scene_obj.hpp"
#include "drone.hpp"
#include "cuboid_obstacle.hpp"

enum ObjectType{OT_Drone, OT_Obstacle};

class FactorySingleton
{
private:
    static FactorySingleton _Factory;
    /* data */

public:
    // FactorySingleton(/* args */){};
    ~FactorySingleton(){std::cout<<"---- D--> Factory\n";};
    static std::shared_ptr<SceneObj> buildObject(ObjectType ObjType,const vector3D point)
    {
        return _Factory.createObject(ObjType, point);
    }
private:
std::shared_ptr<SceneObj> createObject(ObjectType ObjType,const vector3D point)const
{
    switch (ObjType)
    {
    case OT_Drone: return std::make_shared<Drone>(point);
    case OT_Obstacle: return std::make_shared<CuboidObstacle>(point);
    }
     return std::make_shared<CuboidObstacle>();
}
};





#endif