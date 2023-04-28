#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <unistd.h>

#include "vector2d.hpp"
#include "gnuplot_link.hpp"
#include "matrix2x2.hpp"
#include "cuboid.hpp"

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

       output_stream << rect <<"\n";
       //  rect.getCorner(0) << "\n"
       //               << rect.getCorner(1);
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

void test();

void rotate_rect_animY(Cuboid &rect, double angle, PzG::GnuplotLink link, string filename)
{
       Cuboid tmpRect;
       tmpRect = rect;
       if (angle >= 0.0)
              for (int i = 0; i <= int(angle); ++i)
              {
                     {
                            tmpRect.rotateYaxis(1.0);
                            // WriteToStreamExample(tmpRect, cout);
                            usleep(10000);
                            if (!WriteToFileExample(tmpRect,filename))
                                   break;
                            usleep(10000);

                            link.Draw();

                     }
              }
       else
       {
              for (int i = angle; i <= 0; ++i)
              {
                     tmpRect.rotateYaxis(-1.0);
                     // WriteToStreamExample(tmpRect, cout);
                     usleep(10000);
                     if (!WriteToFileExample(tmpRect, filename))
                            break;
                     usleep(10000);
                     link.Draw();

              }
       }
       usleep(10000);
       rect.rotateYaxis(angle);
       WriteToStreamExample(rect, cout);
       usleep(10000);
       if (!WriteToFileExample(rect, filename))
              cout << "!!!!!!!!!!!!!\n";
       usleep(10000);
       link.Draw();
       usleep(10000);
}

void rotate_rect_animX(Cuboid &rect, double angle, PzG::GnuplotLink link, string filename)
{
       Cuboid tmpRect;
       tmpRect = rect;
       if (angle >= 0.0)
              for (int i = 0; i <= int(angle); ++i)
              {
                     {
                            tmpRect.rotateXaxis(1.0);
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
                     tmpRect.rotateXaxis(-1.0);
                     // WriteToStreamExample(tmpRect, cout);
                     usleep(10000);
                     if (!WriteToFileExample(tmpRect, filename))
                            break;
                     usleep(10000);
                     link.Draw();

              }
       }
       usleep(10000);
       rect.rotateXaxis(angle);
       WriteToStreamExample(rect, cout);
       usleep(10000);
       if (!WriteToFileExample(rect, filename))
              cout << "!!!!!!!!!!!!!\n";
       usleep(10000);
       link.Draw();

       usleep(10000);
}
void rotate_rect_animZ(Cuboid &rect, double angle, PzG::GnuplotLink link, string filename)
{

       Cuboid tmpRect;
       tmpRect = rect;
       if (angle >= 0.0)
              for (int i = 0; i <= int(angle); ++i)
              {
                     {
                            tmpRect.rotateZaxis(1.0);
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
                     tmpRect.rotateZaxis(-1.0);
                     // WriteToStreamExample(tmpRect, cout);
                     usleep(10000);
                     if (!WriteToFileExample(tmpRect, filename))
                            break;
                     usleep(10000);
                     link.Draw();
              }
       }
       usleep(10000);
       rect.rotateZaxis(angle);
       WriteToStreamExample(rect, cout);
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
                     tmpRect.moveCuboidForward(1);
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
                     tmpRect.moveCuboidForward(-1);
                     // WriteToStreamExample(tmpRect, cout);
                     usleep(10000);
                     if (!WriteToFileExample(tmpRect, filename.c_str()))
                            break;
                     usleep(10000);
                     link.Draw();
              }
       }

       usleep(10000);
       rect.moveCuboidForward(xv);
       WriteToStreamExample(rect, cout);
       usleep(10000);
       if (!WriteToFileExample(rect, filename.c_str()))
              cout << "!!!!!!!!!!!!!\n";
       usleep(10000);

       link.Draw();
       cout << 1 << endl;
       usleep(10000);
}


void addToDrawingList(PzG::GnuplotLink &l, const char* name)
{
  
             
}
int main()
{
       Vector2d<double, 3> vMid, vMid2, vMid3;
       vMid.setCoords(0.0, 0.0, 0.0);
       vMid2.setCoords(0.0, -10.0, -100.0);
       vMid3.setCoords(60.0, 40.0, 20.0);
       Cuboid rect(vMid, 60.0, 40.0, 20.0); 
       Cuboid rect2(vMid2, 100.0, 30.0, 30.0); 
       Cuboid rect3(vMid3, 80.0, 30.0, 30.0); // To tylko przykladowe definicje zmiennej
       PzG::GnuplotLink link1;                // Ta zmienna jest potrzebna do wizualizacji
                                  // rysunku prostokata
       const char *sep=", ";
       string f1="data/prostokat1.dat", f2="data/prostokat2.dat", f3="data/prostokat3.dat";
       link1.AddDrawingFromFiles(f1,&sep);
       link1.AddDrawingFromFiles(f2,&sep);
       link1.AddDrawingFromFiles(f3,&sep);
       //-------------------------------------------------------
       //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
       //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
       //  na dwa sposoby:
       //   1. Rysowane jako linia ciagl o grubosci 2 piksele
       //
       link1.SetDrawingMode(PzG::DM_3D);

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
       link1.AddFilename(f1.c_str(), PzG::LS_CONTINUOUS, 2);
       WriteToStreamExample(rect, cout);
       if (!WriteToFileExample(rect, f1.c_str()))
              return 1;
       link1.Draw();
       link1.AddFilename(f2.c_str(), PzG::LS_CONTINUOUS, 2);
       WriteToStreamExample(rect2, cout);
       if (!WriteToFileExample(rect2, f2.c_str()))
              return 1;
       link1.Draw();
       link1.AddFilename(f3.c_str(), PzG::LS_CONTINUOUS, 2);
       WriteToStreamExample(rect3, cout);
       if (!WriteToFileExample(rect3, f3.c_str()))
              return 1;
              
       // sleep(1); 

       link1.Draw();
       sleep(1);
    rotate_rect_animY(rect, 90, link1,f1);
       sleep(1);
    rotate_rect_animZ(rect3, -90, link1,f3);
       sleep(1);
       moveC(rect2, 100, link1,f2);
       sleep(1);
       moveC(rect, 100, link1,f1);
    rotate_rect_animY(rect2, 90, link1,f2);
       sleep(1);
       moveC(rect3, 100, link1,f3);
       getchar();

 }
