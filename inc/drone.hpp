#ifndef DRONE_HPP
#define DRONE_HPP
/*!
 * @file drone.hpp
 * @author {Kacper Szczepanowski} ({kacperszcz159@gmail.com})
 * @brief File contains definition of \p Drone class.
 * @version 0.1
 * @date 2023-09-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include "hexagonal_prism.hpp"
#include "cuboid.hpp"
#include "scene_obj.hpp"
#include <mutex>
#define DATA_DIR "./data/"
/*!
 * @brief Vector of rotors
 * 
 * New type: std vector of HexagonalPrism.
 */
typedef std::vector<HexagonalPrism> rotorsVec;

/*!
 * @brief Vector of filenames
 * 
 * New type: std vector of filenames
 */
typedef std::vector<std::string> fileVec;

/*!
 * @brief Drone object with controll methods.
 * 
 * Class storage information about Drone which is a derived class from \p SceneObj.
 * Contains methods for controlling drone in 3D space.
 */
class Drone: public SceneObj
{
    private:
    std::mutex m;
    /*!
     * @brief Basic Drone size.
     * 
     */
        constexpr static double _basicBodyW= 60,  _basicBodyL= 60,
                              _basicBodyH= 30,  _basicRotorR=25,  _basicRotorH=20;
 
        /*!
         * @brief Counter of existed Drones.
         * 
         */
        static unsigned int _droneNo;

        /*!
         * @brief Specific Drone ID number.
         * 
         */
        const unsigned int _ID;
        /*!
         * @brief Body of Drone.
         * 
         * Instance of \p Cuboid class.
         */
        Cuboid _body;

        /*!
         * @brief Vector of Rotors
         * 
         */
        rotorsVec _rotors;
        
        /*!
         * @brief Middle point of Drone.
         * 
         * 
         */
        vector3D _midPoint;

    /*!
     * @brief Vector of related filenames.
     * 
     */
        fileVec fileNames;

        /*!
         * @brief path of Drone.
         * 
         * TBA.
         */
        std::vector<vector3D> _path;
        double _scale;

    public:
        
        /*!
        * @brief Construct a new Drone object
        * 
        * Nonparametrical (default) constructor of object Drone. Creates Drone object
        * in point (0,0,0) with default
        * 
        * @see Drone(const Drone &v), @see Drone(vector3D midPoint, double scale=1.0)
        */    
        Drone();
        /*!
         * @brief Construct a new Drone object
         * 
         * Parametrical Drone constructor. Sets
         * 
         * @param[in] midPoint Base point of Drone object.
         * @param[in] scale  Variable to manipulate with object size.
         */
        Drone(vector3D midPoint, double scale=1.0);

        /*!
         * @brief Construct a new Drone object based on another Drone object.
         * 
         * Copy constructor of Drone object.
         * @param[in] d Instance of Drone object to copy.
         */
        Drone(const Drone &d);


        double getRadius(){return 2.2;}

        Drone( Drone &&v);
        /*!
         * @brief Destroy the Drone object
         * 
         * Default destructor of the Drone object.
         */
        ~Drone(){--_droneNo; _rotors.clear(), _rotors.shrink_to_fit(); fileNames.clear(); fileNames.shrink_to_fit();};

        /*!
         * @brief Get the center point of Drone
         * 
         * @return vector3D 
         */
        vector3D getMidPoint() const{ return (_midPoint); }
        
        /*!
         * @brief Overload operator \b [] .
         * 
         * Returnes i-th element of filenames vector.
         * 0 -> _body
         * 1-4 -> one of rotors.
         * @param[in] i - index of filename Vector. 
         * @return const std::string 
         */
        const std::string operator[](unsigned i) { return fileNames[i]; }

        /*!
         * @brief Overload operator \b [] .
         * 
         * Returnes i-th element of filenames vector.
         * 0 -> _body
         * 1-4 -> one of rotors.
         * @param[in] i - index of filename Vector. 
         * @return const std::string 
         */
        const std::string operator[](unsigned i)const { return fileNames[i]; }
        
        
        /*!
         * @brief Return  Body object
         * 
         * @return Cuboid - body of drone
         */
        Cuboid getBody()const { return _body; }

        /*!
         * @brief Return Rotor object
         * 
         * Return one of rotors.
         * 
         * @param[in] i - index of rotors vector. 
         * @return HexagonalPrism - one of rotor.
         */
        HexagonalPrism getRotor(int i) { return _rotors[i]; }


        /*!
         * @brief Return Rotor object
         * 
         * Return one of rotors.
         * 
         * @param[in] i - index of rotors vector. 
         * @return HexagonalPrism - one of rotor.
         */
        HexagonalPrism getRotor(int i)const {return _rotors[i];}


        /*!
         * @brief Generate names for files.
         * 
         * Generator of strings used for related files. 
         * Every existing drone has independent files due to \p _ID.
         */
        void generateNames();
        /*!
         * @brief Print all names of files on std out.
         * 
         */
        void printNamesOnStd();

        /*!
         * @brief Move drone in onw X axis.
         * 
         * Moves drone forward. Based on own orientation.
         * 
         * @param[in] x - length in X axis. 
         * @param[in] speed - speed for rotors speed.
         * @param[in] rotorsSpeed - param for rotors speed.
         */
        void moveDrone(const double x, double speed=1, double rotorsSpeed=1);
        /*!
         * @brief Move drone in onw X axis and global Z axis.
         * 
         * Moves drone forward and up. 
         * 
         * @param[in] x - length in X axis. 
         * @param[in] angle - angle of going up
         * @param[in] rotorsSpeed - param for rotors speed.
         */
        void soarDrone(const double x, const double angle, double rotorsSpeed=1);
        
        /*!
         * @brief Rotate Drone around its own axis.
         * 
         * 
         * Rotate Drone around its own axis.
         * 
         * @param[in] angle - angle of rotation 
         * @param[in] rotorsSpeed -param for rotors spin
         */
        void rotateDrone(const double angle,  double rotorsSpeed=1);

        /*!
         * @brief Rotate rotors.
         * 
         * Rotating rotors while Drones moving.
         * 
         * @param[in] distance - of drone moving/or angle if it rotate.
         * @param[in] speed - speed of spin.
         * @param[in] direction - direction of rotation.
         */
        void spinRotors(const double distance, double speed=1, bool direction=true);

        /*!
         * @brief Set the Mid Point object
         * 
         * @param[in] a New center vector value. 
         */
        void setMidPoint(const vector3D& a){this->_midPoint=a;}

        /*!
         * @brief Print body on std out.
         * 
         */
        void printBody(){_body.printVertexes();};

        /*!
         * @brief Write body and rotors to files
         * 
         */
        void writeToFiles();
        
        /*!
         * @brief Get _ID value.
         * 
         * @return uint 
         */
        uint getID()const{return _ID;}
        
        // ifDetectedCollision(const SceneObj & anotherObj) const {return false;};
};

#endif //DRONE_HPP