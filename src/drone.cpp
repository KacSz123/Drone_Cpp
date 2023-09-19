

#include "drone.hpp"
#include <cmath>
using namespace std;
unsigned int Drone::_droneNo = 0;
// static inline double toRad
inline static double toRadians(const double radians)
{
    return radians * (M_PI / 180);
}
Drone::Drone(vector3D midPoint, double scale):SceneObj{}, _ID(++_droneNo)
{

    vector3D midPt(midPoint);
    _body = Cuboid(midPt, _basicBodyW * scale, _basicBodyL * scale, _basicBodyH * scale,_basicBodyL*scale/2);
    vector3D tmpVec(0, 0, 0);
    HexagonalPrism *tmpHex = new HexagonalPrism();
    for (int i = 0; i < 2; ++i)
    {
        tmpVec.setCoords(0, 0, 10 * scale);
        tmpVec = tmpVec + _body.getCorner(i);
        *tmpHex = HexagonalPrism(tmpVec, _basicRotorH * scale, _basicRotorR * scale);
        tmpHex->setOrientation(_body.getOrientation());
        this->_rotors.push_back(*tmpHex);
    }
    for (int i = 6; i < 8; ++i)
    {
        tmpVec.setCoords(0, 0, 10 * scale);
        tmpVec = tmpVec + _body.getCorner(i);
        *tmpHex = HexagonalPrism(tmpVec, _basicRotorH * scale, _basicRotorR * scale);
        tmpHex->setOrientation(_body.getOrientation());
        this->_rotors.push_back(*tmpHex);
    }
    delete tmpHex;
    
    this->generateNames();

    _midPoint.setCoords(midPt.getCoord(0), midPt.getCoord(1),
                        midPt.getCoord(2) + (_basicRotorH * scale) / 2.0);

    this->setPosition(this->getMidPoint());
    this->setHeight(((_basicBodyH * scale)+(_basicRotorH * scale))/2.0);
    this->setCircleRadius(sqrt(pow(_basicBodyL*scale/2.0,2)+pow((_basicBodyW*scale/2.0),2)) + _basicRotorR*sqrt(2.0));
    // setPosition(getMidPoint());
    // getchar();

}
Drone::Drone(): _ID(++_droneNo){}
void Drone::generateNames()
{
    string *str1 = new string("");
    *str1 = string(DATA_DIR) + "Drone_" + to_string(_ID) + "_body.dat";
    this->fileNames.push_back(*str1);

    str1->clear();
    for (int i = 1; i < 5; ++i)
    {
        *str1 = string(DATA_DIR) + "Drone_" + to_string(_ID) + "_rotor.dat" + to_string(i);
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
    _body.moveForward(x);
    for (rotorsVec::iterator i = _rotors.begin(); i != _rotors.end(); ++i)
        i->moveForward(x);
    this->spinRotors(x, rotorsSpeed);
    // auto tmpvec = vector3D(x,0,0);
    this->_midPoint.setCoords(_midPoint.getCoord(0)+x,_midPoint.getCoord(1),_midPoint.getCoord(2));
    this->setPosition(getMidPoint());

    std::cout<<"--------------------\n";
    std::cout<<"srodek "<<getMidPoint()<<"\n";
    std::cout<<"postion "<<getPosition()<<"\n";
    std::cout<<"--------------------\n";
}

void Drone::soarDrone(const double pathLen, const double angle, double speed, double rotorsSpeed)
{
    double const x = pathLen * cos(toRadians(angle));
    double const z = pathLen * sin(toRadians(angle));
    _body.soarForward(x, z);
    for (rotorsVec::iterator i = _rotors.begin(); i != _rotors.end(); i++)
        i->soarForward(x, z);

    this->spinRotors(pathLen, rotorsSpeed);
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
        vel = new double[4]{rotParam * speed * velDiff, -rotParam * speed, -rotParam * speed, rotParam * speed * velDiff};
    }
    else if (direction && distance == 0)
    {
        // std::cout<<"op2\n";
        rotParam = 1;
        vel = new double[4]{-rotParam * speed, -rotParam * speed * velDiff, -rotParam * speed * velDiff, rotParam * speed};
    }
    else
    {
        rotParam = distance * 2;
        // std::cout<<"esle\n";
        vel = new double[4]{rotParam * speed, -rotParam * speed, -rotParam * speed, rotParam * speed};
    }
    for (uint i = 0; i < _rotors.size(); ++i)
        _rotors[i].rotateWithStaticOrient(vel[i], 'z');
    delete vel;
}

void Drone::rotateDrone(double angle, double speed, double rotorsSpeed)
{
    _body.rotate(angle, 'z',true, _body.getMidPoint());
    for (rotorsVec::iterator i = _rotors.begin(); i != _rotors.end(); ++i)
    {
        i->setOrientation(_body.getOrientation());
        i->rotate(angle, 'z', false, this->getBody().getMidPoint());
    }
    
    if (angle >= 0)
        this->spinRotors(0, rotorsSpeed);
    else
        this->spinRotors(0, rotorsSpeed, false);
}

double Drone::getXYDistance(const SceneObj *another) const
{
    return 0;
}
double Drone::getZDistance(const SceneObj *another) const
{
    return 0;
}

void Drone::writeToFiles()
{

    if (!_body.writeToFile((*this)[0]))
        exit(1);

    for (int i = 1; i < 5; ++i)
    {
        if (!_rotors[i - 1].writeToFile((*this)[i]))
            exit(1);
    }
}

Drone::Drone(const Drone &d) : _ID{d.getID()}
{
    this->_body = d.getBody();
    fileNames.push_back(d[0]);
    _midPoint = d.getMidPoint();
    for (int i = 0; i < 4; ++i)
    {
        this->_rotors.push_back(d.getRotor(i));

        fileNames.push_back(d[i + 1]);
    }
    this->setPosition(d.getPosition());
    this->setHeight(d.getHeight());
    this->setCircleRadius(d.getCircleRadius());


}