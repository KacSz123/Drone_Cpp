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
       cout << 1 << endl;
       usleep(10000);
}

void addToDrawingList(PzG::GnuplotLink &l, const char *name)
{
}
int main()
{
       Vector2d<double, 3> vMid, vMid2, vMid3;

       vMid.setCoords(0.0, 0.0, 0.0);

       vMid2.setCoords(0.0, 0.0, 100.0);
       vMid3.setCoords(60.0, 40.0, 20.0);
       Cuboid rect(vMid, 60.0, 40.0, 20.0);

       Drone d(vMid);

       // Cuboid rect2(vMid2, 100.0, 30.0, 30.0);
       Cuboid rect3(vMid3, 180.0, 30.0, 30.0); // To tylko przykladowe definicje zmiennej
       PzG::GnuplotLink link1;                 // Ta zmienna jest potrzebna do wizualizacji
       HexagonalPrism hex(vMid2, 60.0, 60.0);  // rysunku prostokata
       const char *sep = ", ";
       string f1 = "data/prostokat1.dat", f2 = "data/prostokat2.dat", f3 = "data/prostokat3.dat";
       link1.AddDrawingFromFiles(f1, &sep);
       link1.AddDrawingFromFiles(f2, &sep);
       link1.AddDrawingFromFiles(f3, &sep);
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
       // WriteToStreamExample(rect, cout);
       if (!WriteToFileExample(rect, f1.c_str()))
              return 1;
       link1.Draw();
       link1.AddFilename(f2.c_str(), PzG::LS_CONTINUOUS, 2);
       // WriteToStreamExample(hex, cout);
       if (!WriteToFileExample(hex, f2.c_str()))
              return 1;
       link1.Draw();
       link1.AddFilename(f3.c_str(), PzG::LS_CONTINUOUS, 2);
       // WriteToStreamExample(rect3, cout);
       if (!WriteToFileExample(rect3, f3.c_str()))
              return 1;

       sleep(1);

       //        link1.Draw();
       //        sleep(1);
       //     rotate_rect_anim(rect, 90, link1,f1,'Y');
       //        sleep(1);
       //     rotate_rect_anim(rect3, -90, link1,f3, 'Z');
       //        sleep(1);
       //        moveC(rect2, 100, link1,f2);
       //        sleep(1);
       //        moveC(rect, 100, link1,f1);
       //     rotate_rect_anim(rect2, 90, link1,f2,'Y');
       //        sleep(1);
       moveC(hex, 100, link1,f2);
       rotate_rect_anim(hex,45.0,link1,f2,'Z');
       moveC(hex, 100, link1,f2);
       cout<<hex.getMidPoint()<<endl;
       getchar();
}
