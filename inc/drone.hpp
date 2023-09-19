#ifndef DRONE_HPP
#define DRONE_HPP

#include <iostream>
#include <vector>
#include <string>
#include "hexagonal_prism.hpp"
#include "cuboid.hpp"
#include "scene_obj.hpp"

#define DATA_DIR "./data/"

typedef std::vector<HexagonalPrism> rotorsVec;
typedef std::vector<std::string> fileVec;

/*!
 * @brief 
 * 
 */
class Drone: public SceneObj
{
    private:
        constexpr static double _basicBodyW=60;
        constexpr static double _basicBodyL=60;
        constexpr static double _basicBodyH=30;
        constexpr static double _basicRotorR=25;
        constexpr static double _basicRotorH=20;
        // double _scale;
        static unsigned int _droneNo;
        const unsigned int _ID;
        Cuboid _body;
        rotorsVec _rotors;
        vector3D _midPoint;
        fileVec fileNames;
        std::vector<vector3D> _path;

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
         * @param[in] v Instance of Drone object to copy.
         */
        Drone(const Drone &v);
        /*!
         * @brief Destroy the Drone object
         * 
         * Default destructor of the Drone object.
         */
        ~Drone(){};


        vector3D getMidPoint() const{ return (_midPoint); }
        const std::string operator[](unsigned i) { return fileNames[i]; }
        const std::string operator[](unsigned i)const { return fileNames[i]; }
        Cuboid getBody()const { return _body; }
        HexagonalPrism getRotor(int i) { return _rotors[i]; }
        void generateNames();
        void printNamesOnStd();
        void moveDrone(const double x, double speed=1, double rotorsSpeed=1);
        void soarDrone(const double x, const double angle, double speed=1, double rotorsSpeed=1);
        void rotateDrone(const double angle, double speed=1, double rotorsSpeed=1);
        void spinRotors(const double distance, double speed=1, bool direction=true);

        void setMidPoint(vector3D& a){this->_midPoint=a;}
        void printBody(){_body.printVertexes();};
        void writeToFiles();
        HexagonalPrism getRotor(int i)const {return _rotors[i];}
        uint getID()const{return _ID;}
        // ifDetectedCollision(const SceneObj & anotherObj) const {return false;};
};

#endif //DRONE_HPP