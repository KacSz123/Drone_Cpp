#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <unistd.h>
#include <memory>

#include "scene.hpp"
using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */

const int kShorterEdgesLength = 10;
const int kLongerEdgesLength = 150;




int main()
{
       std::cout<<"debug0\n";
       // const int delay = 10000;

       // Drone a = Drone(vector3D(0,0,0));
       Vector2d<double, 3> *vMid=new vector3D(0.0, 0.0, 0.0);
       Vector2d<double, 3> *vMid2=new vector3D(-170.0, 0.0, 0.0);
       Vector2d<double, 3> *vMid3=new vector3D(0.0, 250.0, 0.0);
       vector3D *tab = new vector3D[3]{*vMid,*vMid2,*vMid3};


       Scene *sc = new Scene();
       std::cout<<"debug02\n";
       
       // auto shared_drone = std::make_shared<Drone>(Drone(tab[i]));
       
       // getchar();

       for(int i=1; i<3;++i)
       {
                     std::shared_ptr<Drone> a=std::make_shared<Drone>(Drone(tab[i]));
                     sc->addDrone(a);
       }

       // std::shared_ptr<CuboidObstacle> b=std::make_shared<CuboidObstacle>(CuboidObstacle(*vMid));
       sc->addObstacle(std::make_shared<CuboidObstacle>(CuboidObstacle(*vMid)));

       vector3D::printCounters();
       std::cout<<"debug03\n";
       sc->drawScene();
       sc->activateDrone(0);
       getchar();
       sc->moveActiveDroneForward(130);
       getchar();
       
       sc->rotateActiveDrone(45);
       getchar();
       sc->activateDrone(1);

       sc->rotateActiveDrone(-45);
       sc->moveActiveDroneForward(130);
       // sc->checkColision(0);
       getchar();
       delete sc;
       // a.reset();

       // shared_drone.reset();
       delete vMid;        
       delete vMid2;       
       delete vMid3;     
       delete[] tab;   


       vector3D::printCounters();
       SceneObj::printCounters();

        return 0;
}
