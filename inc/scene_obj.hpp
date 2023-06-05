#ifndef SCENE_OBJ_HPP
#define SCENE_OBJ_HPP


#include<vector>
#include<cmath>

#include"vector2d.hpp"



class SceneObj
{
private:
protected:
    static uint _allSceneObjectCounter;
    static uint _existingSceneObjectCounter;

    double _circleRadius;
    double _heightRange;

public:

    SceneObj();
    ~SceneObj();
    
    double getCircleRadius()const {return _circleRadius;}
    double getHeight()const {return _heightRange;}  
      static void printCounters()
    {
        std::cout << "No. of all created SceneObj<>: " << _allSceneObjectCounter
         << ";\n No. of existing SceneObj<>: " << _existingSceneObjectCounter << std::endl;
    }
    // virtual  double getXYDistance(const SceneObj & anotherObj)const = 0;
    // virtual  double getZDistance(const SceneObj & anotherObj)const = 0;
    // bool ifDetectedCollision(const SceneObj & anotherObj) const;
};



#endif //SCENE_OBJ_HPP