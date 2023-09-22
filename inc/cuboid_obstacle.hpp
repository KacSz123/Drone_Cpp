#ifndef CUBOID_OBSTACLE_HPP
#define CUBOID_OBSTACLE_HPP
/*!
 * @file cuboid_obstacle.hpp
 * @author {Kacper Szczepanowski} ({kacperszcz159@gmail.com})
 * @brief Model of class derived from SceneObj. Describes obstacle on robotic scene.
 * @version 0.1
 * @date 2023-09-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "scene_obj.hpp"
#include "cuboid.hpp"

#include<string>

#define DATA_DIR "./data/"

/*!
 * @brief CuboidObstacle inherits from \see SceneObj.
 * 
 * Describes CuboidObstacle which is a specific type of  \see SceneObj.
 */
class CuboidObstacle: public SceneObj
{
   /*!
    * @brief Default values of Cuboid.
    * 
    */
constexpr static double Xdefault = 30, Ydefault = 50, Zdefault = 100;

private:
   /*!
    * @brief ID no. of Obstacle
    */
   const uint _ID;

   /*!
    * @brief Cuboid obstacle
    * 
    */
   Cuboid _obstacle;

   /*!
    * @brief Name of related file.
    * 
    */
   std::string  _filename;


   /*!
    * @brief Actual size of Obstacle.
    * 
    */
   double _x,_y,_z;
   /*!
    * @brief Counter of Obstacle.
    * 
    * Related with \see _ID.
    */
   static uint _cuboidObstCntr;
public:

   /*!
    * @brief Construct a new Cuboid Obstacle object
    * 
    */
    CuboidObstacle();
    /*!
     * @brief Construct a new Cuboid Obstacle object
     * 
     * @param[in] v - basic point.
     * @param[in] x - x size of Cuboid.
     * @param[in] y  - y size of Cuboid.
     * @param[in] z  - z size of Cuboid.
     */
    CuboidObstacle(vector3D& v,double x=Xdefault, double y=Ydefault,double z=Zdefault);
    
    CuboidObstacle(const vector3D &v,double x=Xdefault, double y=Ydefault,double z=Zdefault);
    /*!
     * @brief Destroy the Cuboid Obstacle object
     * 
     */
    ~CuboidObstacle();
   
   /*!
    * @brief Return _ID.
    * 
    * @return uint ID value.
    */
   uint getID()const{return _ID;}

   /*!
    * @brief Write coordinates to specific file.
    * 
    * Open file with \see _filename and write coordinates.
    * 
    */
    void writeToFile(){_obstacle.writeToFile(_filename);};

    /*!
     * @brief Get the File Name object
     * 
     * @return std::string name
     */
    std::string getFileName()const {return _filename;};

    /*!
     * @brief Return body object.
     * 
     * @return Cuboid - body.
     */
    Cuboid getCuboid()const {return _obstacle;};

    /*!
     * @brief Copy Constructor
     * 
     * 
     * Construct a new Cuboid Obstacle object based on another.
     * @param[in] d - basic object.
     */
   CuboidObstacle(const CuboidObstacle &d):_ID{d.getID()}
   {
      _obstacle = d.getCuboid();
      _filename = d.getFileName();
      this->setPosition(d.getPosition());
      this->setHeight(d.getHeight());
      this->setCircleRadius(d.getCircleRadius());
   }
}; 


#endif //CUBOID_OBSTACLE_HPP