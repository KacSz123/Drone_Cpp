

#include "drone.hpp"
#include <cmath>
using namespace std;
unsigned int Drone::_droneNo = 0;
// static inline double toRad
inline static double toRadians(const double radians)
{
    return radians * (M_PI / 180);
}
Drone::Drone(vector3D midPoint, double scale) : _ID(++_droneNo)
{
    vector3D *midPt = new vector3D(midPoint);

    this->_body = new Cuboid(*midPt, 60*scale, 60*scale, 30*scale);
    // std::cout<<*(this->_body)<<"\n";
    vector3D *tmpVec;
    HexagonalPrism *tmpHex;
    for (int i = 0; i < 2; ++i)
    {
        tmpVec = new vector3D(0, 0, 10*scale);
        *tmpVec = *tmpVec + this->_body->getCorner(i);
        tmpHex = new HexagonalPrism(*tmpVec, 20*scale, 25*scale);
        tmpHex->setOrientation(_body->getOrientation());
        this->_rotors.push_back(*tmpHex);

        delete tmpHex;
        delete tmpVec;
    }
    for (int i = 6; i < 8; ++i)
    {
        vector3D *tmp2Vec = new vector3D(0, 0, 10*scale);
        //  std::cout<<this->_body->getCorner(i)<<"---\n";
        *tmp2Vec = *tmp2Vec + this->_body->getCorner(i);
        HexagonalPrism *tmp2Hex = new HexagonalPrism(*tmp2Vec, 20*scale, 25*scale);
        tmp2Hex->setOrientation(_body->getOrientation());
        this->_rotors.push_back(*tmp2Hex);

        delete tmp2Hex;
        delete tmp2Vec;
    }

    this->_midPoint = new vector3D;
    this->_midPoint->setCoords(midPt->getCoord(0), midPt->getCoord(1), midPt->getCoord(2) + 25);

    this->generateNames();
    // this->printNamesOnStd();
}
Drone::Drone() : _ID(++_droneNo) {}
void Drone::generateNames()
{
    string *str1 = new string("");
    *str1 = string(DATA_DIR) + "Drone_" + to_string(_ID) + "_body";
    this->fileNames.push_back(*str1);

    str1->clear();
    for (int i = 1; i < 5; ++i)
    {
        *str1 = string(DATA_DIR) + "Drone_" + to_string(_ID) + "_rotor" + to_string(i);
        this->fileNames.push_back(*str1);
        str1->clear();
    }
    delete str1;
}

void Drone::printNamesOnStd()
{
    for (fileVec::iterator i = fileNames.begin(); i != fileNames.end(); i++)
        cout << *i << "\n";
}
void Drone::moveDrone(double x, double speed, double rotorsSpeed)
{
    _body->moveForward(x);
    for (rotorsVec::iterator i = _rotors.begin(); i != _rotors.end(); ++i)
        i->moveForward(x);
    this->spinRotors(x,rotorsSpeed);
}

void Drone::soarDrone(const double pathLen, const double angle, double speed, double rotorsSpeed)
{
    double const x = pathLen * cos(toRadians(angle));
    double const z = pathLen * sin(toRadians(angle));
    _body->soarForward(x, z);
    for (rotorsVec::iterator i = _rotors.begin(); i != _rotors.end(); i++)
        i->soarForward(x, z);

    this->spinRotors(pathLen,rotorsSpeed);
}

void Drone::spinRotors(const double distance, double speed, bool direction)
{

    double rotParam;
    double *vel;
    constexpr int velDiff = 5;
    if (!direction && distance == 0)
    {
        // std::cout<<"op1\n";
        rotParam = -1;
        vel = new double[4]{rotParam * speed * velDiff, -rotParam * speed, -rotParam * speed , rotParam * speed*velDiff};
    }
    else if (direction && distance == 0)
    {
        // std::cout<<"op2\n";
        rotParam = 1;
        vel = new double[4]{-rotParam * speed, -rotParam * speed*velDiff, -rotParam * speed*velDiff, rotParam * speed };
    }
    else{
        rotParam = distance*2;
        // std::cout<<"esle\n";
        vel = new double[4]{rotParam * speed, -rotParam * speed, -rotParam * speed, rotParam*speed};
}
    for (uint i = 0; i < _rotors.size(); ++i)
        _rotors[i].rotateWithStaticOrient(vel[i], 'z');
    delete vel;
}

void Drone::rotateDrone(double angle, double speed, double rotorsSpeed)
{
    // this->getMidPoint()
    _body->rotate(angle, 'z');
    for (rotorsVec::iterator i = _rotors.begin(); i != _rotors.end(); ++i)
    {
        i->setOrientation(_body->getOrientation());
        i->rotate(angle, 'z', false, this->getMidPoint());
    }

    if(angle>=0)
        this->spinRotors(0,rotorsSpeed);
    else
        this->spinRotors(0,rotorsSpeed,false);
}
