#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include<unistd.h>

#include "gnuplot_link.hpp"
#include "vector2d.hpp"
#include "matrix2x2.hpp"
#include "rectangle.hpp"

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
void WriteToStreamExample(Rectangle rect, ostream &output_stream)
{
       //---------------------------------------------------------------
       // To tylko przyklad !!!
       // W programie nalezy uzywać pojęcia wektora, a nie oddzielnych
       // zmiennych do reprezentowania wspolrzednych!
       //
       //   double  x1, y1, x2, y2, x3, y3, x4, y4;

       //   x1 = y1 = 10;
       //   x2 = x1 + kLongerEdgesLength;  y2 = y1;
       //   x3 = x2;  y3 = y2 + kShorterEdgesLength;
       //   x4 = x3 - kLongerEdgesLength; y4 = y3;

       //   output_stream << setw(16) << fixed << setprecision(10) << x1+offset
       //          << setw(16) << fixed << setprecision(10) << y1+offset << endl;
       //   output_stream << setw(16) << fixed << setprecision(10) << x2+offset
       //          << setw(16) << fixed << setprecision(10) << y2+offset << endl;
       //   output_stream << setw(16) << fixed << setprecision(10) << x3+offset
       //          << setw(16) << fixed << setprecision(10) << y3+offset << endl;
       //   output_stream << setw(16) << fixed << setprecision(10) << x4+offset
       //          << setw(16) << fixed << setprecision(10) << y4+offset << endl;
       //   output_stream << setw(16) << fixed << setprecision(10) << x1+offset
       //          << setw(16) << fixed << setprecision(10) << y1+offset << endl;
       output_stream << rect << rect.getCorner(0);
       // Jeszcze raz zapisujemy pierwszy punkt,
       // aby gnuplot narysowal zamkniętą linię.
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
bool WriteToFileExample(Rectangle rect, string filename)
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
void rotate_rect_anim(Rectangle &rect, double angle,PzG::GnuplotLink link)
{
       cout<<"siema!!!!!!!!!\n\n";
       Rectangle tmpRect;
       tmpRect=rect;
       if (angle>=0.0)
              for(int i=0; i<=int(angle);++i)
                     {
            {  cout<<"siema 1 !!!!!!!!!\n\n";
                     tmpRect.rotateRectangle(1.0);
                     WriteToStreamExample(tmpRect, cout);
                     usleep(10000);
                     if (!WriteToFileExample(tmpRect, "data/prostokat.dat"))
                            break;
                     usleep(10000);

                     link.Draw();
                     cout<<1<<endl;
                     }
                     }
       else  {
              for(int i=angle; i <= 0;++i)
                     {
                     tmpRect.rotateRectangle(-1.0);
                     WriteToStreamExample(tmpRect, cout);
                     usleep(10000);
                     if (!WriteToFileExample(tmpRect, "data/prostokat.dat"))
                            break;
                     usleep(10000);

                     link.Draw();
                     cout<<1<<endl;
                     }
                     }
       usleep(10000);
       rect.rotateRectangle(angle);
                     WriteToStreamExample(rect, cout);
                     usleep(10000);
                     if (!WriteToFileExample(rect, "data/prostokat.dat"))
                            cout<<"!!!!!!!!!!!!!\n";
                     usleep(10000);

                     link.Draw();
                     cout<<1<<endl;
                     usleep(10000);
}
int main()
{

       double a = 50.0;
       Rectangle rect(-a, 5 * a, 2 * a, 5 * a); // To tylko przykladowe definicje zmiennej
       PzG::GnuplotLink link;                   // Ta zmienna jest potrzebna do wizualizacji
                                                // rysunku prostokata

       //-------------------------------------------------------
       //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
       //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
       //  na dwa sposoby:
       //   1. Rysowane jako linia ciagl o grubosci 2 piksele
       //
       link.AddFilename("data/prostokat.dat", PzG::LS_CONTINUOUS, 2);
       //
       //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
       //      których połowa długości boku wynosi 2.
       //
       link.AddFilename("data/prostokat.dat", PzG::LS_SCATTERED, 2);
       //
       //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
       //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
       //  jako wspolrzedne punktow podajemy tylko x,y.
       //
       link.SetDrawingMode(PzG::DM_2D);
       WriteToStreamExample(rect, cout);
       if (!WriteToFileExample(rect, "data/prostokat.dat"))
              return 1;
       link.Draw();
       sleep(2);
       rotate_rect_anim(rect,a,link);
       rotate_rect_anim(rect,-2*a,link);

       getchar();
}

void test()
{
     
       Vector2d vec1(2.0, 2.0), vec2(1.0, 1.0);
       Rectangle rect(0.0, 0.0, 3.0, 5.0), rect2(0.0, 0.0, 4.0, 6.0);
       std::cout << vec1 << "\n"
                 << vec2 << "\n"
                 << rect << std::endl;
       rect.moveRectangle(vec2);
       std::cout << rect << std::endl;
       rect += vec1;
       std::cout << rect << std::endl;
       std::cout << "----------------------------\n";
       std::cout << rect2 << std::endl;
       rect2.rotateRectangle(90.0);
       std::cout << rect2 << std::endl;
}




/**
 * 
 * 
 * 
 * 
 *        WriteToStreamExample(rect, cout);
       if (!WriteToFileExample(rect, "data/prostokat.dat"))
              return 1;
       link.Draw(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
       cout << "Naciśnij ENTER, aby kontynuowac" << endl;
       cin.ignore(100000, '\n');

       //----------------------------------------------------------
       // Ponownie wypisuje wspolrzedne i rysuje prostokąt w innym miejscu.
       //
       rect.rotateRectangle(-45);
       WriteToStreamExample(rect, cout);
       if (!WriteToFileExample(rect, "data/prostokat.dat"))
              return 1;
       link.Draw(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
       getchar();

       Vector2d vec(50,130);
       rect.moveRectangle(vec);
       WriteToStreamExample(rect, cout);
       if (!WriteToFileExample(rect, "data/prostokat.dat"))
              return 1;
       link.Draw(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
*/