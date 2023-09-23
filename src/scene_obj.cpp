#include "scene_obj.hpp"

uint SceneObj::_allSceneObjectCounter = 0;
uint SceneObj::_existingSceneObjectCounter = 0;

SceneObj::SceneObj()
{
    // std::cout << "con so\n";
    ++_allSceneObjectCounter;
    ++_existingSceneObjectCounter;
}

// SceneObj::~SceneObj()
// {
//     // _allSceneObjectCounter;
//     // std::cout << "Dest so\n";
//     --_existingSceneObjectCounter;
// }
bool SceneObj::ifDetectedCollision(std::shared_ptr<SceneObj> anotherObj) const
{

    auto xr = pow(abs(getPosition()[0] - anotherObj->getPosition()[0]), 2.0);
    auto yr = pow(abs(getPosition()[1] - anotherObj->getPosition()[1]), 2.0);

    auto xyReal = sqrt(xr + yr);

    auto zReal = abs(getPosition()[2] - anotherObj->getPosition()[2]);

    auto xyMax = _circleRadius + anotherObj->getCircleRadius();
    auto zMax = _heightRange + anotherObj->getHeight();
 
    if (xyReal < xyMax && zReal < zMax)
        return true;
    else
        return false;
}
