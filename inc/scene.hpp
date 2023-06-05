#ifndef SCENE_HPP
#define SCENE_HPP
/*!
 * @file scene.hpp
 * @author {Kacper Szczepanowski} ({kacperszcz159@gmail.com})
 * @brief File modeling class Scene which contains all objects both: drones and obstacles.
 * 
 * @version 0.1
 * @date 2023-09-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
// #include "file_operation.hpp"
#include "drone.hpp"
#include "scene_obj.hpp"
#include "lacze_do_gnuplota.hpp"
#include <string>
#include <list>
#include <memory>

/*!
 * @brief New type: list of of shared_ptr to ScecneObj instances
 * 
 */
using SceneObjectsList = std::list<std::shared_ptr<SceneObj>>;

/*!
 * @brief New type: list of of shared_ptr to Drone instances
 * 
 */
using DronesList = std::list<std::shared_ptr<Drone>>;
class Scene
{
private:
    SceneObjectsList _sceneObjList;
    DronesList _dronesList;
    // link
    PzG::LaczeDoGNUPlota _link;
    constexpr static float Xupper = 400.0;
    constexpr static float Xlow   =-400.0;
    constexpr static float Yupper = 400.0;
    constexpr static float Ylow   =-400.0;
    constexpr static float Zupper = 400.0;
    constexpr static float Zlow   =-400.0;
public:
    Scene(/* args */);
    ~Scene();
    void addDrone(vector3D midPt, double scale)
    {
        auto drone = std::make_shared<Drone>(Drone(midPt,scale));
        _sceneObjList.push_back(drone);
        _dronesList.push_back(drone);
        this->addDronesFileToGPLink(drone);
        drone.reset();
    }
    void addDrone(std::shared_ptr<Drone> drone)
    {

       std::cout<<"debug10\n";
        _sceneObjList.push_back(drone);

       std::cout<<"debug11\n";
        _dronesList.push_back(drone);
        drone->writeToFiles();
       std::cout<<"debug12\n";
        this->addDronesFileToGPLink(drone);

       std::cout<<"debug13\n";
        this->drawScene();
    }

    // void addObstacle(vector3D midPt, double x, double y, double z)
    // {}
    // void addObstacle(CuboidObsacle & cubO);
    void moveDroneForward(double pathLen);
    void soarDrone(double pathLen, double angle);

    void configureGnuplotLink()
    {
        _link.ZmienTrybRys(PzG::TR_3D);
        _link.UstawZakresX(Xlow,Xupper);
        _link.UstawZakresY(Ylow,Yupper);
        _link.UstawZakresZ(Zlow,Zupper);
        _link.UstawRotacjeXZ(40,60);

    }
    void addDronesFileToGPLink(std::shared_ptr<Drone> drone)
    {
        static int kolor=1;
        if(kolor>6)
            kolor=1;
        PzG::InfoPlikuDoRysowania *fileInfo = &_link.DodajNazwePliku((*drone)[0].c_str());
        fileInfo->ZmienKolor(kolor);
        for(int i=1; i<5; ++i)
        {
        PzG::InfoPlikuDoRysowania *fileInfo = &_link.DodajNazwePliku((*drone)[i].c_str());
        fileInfo->ZmienKolor(kolor);
        }

        ++kolor;
    }
    void drawScene(){_link.Rysuj();}
};





#endif