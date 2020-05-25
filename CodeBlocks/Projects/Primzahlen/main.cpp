#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

int main()
{
    const long MAXPRIMZAHL=1000000000;
    long primzahl, divisor;
    bool istEinePrimzahl;

    primzahl = 31324399;


    time_t Zeitstempel;                    //Variablen f�r die Zeit f�llen
    tm *nun;
    Zeitstempel = time(0);
    nun = localtime(&Zeitstempel);

    int akt_year = nun->tm_year+1900;          //aktuelles Jahr errechnen
    int akt_month = nun->tm_mon +1;
    int akt_day = nun->tm_mday;
    int akt_hour = nun->tm_hour ;
    int akt_minute = nun->tm_min;

    fstream f;
    f.open("KRU_Primzahlen_Protokoll.dat", ios::app);
    f << "Start des Programms Datei " << akt_year << akt_month << akt_day << akt_hour << akt_minute << endl;
    f << "Startprimzahl : " << primzahl << endl;

    for (; primzahl<=MAXPRIMZAHL; primzahl++)
    {
        istEinePrimzahl = true;
        // Pruefe, ob primzahl wirklich eine Primzahl ist.
        for (divisor=2; istEinePrimzahl && divisor<primzahl; divisor++)
        {
            // Ist das restlos teilbar?
            if (0==primzahl % divisor)
            {
                // Zahl ist teilbar, ist also keine Primzahl!
                istEinePrimzahl = false;
            }
        }
        // Pruefung ist beendet.
        // Wenn es eine Primzahl ist, ausgeben!
        if (istEinePrimzahl)
        {
            cout << ", " << primzahl;
            f << "Es ist eine Primzahl : " << primzahl << endl;
        }
    }
    cout << endl;
    f << "Primzahl am Ende : " << primzahl << endl;
    f << "Stop  des Programms Datei " << akt_year << akt_month << akt_day << akt_hour << akt_minute << endl;
    f.close();
}

