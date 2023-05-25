

#include "drone.hpp"

using namespace std;
Drone::Drone(vector3D midPoint)
{
    vector3D *midPt = new vector3D;
    this->_body = new Cuboid(*midPt, 100, 60, 30);
    std::cout<<*(this->_body)<<"\n";
    for(int i=0; i<2; ++i)
    {
     vector3D *tmpVec= new vector3D(0,0,10);
     *tmpVec =*tmpVec + this->_body->getCorner(i);
     HexagonalPrism *tmpHex = new HexagonalPrism(*tmpVec, 20,20);
     this->_rotors.push_back(*tmpHex);
     
     delete tmpHex;
     delete tmpVec; 
    }
    for(int i=6; i<8; ++i)
    {
     vector3D *tmp2Vec= new vector3D(0,0,10);
     std::cout<<this->_body->getCorner(i)<<"---\n";
     *tmp2Vec =*tmp2Vec + this->_body->getCorner(i);
     HexagonalPrism *tmp2Hex = new HexagonalPrism(*tmp2Vec, 20,20);
     this->_rotors.push_back(*tmp2Hex);
     
     delete tmp2Hex;
     delete tmp2Vec; 
    }
    
    this->_midPoint = new vector3D;
    this->_midPoint->setCoords(midPt->getCoord(0),midPt->getCoord(1),midPt->getCoord(2)+25);


    cout<<*(this->_midPoint)<<"\n";
    for(int i=0; i<4; ++i)
    cout<<this->_rotors[i].getMidPoint()<<"\n";

}