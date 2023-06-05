#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include <unistd.h>
#include <memory>

// #include "drone.hpp"
// #include "vector2d.hpp"
// #include "matrix2x2.hpp"
// #include "cuboid.hpp"
// #include "hexagonal_prism.hpp"
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
       Vector2d<double, 3> *vMid=new vector3D(-75.0, -75.0, 0.0);
       Vector2d<double, 3> *vMid2=new vector3D(75.0, 75.0, 20.0);
       Vector2d<double, 3> *vMid3=new vector3D(75.0, 75.0, -60.0);
       vector3D *tab = new vector3D[3]{*vMid,*vMid2,*vMid3};
       // std::cout<<"debug01\n";
       // Drone *d = new Drone(*vMid);

       Scene *sc = new Scene();
       std::cout<<"debug02\n";
       
       // auto shared_drone = std::make_shared<Drone>(Drone(tab[i]));
       
       getchar();
       for(int i=0; i<3;++i)
       {
                     std::shared_ptr<Drone> a=std::make_shared<Drone>(Drone(tab[i]));
                     sc->addDrone(a);
       }
       std::cout<<"debug04\n";
       getchar();

       vector3D::printCounters();
       std::cout<<"debug03\n";
       sc->drawScene();
       getchar();
       delete sc;
       // a.reset();

       // shared_drone.reset();
       delete vMid;        
       delete vMid2;       
       delete vMid3;     
       delete[] tab;   
       // droneList.clear();


       // vecList.push_back(std::make_shared<vector3D>(*vMid2));
       // delete d;

       // std::cout<<d->getMidPoint()<<std::endl;
       // Cuboid *c = new Cuboid(*vMid, 50, 50, 50);
       // Drone d2(vMid2, 0.6);
       // Drone d3(vMid3,1.7);
       // HexagonalPrism *d=new HexagonalPrism(*vMid,20,30);
//        try
//               {
//                      Vector2d<double, 2> a(1,2,3);
//               }
//        catch(VectorConstructorException a)
//        {
//               std::cout<<"exception caught.\n"<<typeid(a).name();
//        }
// //   // rysunku prostokata

       vector3D::printCounters();
       SceneObj::printCounters();
       // link1.AddFilename(d2[0].c_str(), PzG::LS_CONTINUOUS, 2);
       // link1.AddFilename(d2[1].c_str(), PzG::LS_CONTINUOUS, 2);
       // link1.AddFilename(d2[2].c_str(), PzG::LS_CONTINUOUS, 2);
       // link1.AddFilename(d2[3].c_str(), PzG::LS_CONTINUOUS, 2);
       // link1.AddFilename(d2[4].c_str(), PzG::LS_CONTINUOUS, 2);

       // link1.AddFilename(d3[0].c_str(), PzG::LS_CONTINUOUS, 2);
       // link1.AddFilename(d3[1].c_str(), PzG::LS_CONTINUOUS, 2);
       // link1.AddFilename(d3[2].c_str(), PzG::LS_CONTINUOUS, 2);
        
        return 0;
}
       // link1.AddFilename(d3[3].c_str(), PzG::LS_CONTINUOUS, 2);
       // link1.AddFilename(d3[4].c_str(), PzG::LS_CONTINUOUS, 2);
       

       // link1.
       //-------------------------------------------------------
       //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
       //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
       //  na dwa sposoby:
       //   1. Rysowane jako linia ciagl o grubosci 2 piksele
       //

       //
       //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
       //      których połowa długości boku wynosi 2.
       //
       // link.AddFilename("data/prostokat.dat", PzG::LS_SCATTERED, 2);
       //
       //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów

       //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
       //  jako wspolrzedne punktow podajemy tylko x,y.
       //

       // if (!WriteToFileExample(d2.getBody(), d2[0].c_str()))
       //        return 1;
       // if (!WriteToFileExample(d2.getRotor(0), d2[1].c_str()))
       //        return 1;
       // if (!WriteToFileExample(d2.getRotor(1), d2[2].c_str()))
       //        return 1;
       // if (!WriteToFileExample(d2.getRotor(2), d2[3].c_str()))
       //        return 1;
       // if (!WriteToFileExample(d2.getRotor(3), d2[4].c_str()))
       //        return 1;


       // if (!WriteToFileExample(d3.getBody(), d3[0].c_str()))
       //        return 1;
       // if (!WriteToFileExample(d3.getRotor(0), d3[1].c_str()))
       //        return 1;
       // if (!WriteToFileExample(d3.getRotor(1), d3[2].c_str()))
       //        return 1;
       // if (!WriteToFileExample(d3.getRotor(2), d3[3].c_str()))
       //        return 1;
       // if (!WriteToFileExample(d3.getRotor(3), d3[4].c_str()))
       //        return 1;

       // link1.Draw();
       // sleep(1);
// std::cout<<"MID POINTS!!!-\n";
// std::cout<<"body mpt: "<<d.getBody().getMidPoint()<<std::endl;
// std::cout<<"r1 mpt: "<<d.getRotor(0).getMidPoint()<<std::endl;
// std::cout<<"r2 mpt: "<<d.getRotor(1).getMidPoint()<<std::endl;
// std::cout<<"r3 mpt: "<<d.getRotor(2).getMidPoint()<<std::endl;
// std::cout<<"r4 mpt: "<<d.getRotor(3).getMidPoint()<<std::endl;
// std::cout<<"ORIENTATION!!!-\n";
// std::cout<<"body mpt: \n"<<d.getBody().getOrientation()<<std::endl;
// std::cout<<"r1 mpt: \n"<<d.getRotor(0).getOrientation()<<std::endl;
// std::cout<<"r2 mpt: \n"<<d.getRotor(1).getOrientation()<<std::endl;
// std::cout<<"r3 mpt: \n"<<d.getRotor(2).getOrientation()<<std::endl;
// std::cout<<"r4 mpt: \n"<<d.getRotor(3).getOrientation()<<std::endl;
// for(int i=0;i<200;++i)
// { 
//        d.moveDrone(1);
//        usleep(500);
//               if (!WriteToFileExample(d.getBody(), d[0].c_str()))
//               return 1;

//        if (!WriteToFileExample(d.getRotor(0), d[1].c_str()))
//               return 1;

//        if (!WriteToFileExample(d.getRotor(1), d[2].c_str()))
//               return 1;

//        if (!WriteToFileExample(d.getRotor(2), d[3].c_str()))
//               return 1;
//        if (!WriteToFileExample(d.getRotor(3), d[4].c_str()))
//               return 1;
//        usleep(500);

//        link1.Draw();
//        usleep(500);
//        }
// std::cout<<"MID POINTS!!!-\n";
// std::cout<<"body mpt: "<<d.getBody().getMidPoint()<<std::endl;
// std::cout<<"r1 mpt: "<<d.getRotor(0).getMidPoint()<<std::endl;
// std::cout<<"r2 mpt: "<<d.getRotor(1).getMidPoint()<<std::endl;
// std::cout<<"r3 mpt: "<<d.getRotor(2).getMidPoint()<<std::endl;
// std::cout<<"r4 mpt: "<<d.getRotor(3).getMidPoint()<<std::endl;
// std::cout<<"ORIENTATION!!!-\n";
// std::cout<<"body mpt: \n"<<d.getBody().getOrientation()<<std::endl;
// std::cout<<"r1 mpt: \n"<<d.getRotor(0).getOrientation()<<std::endl;
// std::cout<<"r2 mpt: \n"<<d.getRotor(1).getOrientation()<<std::endl;
// std::cout<<"r3 mpt: \n"<<d.getRotor(2).getOrientation()<<std::endl;
// std::cout<<"r4 mpt: \n"<<d.getRotor(3).getOrientation()<<std::endl;
// getchar();
// for(int i=0;i<100;++i)
// { 
//        d.soarDrone(1,45);
//        usleep(500);
//               if (!WriteToFileExample(d.getBody(), d[0].c_str()))
//               return 1;

//        if (!WriteToFileExample(d.getRotor(0), d[1].c_str()))
//               return 1;

//        if (!WriteToFileExample(d.getRotor(1), d[2].c_str()))
//               return 1;

//        if (!WriteToFileExample(d.getRotor(2), d[3].c_str()))
//               return 1;
//        if (!WriteToFileExample(d.getRotor(3), d[4].c_str()))
//               return 1;
//        usleep(500);

//        link1.Draw();
//        usleep(500);
//        }
// getchar();
// for(int i=0;i<150;++i)
// { 
//        d.moveDrone(1,1, 5);
//        usleep(500);
//               if (!WriteToFileExample(d.getBody(), d[0].c_str()))
//               return 1;

//        if (!WriteToFileExample(d.getRotor(0), d[1].c_str()))
//               return 1;

//        if (!WriteToFileExample(d.getRotor(1), d[2].c_str()))
//               return 1;

//        if (!WriteToFileExample(d.getRotor(2), d[3].c_str()))
//               return 1;
//        if (!WriteToFileExample(d.getRotor(3), d[4].c_str()))
//               return 1;
//        usleep(delay);

//        link1.Draw();
//        usleep(delay);
//        std::cout<<"1\n";
//        }

//  getchar();
// for(int i=0;i<150;++i)
// { 
//        d.moveDrone(1,1,1);
//        usleep(500);
//               if (!WriteToFileExample(d.getBody(), d[0].c_str()))
//               return 1;

//        if (!WriteToFileExample(d.getRotor(0), d[1].c_str()))
//               return 1;

//        if (!WriteToFileExample(d.getRotor(1), d[2].c_str()))
//               return 1;

//        if (!WriteToFileExample(d.getRotor(2), d[3].c_str()))
//               return 1;
//        if (!WriteToFileExample(d.getRotor(3), d[4].c_str()))
//               return 1;
//        usleep(delay);

//        link1.Draw();
//        usleep(delay);
//        std::cout<<"1\n";
//        }

//  getchar();
// for(int i=0;i<100;++i)
// { 
//        d.rotateDrone(-0.5);
//        usleep(500);
//               if (!WriteToFileExample(d.getBody(), d[0].c_str()))
//               return 1;

//        if (!WriteToFileExample(d.getRotor(0), d[1].c_str()))
//               return 1;

//        if (!WriteToFileExample(d.getRotor(1), d[2].c_str()))
//               return 1;

//        if (!WriteToFileExample(d.getRotor(2), d[3].c_str()))
//               return 1;
//        if (!WriteToFileExample(d.getRotor(3), d[4].c_str()))
//               return 1;
//        usleep(delay);

//        link1.Draw();
//        usleep(delay);
//        }


       //  getchar();

       //       std::cout<<"233\n";
       //  try
       //  {droneList.clear();}
       //  catch(...)
       //  {

       //       std::cout<<"well....\n";
       //  }

// 

