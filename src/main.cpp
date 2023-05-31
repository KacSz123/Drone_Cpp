#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <unistd.h>
#include "gnuplot_link.hpp"

#include "drone.hpp"
#include "vector2d.hpp"
#include "matrix2x2.hpp"
#include "cuboid.hpp"
#include "hexagonal_prism.hpp"
using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */

const int kShorterEdgesLength = 10;
const int kLongerEdgesLength = 150;

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] output_stream - strumien wyjsciowy, do ktorego maja zostac
 *                            zapisane kolejne wspolrzedne.
 * \param[in] offset - ten parameter jest tylko po to, aby pokazać
 *                     mozliwosc zmiany wspolrzednych i prostokata
 *                     i zmiane jego polorzenia na okienku graficznym
 *                     rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void WriteToStreamExample(Cuboid rect, ostream &output_stream)
{
       output_stream << rect << "\n";
}
void WriteToStreamExample(HexagonalPrism hex, ostream &output_stream)
{
       output_stream << hex << "\n";
}
/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] filename - nazwa pliku, do którego zostana zapisane
 *                       wspolrzędne punktów.
 * \param[in] offset - ten parameter jest tylko po to, aby pokazać
 *                     mozliwosc zmiany wspolrzednych i prostokata
 *                     i zmiane jego polorzenia na okienku graficznym
 *                     rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool WriteToFileExample(Cuboid rect, string filename)
{
       ofstream file_stream;
       file_stream.open(filename);
       if (!file_stream.is_open())
       {
              cerr << ":(  Operacja otwarcia do zapisu \"" << filename << "\"" << endl
                   << ":(  nie powiodla sie." << endl;
              return false;
       }
       WriteToStreamExample(rect, file_stream);
       file_stream.close();
       return !file_stream.fail();
}

bool WriteToFileExample(HexagonalPrism hex, string filename)
{
       ofstream file_stream;
       file_stream.open(filename);
       if (!file_stream.is_open())
       {
              cerr << ":(  Operacja otwarcia do zapisu \"" << filename << "\"" << endl
                   << ":(  nie powiodla sie." << endl;
              return false;
       }
       WriteToStreamExample(hex, file_stream);
       file_stream.close();
       return !file_stream.fail();
}
void rotate_rect_anim(Cuboid &rect, double angle, PzG::GnuplotLink link, string filename, char axis)
{
       Cuboid tmpRect;
       tmpRect = rect;

       if (angle >= 0.0)
              for (int i = 0; i <= int(angle); ++i)
              {
                     {
                            tmpRect.rotate(1.0, axis);
                            // WriteToStreamExample(tmpRect, cout);
                            usleep(10000);
                            if (!WriteToFileExample(tmpRect, filename))
                                   break;
                            usleep(10000);
                            link.Draw();
                     }
              }
       else
       {
              for (int i = angle; i <= 0; ++i)
              {
                     tmpRect.rotate(1.0, axis);
                     // WriteToStreamExample(tmpRect, cout);
                     usleep(10000);
                     if (!WriteToFileExample(tmpRect, filename))
                            break;
                     usleep(10000);
                     link.Draw();
              }
       }
       usleep(10000);
       rect.rotate(angle, axis);
       // WriteToStreamExample(rect, cout);
       usleep(10000);
       if (!WriteToFileExample(rect, filename))
              cout << "!!!!!!!!!!!!!\n";
       usleep(10000);
       link.Draw();
       usleep(10000);
}

void rotate_rect_anim(HexagonalPrism &rect, double angle, PzG::GnuplotLink link, string filename, char axis)
{
       HexagonalPrism tmpRect;
       tmpRect = rect;

       if (angle >= 0.0)
              for (int i = 0; i <= int(angle); ++i)
              {
                     {
                            tmpRect.rotate(1.0, axis);
                            // WriteToStreamExample(tmpRect, cout);
                            usleep(10000);
                            if (!WriteToFileExample(tmpRect, filename))
                                   break;
                            usleep(10000);
                            link.Draw();
                     }
              }
       else
       {
              for (int i = angle; i <= 0; ++i)
              {
                     tmpRect.rotate(1.0, axis);
                     // WriteToStreamExample(tmpRect, cout);
                     usleep(10000);
                     if (!WriteToFileExample(tmpRect, filename))
                            break;
                     usleep(10000);
                     link.Draw();
              }
       }
       usleep(10000);
       rect.rotate(angle, axis);
       // WriteToStreamExample(rect, cout);
       usleep(10000);
       if (!WriteToFileExample(rect, filename))
              cout << "!!!!!!!!!!!!!\n";
       usleep(10000);
       link.Draw();
       usleep(10000);
}

void moveC(Cuboid &rect, double xv, PzG::GnuplotLink link, string filename)
{      


       Cuboid tmpRect;
       tmpRect = rect;
       if (xv > 0)
       {
              for (int i = 0; i <= int(xv); ++i)
              {
                     tmpRect.moveForward(1);
                     // WriteToStreamExample(tmpRect, cout);
                     usleep(10000);
                     if (!WriteToFileExample(tmpRect, filename.c_str()))
                            break;
                     usleep(10000);
                     link.Draw();
              }
       }
       else
       {
              for (int i = int(xv); i <= 0; ++i)
              {
                     tmpRect.moveForward(-1);
                     // WriteToStreamExample(tmpRect, cout);
                     usleep(10000);
                     if (!WriteToFileExample(tmpRect, filename.c_str()))
                            break;
                     usleep(10000);
                     link.Draw();
              }
       }

       usleep(10000);
       rect.moveForward(xv);
       // WriteToStreamExample(rect, cout);
       usleep(10000);
       if (!WriteToFileExample(rect, filename.c_str()))
              cout << "!!!!!!!!!!!!!\n";
       usleep(10000);

       link.Draw();
       usleep(10000);
}
void moveC(HexagonalPrism &rect, double xv, PzG::GnuplotLink link, string filename)
{
       HexagonalPrism tmpRect;
       tmpRect = rect;
       if (xv > 0)
       {
              for (int i = 0; i <= int(xv); ++i)
              {
                     tmpRect.moveForward(1);
                     // WriteToStreamExample(tmpRect, cout);
                     usleep(10000);
                     if (!WriteToFileExample(tmpRect, filename.c_str()))
                            break;
                     usleep(10000);
                     link.Draw();
              }
       }
       else
       {
              for (int i = int(xv); i <= 0; ++i)
              {
                     tmpRect.moveForward(-1);
                     // WriteToStreamExample(tmpRect, cout);
                     usleep(10000);
                     if (!WriteToFileExample(tmpRect, filename.c_str()))
                            break;
                     usleep(10000);
                     link.Draw();
              }
       }

       usleep(10000);
       rect.moveForward(xv);
       // WriteToStreamExample(rect, cout);
       usleep(10000);
       if (!WriteToFileExample(rect, filename.c_str()))
              cout << "!!!!!!!!!!!!!\n";
       usleep(10000);

       link.Draw();
       // cout << 1 << endl;//
       usleep(10000);
}

void addToDrawingList(PzG::GnuplotLink &l, const char *name)
{
}
int main()
{
       const int delay = 10000;
       Vector2d<double, 3> vMid,vMid2,vMid3;

       vMid.setCoords(-75.0, -75.0, 0.0);
       vMid2.setCoords(100.0, -60.0, 20.0);
       vMid3.setCoords(100.0, 100.0, -20.0);

       Drone d(vMid);
       Drone d2(vMid2, 0.6);
       Drone d3(vMid3,1.7);

  // rysunku prostokata
       PzG::GnuplotLink link1;                 // Ta zmienna jest potrzebna do wizualizacji
       link1.SetDrawingMode(PzG::DM_3D);
       link1.Init();

       link1.AddFilename(d[0].c_str(), PzG::LS_CONTINUOUS, 2);
       link1.AddFilename(d[1].c_str(), PzG::LS_CONTINUOUS, 2);
       link1.AddFilename(d[2].c_str(), PzG::LS_CONTINUOUS, 2);
       link1.AddFilename(d[3].c_str(), PzG::LS_CONTINUOUS, 2);
       link1.AddFilename(d[4].c_str(), PzG::LS_CONTINUOUS, 2);

       link1.AddFilename(d2[0].c_str(), PzG::LS_CONTINUOUS, 2);
       link1.AddFilename(d2[1].c_str(), PzG::LS_CONTINUOUS, 2);
       link1.AddFilename(d2[2].c_str(), PzG::LS_CONTINUOUS, 2);
       link1.AddFilename(d2[3].c_str(), PzG::LS_CONTINUOUS, 2);
       link1.AddFilename(d2[4].c_str(), PzG::LS_CONTINUOUS, 2);

       link1.AddFilename(d3[0].c_str(), PzG::LS_CONTINUOUS, 2);
       link1.AddFilename(d3[1].c_str(), PzG::LS_CONTINUOUS, 2);
       link1.AddFilename(d3[2].c_str(), PzG::LS_CONTINUOUS, 2);
       link1.AddFilename(d3[3].c_str(), PzG::LS_CONTINUOUS, 2);
       link1.AddFilename(d3[4].c_str(), PzG::LS_CONTINUOUS, 2);
       

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

       if (!WriteToFileExample(d.getBody(), d[0].c_str()))
              return 1;
       if (!WriteToFileExample(d.getRotor(0), d[1].c_str()))
              return 1;
       if (!WriteToFileExample(d.getRotor(1), d[2].c_str()))
              return 1;
       if (!WriteToFileExample(d.getRotor(2), d[3].c_str()))
              return 1;
       if (!WriteToFileExample(d.getRotor(3), d[4].c_str()))
              return 1;
       
       // sleep(1);
       // link1.Draw();

       if (!WriteToFileExample(d2.getBody(), d2[0].c_str()))
              return 1;
       if (!WriteToFileExample(d2.getRotor(0), d2[1].c_str()))
              return 1;
       if (!WriteToFileExample(d2.getRotor(1), d2[2].c_str()))
              return 1;
       if (!WriteToFileExample(d2.getRotor(2), d2[3].c_str()))
              return 1;
       if (!WriteToFileExample(d2.getRotor(3), d2[4].c_str()))
              return 1;


       if (!WriteToFileExample(d3.getBody(), d3[0].c_str()))
              return 1;
       if (!WriteToFileExample(d3.getRotor(0), d3[1].c_str()))
              return 1;
       if (!WriteToFileExample(d3.getRotor(1), d3[2].c_str()))
              return 1;
       if (!WriteToFileExample(d3.getRotor(2), d3[3].c_str()))
              return 1;
       if (!WriteToFileExample(d3.getRotor(3), d3[4].c_str()))
              return 1;

       link1.Draw();
       sleep(1);
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
getchar();
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


//         getchar();
//         return 0;
// 
}

