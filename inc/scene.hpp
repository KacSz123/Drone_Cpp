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
#include "cuboid_obstacle.hpp"
// #include "scene_obj.hpp"
#include "lacze_do_gnuplota.hpp"
#include <string>
#include <list>
#include <memory>
#include <unistd.h>

using sh_ptr_scene_obj = std::shared_ptr<SceneObj>;
using sh_ptr_obst= std::shared_ptr<CuboidObstacle>;
/*!
 * @brief New type: list of of shared_ptr to ScecneObj instances
 *
 */
using SceneObjectsList = std::list<sh_ptr_scene_obj>;

using sh_ptr_Drone = std::shared_ptr<Drone>;
/*!
 * @brief New type: list of of shared_ptr to Drone instances
 *
 */
using DronesList = std::list<sh_ptr_Drone>;
using handFileInfo = PzG::InfoPlikuDoRysowania *;
using fileHandlerList = std::vector<std::vector<handFileInfo>>;
class Scene
{
private:
    constexpr static float Xupper = 400.0;
    constexpr static float Xlow = -400.0;
    constexpr static float Yupper = 400.0;
    constexpr static float Ylow = -400.0;
    constexpr static float Zupper = 400.0;
    constexpr static float Zlow = -400.0;
    
    SceneObjectsList _sceneObjList;
    DronesList _dronesList;
    
    sh_ptr_Drone _activeDrone;
    sh_ptr_obst _activeObstacle;

    fileHandlerList _dronesFilesList;
    fileHandlerList _obstacleFilesList;
    
    handFileInfo  _pathHandler;
    PzG::LaczeDoGNUPlota _link;
    

public:
    Scene(/* args */);
    ~Scene();
    void addDrone(vector3D midPt, double scale)
    {
        auto drone = std::make_shared<Drone>(Drone(midPt, scale));
        _sceneObjList.push_back(drone);
        _dronesList.push_back(drone);
        this->addDronesFileToGPLink(drone);
        drone.reset();
    }
    void addDrone(sh_ptr_Drone drone)
    {
        _sceneObjList.push_back(drone);
        _dronesList.push_back(drone);
        drone->writeToFiles();

        this->addDronesFileToGPLink(drone);
        this->drawScene();
    }
    void activateDrone(uint i)
    {
        try
        {
            _activeDrone = *(std::next(_dronesList.begin(), i));
        for(long unsigned int it=0; it<_dronesFilesList.size(); ++it)
            {
                auto itt = _dronesFilesList[it];
                if(it==i)
                {
                    for(std::vector<handFileInfo>::iterator it2=itt.begin(); it2!=itt.end(); ++it2)
                        (*it2)->ZmienSzerokosc(2);
                }
                else
                {
                    for(std::vector<handFileInfo>::iterator it2=itt.begin(); it2!=itt.end(); ++it2)
                        (*it2)->ZmienSzerokosc(1);
                }
            }
        }
        catch (std::bad_alloc *a)
        {
            std::cout << "Wron index of Drone list!\n";
            if (_dronesList.size() == 0)
                std::cout << "List of Drones is empty!\n";
            // break;
        }
    }
    void moveActiveDroneForward(double pathLen, double speed = 1)
    {
        for (double i = 0; i < pathLen; i += speed)
        {
            _activeDrone->moveDrone(speed);
            _activeDrone->writeToFiles();
            usleep(1500);
            drawScene();
            if (checkForCollision(_activeDrone))
            {
                break;
            }
        }
    }


    void rotateActiveDrone(double angle, double speed = 1, double rotSpeed=1)
    {
        // auto tmpD = std::make_shared<Drone>(acti)
        for (double i = 0; i < abs(angle); i += speed)
        {
            auto a= angle>0?1:-1;
            _activeDrone->rotateDrone(a, speed,rotSpeed);
            _activeDrone->writeToFiles();
            usleep(1500);
            drawScene();
            if (checkForCollision(_activeDrone))
            {
                std::cout<<"WARNING! Close to collision!\n";
            }
        }
    }
    void soarActiveDrone(double pathLen, double angle, double speed=1)
        {

        for (double i = 0; i < abs(pathLen); i += speed)
        {
            // auto a= angle>0?1:-1;
            _activeDrone->soarDrone(speed, angle);
            _activeDrone->writeToFiles();
            usleep(1500);
            drawScene();
            if (checkForCollision(_activeDrone))
            {
                std::cout<<"WARNING! Close to collision!\n";
            }
        }
    }

    bool checkForCollision(sh_ptr_Drone obj)
    {

        for (SceneObjectsList::iterator i = _sceneObjList.begin(); i != _sceneObjList.end(); ++i)
        {
            if (*i != obj && obj->ifDetectedCollision((*i)))
            {
                std::cout << "Collision!\n";
                return true;
            }
        }
        std::cout << "NO Collision!\n";
        return false;
    }
    void configureGnuplotLink()
    {
        _link.ZmienTrybRys(PzG::TR_3D);
        _link.UstawZakresX(Xlow, Xupper);
        _link.UstawZakresY(Ylow, Yupper);
        _link.UstawZakresZ(Zlow, Zupper);
        _link.UstawRotacjeXZ(40, 40);
        
    }
    void addDronesFileToGPLink(sh_ptr_Drone drone)
    {
        std::vector<handFileInfo> tmp;
        static int kolor = 1;
        if (kolor > 10)
            kolor = 1;
        PzG::InfoPlikuDoRysowania *fileInfo = &_link.DodajNazwePliku((*drone)[0].c_str());
        fileInfo->ZmienKolor(kolor);
        tmp.push_back(fileInfo);
        for (int i = 1; i < 5; ++i)
        {
            PzG::InfoPlikuDoRysowania *fileInfo = &_link.DodajNazwePliku((*drone)[i].c_str());
            tmp.push_back(fileInfo);
            fileInfo->ZmienKolor(kolor);
        }
        _dronesFilesList.push_back(tmp);
        ++kolor;
    }
    void addObstacle(sh_ptr_obst obs)
    {
        _sceneObjList.push_back(obs);
        obs->writeToFile();
        this->addObstacleToGPlink(obs);
        this->drawScene();
    }
    void addObstacleToGPlink(sh_ptr_obst cObst)
    {
        constexpr static int kolor_ = 16;
        PzG::InfoPlikuDoRysowania *fileInfo = &_link.DodajNazwePliku(cObst->getFileName().c_str());
        fileInfo->ZmienKolor(kolor_);
        fileInfo->ZmienSzerokosc(2);
    }

    void checkColision(int droneIndex)
    {
        try
        {
            DronesList::iterator it = std::next(_dronesList.begin(), droneIndex);
            checkForCollision((*it));
        }
        catch (std::bad_alloc *a)
        {
            std::cout << "Wron index of Drone list!\n";
            if (_dronesList.size() == 0)
                std::cout << "List of Drones is empty!\n";
        }
        catch (...)
        {
            std::cout << "sth went wrong, but idk;\n";
        }
    }
    void drawScene() { _link.Rysuj(); }
};

#endif