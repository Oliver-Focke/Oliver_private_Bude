#include <iostream>
#include <time.h>
#include <fstream>              //

using namespace std;

int main()                            // Most important part of the program!
{
  int age;                            // Need a variable
  int i = 1;                          // Counter Programmdurchläufe = 1
  int i_soll = 15;                     // Anzahl der Durchläufe

  char32_t dat_name;
  char32_t dat_name_test;

  time_t Zeitstempel;                    //Variablen für die Zeit füllen
    tm *nun;
    Zeitstempel = time(0);
    nun = localtime(&Zeitstempel);

  int akt_year = nun->tm_year+1900;          //aktuelles Jahr errechnen
  int akt_month = nun->tm_mon +1;
  int akt_day = nun->tm_mday;
  int akt_hour = nun->tm_hour ;
  int akt_minute = nun->tm_min;

  fstream f;
    f.open("KRU_Association_Management_Protokoll.dat", ios::app);
    f << "Start des Programms Datei" << akt_year << akt_month << akt_day << akt_hour << akt_minute << endl;


 while (i <= i_soll)  {

     f << "dies ist der " << i << "Durchlauf von " << i_soll << " Durchläufen." << endl;
     cout << "Du bist im " << i << "Durchlauf des Programs von" << i_soll << "\n";
     i++;
 }


f << "Stop  des Programms Datei" << akt_year << akt_month << akt_day << akt_hour << akt_minute << endl;
f.close();
}

