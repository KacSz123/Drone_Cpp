#ifndef SCENE_OBJ_HPP
#define SCENE_OBJ_HPP


#include<vector>
#include<cmath>

#include"vector2d.hpp"
#include<cmath>
#include<memory>

class 
SceneObj
{
private:
protected:
    static uint _allSceneObjectCounter;
    static uint _existingSceneObjectCounter;

    double _circleRadius;
    double _heightRange;
    vector3D _position;
public:

    SceneObj();
    SceneObj(const SceneObj& o)
    {
        // ++_allSceneObjectCounter;
        // ++_existingSceneObjectCounter;
        _circleRadius = o.getCircleRadius();
        _heightRange = o.getHeight();
        _position = o.getPosition();
    }
    ~SceneObj();
    double getRadius()const{return _circleRadius;}
    double getHeight()const{return _heightRange;}
    vector3D getPosition()const{return _position;}
    double getCircleRadius()const {return _circleRadius;}
    void setRadius(const double &a){_circleRadius=a;}
    void setHeight(const double &a){_heightRange=a;}
    void setPosition(const vector3D&v) { _position=v;}
    void setCircleRadius(const double &a) { _circleRadius=a;}
    // double getHeight()const {return _heightRange;}  
      static void printCounters()
    {
        std::cout << "No. of all created SceneObj<>: " << _allSceneObjectCounter
         << ";\n No. of existing SceneObj<>: " << _existingSceneObjectCounter << std::endl;
    }
     bool ifDetectedCollision( std::shared_ptr<SceneObj> anotherObj)const
     {
        std::cout<<"**************************************************\n";
        std::cout<<"moj srodek:  "<<this->getPosition()<<std::endl;
        std::cout<<"jegosrodek:  "<<anotherObj->getPosition()<<std::endl;
        std::cout<<"**************************************************\n";
        auto xr = pow(abs(getPosition()[0]-anotherObj->getPosition()[0]),2.0);
        auto yr = pow(abs(getPosition()[1]-anotherObj->getPosition()[1]),2.0);

        auto xyReal = sqrt(xr+yr);

        auto zReal= abs(getPosition()[2]-anotherObj->getPosition()[2]);

        auto xyMax = _circleRadius+anotherObj->getCircleRadius();
        auto zMax = _heightRange + anotherObj->getHeight();
        std::cout<<"xyMin:"<<xyMax<<"; xyReal:"<<xyReal<<"\n";
        std::cout<<"zMin:"<<zMax<<"; zReal:"<<zReal<<"\n";
    //    getchar(); 
        if(xyReal<xyMax&& zReal<zMax)
            return true;
        else
            return false;
     }
};



#endif //SCENE_OBJ_HPP