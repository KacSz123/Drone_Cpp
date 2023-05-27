

#include "drone.hpp"

using namespace std;
unsigned int Drone:: _droneNo = 0;
Drone::Drone(vector3D midPoint):_ID(++_droneNo)
{
    vector3D *midPt = new vector3D;
    this->_body = new Cuboid(*midPt, 60, 60, 30);
    // std::cout<<*(this->_body)<<"\n";
     vector3D *tmpVec;
     HexagonalPrism *tmpHex; 
    for(int i=0; i<2; ++i)
    {
        tmpVec = new vector3D(0,0,10);
     *tmpVec =*tmpVec + this->_body->getCorner(i);
     tmpHex= new HexagonalPrism(*tmpVec, 20,25);
     this->_rotors.push_back(*tmpHex);
     
     delete tmpHex;
     delete tmpVec; 
    }
    for(int i=6; i<8; ++i)
    {
     vector3D *tmp2Vec= new vector3D(0,0,10);
    //  std::cout<<this->_body->getCorner(i)<<"---\n";
     *tmp2Vec =*tmp2Vec + this->_body->getCorner(i);
     HexagonalPrism *tmp2Hex = new HexagonalPrism(*tmp2Vec, 20,25);
     this->_rotors.push_back(*tmp2Hex);
     
     delete tmp2Hex;
     delete tmp2Vec; 
    }
    
    this->_midPoint = new vector3D;
    this->_midPoint->setCoords(midPt->getCoord(0),midPt->getCoord(1),midPt->getCoord(2)+25);


    this->generateNames();
    this->printStdNames();

}
Drone::Drone():_ID(++_droneNo){}
void Drone::generateNames()
{
    string *str1 = new string("");
    *str1= string(DATA_DIR)+"Drone_"+to_string(_ID)+"_body";
    this->fileNames.push_back(*str1);

    str1->clear();
    for(int i=1; i<5;++i)
    {
        *str1= string(DATA_DIR)+"Drone_"+to_string(_ID)+"_rotor"+to_string(i);
        this->fileNames.push_back(*str1);
        str1->clear();
    }
    delete str1;
}

void Drone::printStdNames()
{
    for(fileVec::iterator i=fileNames.begin(); i!=fileNames.end(); i++)
        cout<<*i<<"\n";
}
void Drone::moveDrone(double x)
{
    _body->moveForward(x);
    for(rotorsVec::iterator i=_rotors.begin(); i!=_rotors.end(); i++)
        i->moveForward(x);
}