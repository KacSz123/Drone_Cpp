#include <iostream>
#include "scene.hpp"
using namespace std;
void showMenu()
{
       using std::cout;
       using std::endl;

       cout<<"***********************************************\n"
             "******************  OPTIONS  ******************\n"
             "*****       m     SHOW MENU               *****\n"
             "*****                                     *****\n"
             "*****       d     ADD DRONE               *****\n"
             "*****       o     ADD OBSTACLE            *****\n"
             "*****                                     *****\n"
             "*****       z     ACTIVATE DRONE          *****\n"
             "*****       c     ACTIVATE OBSTACLE       *****\n"
             "*****                                     *****\n"
             "*****       r     REMOVE DRONE            *****\n"
             "*****       x     REMOVE OBSTACLE         *****\n"
             "*****                                     *****\n"
             "*****       g     MOVE ACTIVE DRONE       *****\n"
             "*****       l     ROTATE ACTIVE DRONE     *****\n"
             "*****       p     MOVEARC ACTIVE DRONE    *****\n"
             "*****                                     *****\n"
             "*****       i     PRINT VECTORS COUNTERS  *****\n"
             "*****                                     *****\n"
             "*****       s     SET ACTIVE OBST. POSE   *****\n"
             "*****       e     END PROGRAM             *****\n"
             "***********************************************\n"
             "***********************************************\n";
}
typedef enum
{
       ADD_DRONE = 'd',
       ADD_OBSTACLE = 'o',
       ACTIVATE_DRONE = 'z',
       ACTIVATE_OBSTACLE = 'c',
       REMOVE_DRONE = 'r',
       REMOVE_OBSTACLE = 'x',
       MOVE_ACTIVE_DRONE = 'g',
       ROTATE_ACTIVE_DRONE = 'l',
       MOVEARC_ACTIVE_DRONE = 'p',
       SET_OBSTACLE_POSITIION = 's',
       PRINT_COUNTERS = 'i',
       SHOW_MENU = 'm',
       SKIP_ENTER = '\n',
       END_PROGRAM = 'e'

} menuOptions;

int main()
{

       Scene  *sc = new Scene();
       char choice = '\0';
       std::cout<<"podaj vector3d: x,y,z\n";
       vector3D *a = new vector3D();
       std::cin>>*a;
       std::cout<<"podany vector: "<<*a<<"\n";
       delete a;
       while (choice!='k')
       {

              switch (choice=getchar())
              {
              case ADD_DRONE:
              {

                     break;
              }
              case ADD_OBSTACLE:
              {
                     break;
              }
              case ACTIVATE_DRONE:
              {
                     break;
              }
              case ACTIVATE_OBSTACLE:
              {
                     break;
              }
              case REMOVE_DRONE:
              {
                     break;
              }
              case REMOVE_OBSTACLE:
              {
                     break;
              }
              case MOVE_ACTIVE_DRONE:
              {
                     break;
              }
              case ROTATE_ACTIVE_DRONE:
              {
                     break;
              }
              case MOVEARC_ACTIVE_DRONE:
              {
                     break;
              }
              case SET_OBSTACLE_POSITIION:
              {
                     break;
              }
              case SHOW_MENU:
              {
                     break;
              }
              case SKIP_ENTER:
              {
                     break;
              }
              case END_PROGRAM:
              {

                     break;
              }
              default:
                     break;
              }
       }

       // Scene *sc = new Scene();

       sc->addDrone(std::make_shared<Drone>(vector3D(0.0, 0.0, 0.0)));
       sc->addDrone(std::make_shared<Drone>(vector3D(-170.0, 0.0, 0.0)));

       sc->addObstacle(std::make_shared<CuboidObstacle>(vector3D(0.0, 250.0, 0.0)));
       sc->addObstacle(std::make_shared<CuboidObstacle>(vector3D(0.0, -250.0, 0.0)));

       vector3D::printCounters();
       sc->printAvailableDrones();
       sc->printAvailableObstacles();

       sc->drawScene();
       sc->activateDrone(0);
       sc->activateObstacle(1);

       vector3D::printCounters();

       getchar();

       sc->rotateActiveDrone(-90);
       getchar();
       sc->activateDrone(1);
       sc->rotateActiveDrone(-90);

       getchar();
       sc->droneArcMove(250, 90);
       getchar();

       delete sc;

       vector3D::printCounters();
       SceneObj::printCounters();

       return 0;
}
