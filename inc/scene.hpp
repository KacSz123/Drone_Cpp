#ifndef SCENE_HPP
#define SCENE_HPP
/*!
 * @file scene.hpp
 * @author {Kacper Szczepanowski} ({kacperszcz159@gmail.com})
 * @brief File contains  model of a Scene with gemotric objects, both drones and obstacles.
 *
 * Using module "lacze_do_gnuplota" in order to draw objects inf GnuPlot.
 * @version 0.9
 * @date 2023-06-07
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "drone.hpp"
#include "cuboid_obstacle.hpp"
#include "lacze_do_gnuplota.hpp"
#include <string>
#include <list>
#include <memory>
#include <unistd.h>
#include <thread>
#include <future>
#include <mutex>
#include <cstdarg>
    
// #include <process.h>
/*!
 * @brief New type model: shared pointer to \see SceneObj.
 *
 */
using sh_ptr_scene_obj = std::shared_ptr<SceneObj>;
/*!
 * @brief New type model: shared pointer to \see CuboidObstacle.
 * 
 */
using sh_ptr_obst = std::shared_ptr<CuboidObstacle>;

using ObstacleList = std::list<sh_ptr_obst>;


/*!
 * @brief New type: list of of shared_ptr to \see ScecneObj instances.
 *
 */
using SceneObjectsList = std::list<sh_ptr_scene_obj>;

/*!
 * @brief New type model: shared pointer to \see Drone.
 *
 */
using sh_ptr_Drone = std::shared_ptr<Drone>;
/*!
 * @brief New type: list of of shared_ptr to Drone instances.
 *
 */
using DronesList = std::list<sh_ptr_Drone>;

/*!
 * @brief New type model: pointer to PzG::InfoPlikuDoRysowania.
 *
 */
using handFileInfo = PzG::InfoPlikuDoRysowania *;

/*!
 * @brief New Type model: list of handlers to files.
 *
 */
using fileHandlerList = std::vector<std::vector<handFileInfo>>;

using obstFileHandList = std::vector<handFileInfo>;

/*!
 * \brief Scene Model of a robotic scene.
 *
 *
 * Class contains SceneObject such as Drones and Obstacles.
 * Allows to controll the drones with checking for collisions. Also features adding
 * Scene objects (and all derived classes) and controll selected.
 */
 class Scene
{
private:
 std::mutex m;


    /*!
     * @brief Plot boundaries.
     *
     */
    constexpr static float Xupper = 400.0, Xlow = -400.0, Yupper = 400.0,
                           Ylow = -400.0, Zupper = 400.0, Zlow = -400.0;

    /*!
     * @brief List of all objects.
     *
     * List of all objects, used for collision test. \see SceneObjectsList.
     */
    SceneObjectsList _sceneObjList;

    /*!
     * @brief List Drones.
     *
     * List of all Drones, used for controll specific Drone. \see DronesList.
     */
    DronesList _dronesList;


    ObstacleList _obstaclesList;

    /*!
     * @brief Active Drone to take action.
     *
     */
    sh_ptr_Drone _activeDrone;

    /*!
     * @brief Active Obstacle to take action.
     *
     */
    sh_ptr_obst _activeObstacle;

    /*!
     * @brief List of handlers to Drone files.
     *
     * List for visualization in Gnuplot.
     */
    fileHandlerList _dronesFilesList;

    /*!
     * @brief List of handlers to Obstacle files.
     *
     * List for visualization of Obstacles in Gnuplot.
     */
    obstFileHandList _obstacleFilesList;

    /*!
     * @brief TBA
     *
     */
    handFileInfo _pathHandler;

    /*!
     * @brief Visualization in Gnuplot.
     *
     * Object provided by "lacze_do_gnuplota.hpp". Object for visualization in \p Gnuplot
     */
    PzG::LaczeDoGNUPlota _link;

public:
    /*!
     * @brief Construct a new Scene object
     *
     * And configure visualization Link
     */
    Scene();
    /*!
     * @brief Destroy the Scene object
     *
     */
    ~Scene(){};

    /*!
     * @brief Insert new Drone object to scene.
     *
     * Creates new object and insert it to Drones list and to SceneObj list.
     * @param[in] midPt - base point of Drone.
     * @param[in] scale - Scale Drones size.
     */
    void addDrone(vector3D midPt, double scale);
    /*!
     * @brief  Insert new Drone object to scene.
     *
     * Insert new Drone to Drones list and to SceneObj list. New object
     * created based on s
     * @param[in] drone - pointer to drone
     */
    void addDrone(sh_ptr_Drone drone);

    void printAvailableDrones()
    {
        std::cout<<"Available drones [ID]: ";
        for(auto d:_dronesList)
        {
            std::cout<<d->getID()<<", ";
        }
        std::cout<<std::endl;
    }

    void printAvailableObstacles()
    {
        std::cout<<"Available drones [ID]: ";
        for(auto o:_obstaclesList)
        {
            std::cout<<o->getID()<<", ";
        }
        std::cout<<std::endl;
    }

    /*!
     * @brief Activates specify  Drone on list.
     *
     * @param[in] i - index of list
     */
    void activateDrone(uint i);



    void activateObstacle(uint i);


    /*!
     * @brief Move active drone.
     *
     * Move active drone forwad (relative to own X axis) with specify speed.
     *
     * @param[in] pathLen - length of drone path
     * @param[in] speed - speed of animation
     */

    void moveActiveDroneForward(double pathLen, double speed = 1);

    /*!
     * @brief Rotate active drone.
     *
     * Rotates active drone relative to Z axis) with specify speed of drone and rotors.
     * Roation is animated.
     * @param[in] angle - angle of rotation.
     * @param[in] speed - speed of animation.
     * @param[in] rotSpeed - speed of rotors spin animation.
     */
    void rotateActiveDrone(double angle, double speed = 1, double rotSpeed = 1);

    void rotateActiveDrone1Step(double angle);

    /*!
     * @brief Soar active drone.
     *
     * Soar active drone relative to X and Z axis.
     * @param[in] pathLen - length of drones path.
     * @param[in] angle - angle going up.
     * @param[in] speed - speed of animation.
     */
    void soarActiveDrone(double pathLen, double angle, double speed = 1);

    /*!
     * @brief Looks for collision with selected object.
     *
     * Compares positions of all objects on Scene with specified object.
     * @param[in] obj - chosen object.
     * @return true - collision detected.
     * @return false - no collisions.
     */
    bool checkForCollision(sh_ptr_Drone obj);

    /*!
     * @brief Visualization config
     *
     * Uses Lacze_do_Gnuplota.
     */
    void configureGnuplotLink();


    /*!
     * @brief Add Drone to visualization object.
     * 
     * Insert new object to Drones list, and Object list.
     * 
     * @param[in] drone - shared pointer to Drone.
     */
    void addDronesFileToGPLink(sh_ptr_Drone drone);

    /*!
     * @brief Add obstacle to scene
     * 
     * @param obs - \see sh_ptr_obst to obstacle
     */
    void addObstacle(sh_ptr_obst obs);

    void addObstacle(vector3D v, double x, double y, double z);
    /*!
     * @brief Add Obstacle to visualization object.
     * 
     * Insert new object to Obstacles list, and Object list.
     * 
     * @param[in] cObst - shared pointer to CuboidObstacle.
     */
    void addObstacleToGPlink(sh_ptr_obst cObst);

    
    /*!
     * @brief Check for collision.
     * 
     * Checking if there is any collision for object selected by place in list.
     * 
     * @param droneIndex - index of Drone in list.
     */
    void checkColision(int droneIndex);

    /*!
     * @brief Draw scene in Gnuplot
     * 
     */
    void drawScene() { _link.Rysuj(); }

    void droneArcMove(double path, double angle, int steps = 100)
    {

        double stepP = path/steps, stepA = angle/steps;
        std::cout<<stepP<<"   "<<stepA<<"\n";
        getchar();
        for(int i=0; i<steps; ++i)
        {
            moveActiveDroneForward1Step(stepP);
            rotateActiveDrone1Step(stepA);
            if(checkForCollision(_activeDrone))
                break;
        }


        std::cout<<_activeDrone->getPosition()<<"\n";
    }

    void proceedDroneCommand()
    {

    }
    void move2Drones(int ind1, int ind2)
    {

    }

    void moveFewDrones()
    {

    }

    void moveActiveDroneForward1Step(double pathLen);
};

#endif