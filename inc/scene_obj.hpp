#ifndef SCENE_OBJ_HPP
#define SCENE_OBJ_HPP


#include<vector>
#include<cmath>

#include"vector2d.hpp"

class SceneObj
{
private:
    double _circleRadius;
    double _heightRange;

public:

    SceneObj(/* args */);
    ~SceneObj();
    
    double getCircleRadius()const {return _circleRadius;}
    double getHeight()const {return _heightRange;}
    virtual  double getXYDistance(const SceneObj & anotherObj)const = 0;
    virtual  double getZDistance(const SceneObj & anotherObj)const = 0;
    bool ifDetectedCollision(const SceneObj & anotherObj) const;
};



SceneObj::SceneObj(/* args */)
{
}

SceneObj::~SceneObj()
{
}


bool SceneObj::ifDetectedCollision(const SceneObj & anotherObj)const
{
    const double xyDistance = anotherObj.getXYDistance(*this);
    const double zDistance = anotherObj.getZDistance(*this);

    return (xyDistance<this->getCircleRadius());
}








#endif //SCENE_OBJ_HPP