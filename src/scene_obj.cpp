#include"scene_obj.hpp"

uint SceneObj::_allSceneObjectCounter=0;
uint SceneObj::_existingSceneObjectCounter=0;


SceneObj::SceneObj()
{
    std::cout<<"con so\n";
    ++_allSceneObjectCounter;
    ++_existingSceneObjectCounter;
}

SceneObj::~SceneObj()
{
    // _allSceneObjectCounter;
    std::cout<<"Dest so\n";
    --_existingSceneObjectCounter;
}


// bool SceneObj::ifDetectedCollision(const SceneObj & anotherObj)const
// {
//     const double xyDistance = anotherObj.getXYDistance(*this);
//     const double zDistance = anotherObj.getZDistance(*this);

//     return (xyDistance+zDistance<this->getCircleRadius());
// }






