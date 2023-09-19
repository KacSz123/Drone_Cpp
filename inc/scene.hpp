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
/*!
 * @brief New type: list of of shared_ptr to ScecneObj instances
 *
 */
using SceneObjectsList = std::list<std::shared_ptr<SceneObj>>;

using sh_ptr_Drone = std::shared_ptr<Drone>;
/*!
 * @brief New type: list of of shared_ptr to Drone instances
 *
 */
using DronesList = std::list<sh_ptr_Drone>;
using handFileInfo = PzG::InfoPlikuDoRysowania *;
using fileHandlerList = std::vector<handFileInfo>;
class Scene
{
private:
    SceneObjectsList _sceneObjList;
    DronesList _dronesList;
    fileHandlerList _filesControl;
    sh_ptr_Drone activeDrone;
    PzG::LaczeDoGNUPlota _link;
    constexpr static float Xupper = 400.0;
    constexpr static float Xlow = -400.0;
    constexpr static float Yupper = 400.0;
    constexpr static float Ylow = -400.0;
    constexpr static float Zupper = 400.0;
    constexpr static float Zlow = -400.0;

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
    void addDrone(std::shared_ptr<Drone> drone)
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
            activeDrone = *(std::next(_dronesList.begin(), i));
        }
        catch (std::bad_alloc *a)
        {
            std::cout << "Wron index of Drone list!\n";
            if (_dronesList.size() == 0)
                std::cout << "List of Drones is empty!\n";
        }
    }
    void moveActiveDroneForward(double pathLen, double speed = 1)
    {
        for (double i = 0; i < pathLen; i += speed)
        {
            activeDrone->moveDrone(speed);
            activeDrone->writeToFiles();
            usleep(1500);
            drawScene();
            if (checkForCollision(activeDrone))
            {
                break;
            }
        }
    }


    void rotateActiveDrone(double angle, double speed = 1, double rotSpeed=1)
    {
        for (double i = 0; i < abs(angle); i += speed)
        {
            auto a= angle>0?1:-1;
            activeDrone->rotateDrone(a, speed,rotSpeed);
            activeDrone->writeToFiles();
            usleep(1500);
            drawScene();
            if (checkForCollision(activeDrone))
            {
                // break;
                std::cout<<"WARNING! Close to collision!\n";
            }
        }
    }
    void soarDrone(double pathLen, double angle);

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
        static int kolor = 1;
        if (kolor > 10)
            kolor = 1;
        PzG::InfoPlikuDoRysowania *fileInfo = &_link.DodajNazwePliku((*drone)[0].c_str());
        fileInfo->ZmienKolor(kolor);
        for (int i = 1; i < 5; ++i)
        {
            PzG::InfoPlikuDoRysowania *fileInfo = &_link.DodajNazwePliku((*drone)[i].c_str());
            _filesControl.push_back(fileInfo);
            fileInfo->ZmienKolor(kolor);
        }

        ++kolor;
    }
    void addObstacle(std::shared_ptr<CuboidObstacle> obs)
    {
        _sceneObjList.push_back(obs);
        obs->writeToFile();
        this->addObstacleToGPlink(obs);
        this->drawScene();
    }
    void addObstacleToGPlink(std::shared_ptr<CuboidObstacle> cObst)
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