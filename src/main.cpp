#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <unistd.h>
#include <memory>

#include "scene.hpp"
using namespace std;




int main()
{
       VectorNd<double, 3> *vMid3=new vector3D(0.0, 0.0, 0.0);
       VectorNd<double, 3> *vMid2=new vector3D(-170.0, 0.0, 0.0);
       VectorNd<double, 3> *vMid=new vector3D(0.0, 250.0, 0.0);
       vector3D *tab = new vector3D[3]{*vMid,*vMid2,*vMid3};


       Scene *sc = new Scene();


       for(int i=1; i<3;++i)
       {
                     std::shared_ptr<Drone> a=std::make_shared<Drone>(tab[i]);
                     sc->addDrone(a);
       }

       sc->addObstacle(std::make_shared<CuboidObstacle>(*vMid));

       vector3D::printCounters();
       sc->drawScene();
       sc->activateDrone(0);
       getchar();
       sc->moveActiveDroneForward(130);
       getchar();
       
       sc->rotateActiveDrone(45);
       getchar();
       sc->activateDrone(1);

       sc->rotateActiveDrone(-45);
       getchar();

       sc->moveActiveDroneForward(130);
       getchar();
       sc->soarActiveDrone(200, -30);
       // sc->checkColision(0);
       getchar();
       delete sc;
       
       delete vMid;        
       delete vMid2;       
       delete vMid3;     
       delete[] tab;   


       vector3D::printCounters();
       SceneObj::printCounters();

        return 0;
}
