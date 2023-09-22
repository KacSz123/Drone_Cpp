#include "scene.hpp"
#include <mutex>

Scene::Scene(/* args */)
{
    this->configureGnuplotLink();
}

void Scene::addDrone(vector3D midPt, double scale)
{
    auto drone = std::make_shared<Drone>(Drone(midPt, scale));
    _sceneObjList.push_back(drone);
    _dronesList.push_back(drone);
    this->addDronesFileToGPLink(drone);
    drone.reset();
}

void Scene::addDrone(sh_ptr_Drone drone)
{
    _sceneObjList.push_back(drone);
    _dronesList.push_back(drone);
    drone->writeToFiles();

    this->addDronesFileToGPLink(drone);
    this->drawScene();
}
void Scene::activateDrone(uint i)
{
    try
    {
        _activeDrone = *(std::next(_dronesList.begin(), i));
        for (long unsigned int it = 0; it < _dronesFilesList.size(); ++it)
        {
            auto itt = _dronesFilesList[it];
            if (it == i)
            {
                for (std::vector<handFileInfo>::iterator it2 = itt.begin(); it2 != itt.end(); ++it2)
                    (*it2)->ZmienSzerokosc(2);
            }
            else
            {
                for (std::vector<handFileInfo>::iterator it2 = itt.begin(); it2 != itt.end(); ++it2)
                    (*it2)->ZmienSzerokosc(1);
            }
        }
    }
    catch (std::bad_alloc *a)
    {
        std::cout << "Wron index of Drone list!\n";
        if (_dronesList.size() == 0)
            std::cout << "List of Drones is empty!\n";
        // break;
    }
}

void Scene::activateObstacle(uint i)
{
    std::cout<<1<<std::endl;
    try
    {
    std::cout<<2<<std::endl;

    int it=0;
    for(auto ob:_obstaclesList)
    {
        if(ob->getID() == i)
        {
            _activeObstacle = ob;
            break;
        }
        ++it;
    }
    for( auto itt = 0; itt<static_cast<int>(_obstacleFilesList.size()); ++itt)
    {
        if(itt == it)
        _obstacleFilesList[itt]->ZmienSzerokosc(2);
        else
        _obstacleFilesList[itt]->ZmienSzerokosc(1);
    }

    

    }
    catch (std::bad_alloc *a)
    {
    std::cout<<5<<std::endl;

        std::cout << "Wron index of Obstacles list!\n";
        if (_obstaclesList.size() == 0)
            std::cout << "List of Obstacles is empty!\n";
        // break;
    }
}
void Scene::moveActiveDroneForward(double pathLen, double speed)
{
    for (double i = 0; i < pathLen; i += speed)
    {

        _activeDrone->moveDrone(speed);
        usleep(100);
        _activeDrone->writeToFiles();
        usleep(100);
        drawScene();
    }

    std::cout << _activeDrone->getMidPoint() << "\n";
}
void Scene::moveActiveDroneForward1Step(double pathLen)
{

    _activeDrone->moveDrone(pathLen);
    usleep(100);
    _activeDrone->writeToFiles();
    usleep(100);
    drawScene();

    std::cout << _activeDrone->getMidPoint() << "\n";
}

void Scene::rotateActiveDrone(double angle, double speed, double rotSpeed)
{

    for (double i = 0; i < abs(angle); i += speed)
    {

        auto a = angle > 0 ? speed : -speed;
        _activeDrone->rotateDrone(a, rotSpeed);
        usleep(200);
        _activeDrone->writeToFiles();
        drawScene();

        if (checkForCollision(_activeDrone))
        {
            std::cout << "WARNING! Close to collision!\n";
        }
    }
    std::cout << _activeDrone->getPosition() << "\n";
}

void Scene::rotateActiveDrone1Step(double angle)
{
    // auto a = angle > 0 ? speed : -speed;
    _activeDrone->rotateDrone(angle);
    usleep(100);
    _activeDrone->writeToFiles();
    usleep(100);
    drawScene();
    // usleep(50);

    if (checkForCollision(_activeDrone))
    {
        std::cout << "WARNING! Close to collision!\n";
    }

    std::cout << _activeDrone->getPosition() << "\n";
}
void Scene::soarActiveDrone(double pathLen, double angle, double speed)
{

    for (double i = 0; i < abs(pathLen); i += speed)
    {
        // auto a= angle>0?1:-1;
        _activeDrone->soarDrone(speed, angle);
        _activeDrone->writeToFiles();
        usleep(1500);
        drawScene();
        if (checkForCollision(_activeDrone))
        {
            std::cout << "WARNING! Close to collision!\n";
        }
    }
}

bool Scene::checkForCollision(sh_ptr_Drone obj)
{
    for (SceneObjectsList::iterator i = _sceneObjList.begin(); i != _sceneObjList.end(); ++i)
    {
        if (*i != obj && obj->ifDetectedCollision((*i)))
        {
            std::cout << "Collision!\n";
            return true;
        }
    }
    // std::cout << "NO Collision!\n";
    return false;
}

void Scene::configureGnuplotLink()
{
    _link.ZmienTrybRys(PzG::TR_3D);
    _link.UstawZakresX(Xlow, Xupper);
    _link.UstawZakresY(Ylow, Yupper);
    _link.UstawZakresZ(Zlow, Zupper);
    _link.UstawRotacjeXZ(40, 40);
}

void Scene::addDronesFileToGPLink(sh_ptr_Drone drone)
{
    std::vector<handFileInfo> tmp;
    static int kolor = 1;
    if (kolor > 10)
        kolor = 1;
    PzG::InfoPlikuDoRysowania *fileInfo = &_link.DodajNazwePliku((*drone)[0].c_str());
    fileInfo->ZmienKolor(kolor);
    tmp.push_back(fileInfo);
    for (int i = 1; i < 5; ++i)
    {
        PzG::InfoPlikuDoRysowania *fileInfo = &_link.DodajNazwePliku((*drone)[i].c_str());
        tmp.push_back(fileInfo);
        fileInfo->ZmienKolor(kolor);
    }
    _dronesFilesList.push_back(tmp);
    ++kolor;
}

void Scene::addObstacleToGPlink(sh_ptr_obst cObst)
{
    constexpr static int kolor_ = 16;
    PzG::InfoPlikuDoRysowania *fileInfo = &_link.DodajNazwePliku(cObst->getFileName().c_str());
    fileInfo->ZmienKolor(kolor_);
    fileInfo->ZmienSzerokosc(1);
    _obstacleFilesList.push_back(fileInfo);
}
void Scene::addObstacle(sh_ptr_obst obs)
{
    _sceneObjList.push_back(obs);
    _obstaclesList.push_back(obs);
    obs->writeToFile();
    this->addObstacleToGPlink(obs);
    this->drawScene();
}
void Scene::addObstacle(vector3D v, double x, double y, double z)
{   
    std::shared_ptr<CuboidObstacle> obs;
    if (x == 0 || y == 0 || z == 0)
    {
        obs = std::make_shared<CuboidObstacle>(v);
        _sceneObjList.push_back(obs);
        _obstaclesList.push_back(obs);
    }
    else
    {
        obs = std::make_shared<CuboidObstacle>(v, x, y, z);
        _sceneObjList.push_back(obs);
        _obstaclesList.push_back(obs);
    }

    obs->writeToFile();
    this->addObstacleToGPlink(obs);
    this->drawScene();
}


void Scene::checkColision(int droneIndex)
{
    try
    {
        DronesList::iterator it = std::next(_dronesList.begin(), droneIndex);
        checkForCollision((*it));
    }
    catch (std::bad_alloc *a)
    {
        std::cout << "Wron index of Drone list!\n";
        if (_dronesList.size() == 0)
            std::cout << "List of Drones is empty!\n";
    }
    catch (...)
    {
        std::cout << "sth went wrong, but idk;\n";
    }
}