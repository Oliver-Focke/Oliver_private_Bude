/****************************************************************************************
* Project:   Basal Metabolic Rate
* Function:  Das Programm soll den Metabolischen Grundumsatz berechnen
*
*
*            Speicherort : erst Datei sp�ter MySQL oder MariaDB
*            Datenbank   : Metabolic
*            Tables      : User, Werte, Ergebnisse
*
*
*
*****************************************************************************************
* $Author : Eskimo_SVD
* $Name   : Oliver Kr�ger, Pommernstr. 11, 29640 Snevern, Mobil: +49 160 91576995
*****************************************************************************************
*
* Copyright 2019 by kruegerSYS
*
* Erstentwicklung                :    28.02.2019
* Folgeprogrammierung            :    05.03.2019
* Folgeprogrammierung            :    06.03.2019
* Testcompile und Probelauf      :    14.08.2019
*
*****************************************************************************************/

#include <iostream>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;

int main()
{

 // Definition der Variablen
    time_t Zeitstempel;                    //Variablen f�r die Zeit f�llen
    tm *nun;
    Zeitstempel = time(0);
    nun = localtime(&Zeitstempel);

    int akt_year = nun->tm_year+1900;          //aktuelles Jahr errechnen
    int akt_month = nun->tm_mon +1;
    int akt_day = nun->tm_mday;
    int akt_hour = nun->tm_hour ;
    int akt_minute = nun->tm_min;

    string V_Namen;
    char V_Geschlecht = 0;
    long double V_Koerpergroesse , V_Gewicht , V_Alter;
    long double V_Grundumsatz, VV_Gewicht, VV_Koerpergroesse, VV_Alter, VV_Grundumsatz;
    string VV_Geschlecht;


// Schreiben des Startstempels in die Datei
    fstream f;
    f.open("KRU_Basal_Metabolic_Rate_Protokoll.dat", ios::app);
    f << "Start des Programms Basal_Metabolic_Rate " << akt_year << akt_month << akt_day << akt_hour << akt_minute << endl;


// Start der Eingaben
    cout << "V_NAMEN = " << V_Namen << endl;
    cout << "Geben Sie Ihren Namen ein : " ;
    cin >> V_Namen;
    cout << V_Namen;
    cout << endl;
    cin.ignore();

    cout << "Geben Sie Ihre K�rpergr��e (in cm) ein : " ;
    cin >> V_Koerpergroesse;
    cout << endl;

    cout << "Geben Sie Ihr Gewicht (in kg) ein : " ;
    cin >> V_Gewicht;
    cout << endl;

//    cout << "Sind Sie m�nnlich (J/N) : " ;
//    cin >> V_Maennlich;
//    cout << endl;
    cout<<"Geschlecht m oder w :"; cin>>V_Geschlecht;

    cout << "Wie alt sind Sie (in Jahren) : ";
    cin >> V_Alter;
    cout << endl;


// Darstellung der Eingaben

    cout << "Name                : " << V_Namen << endl;
    cout << "K�rpergr��e         : " << V_Koerpergroesse << endl;
    cout << "Gewicht             : " << V_Gewicht << endl;
    cout << "Geschlecht          : " << V_Geschlecht << endl;
    cout << "Alter               : " << V_Alter << endl;
    cout << "Geschlecht          : " << V_Geschlecht << endl;



// Frage nach Korrektheit


// Berechnung f�r das Geschlecht

/* M�nner Grundumsatz = 66,47 + (13,7 x V_Gewicht) + (5 x V_Koerpergroesse) - (6,8 x V_Alter)
* Frauen Grundumsatz = 655,1 + (9,6 x V_Gewicht) + (1,8 x V_Koerpergroesse) - (4,7 x V_Alter)
*/

// zum Testen
cout << V_Geschlecht << endl;

    if (V_Geschlecht == 'm')
        {


        VV_Geschlecht = "M�nnlich";
        VV_Gewicht =(13.7 * V_Gewicht);
        cout << VV_Gewicht << endl;
        VV_Koerpergroesse = 5*V_Koerpergroesse;
        cout << VV_Koerpergroesse<< endl;
        VV_Alter = (6.8 * V_Alter);
        cout << VV_Alter << endl;

        V_Grundumsatz = 66.47+ VV_Gewicht+VV_Koerpergroesse  -VV_Alter;
        VV_Grundumsatz = 66.47 + (13.7 *V_Gewicht) + (5*V_Koerpergroesse) - (6.8 * V_Alter);

        }
    else
        {
        VV_Geschlecht = "Weiblich";

        VV_Gewicht =(9.6 * V_Gewicht);
        cout << VV_Gewicht << endl;
        VV_Koerpergroesse = 1.8*V_Koerpergroesse;
        cout << VV_Koerpergroesse<< endl;
        VV_Alter = (4.7 * V_Alter);
        cout << VV_Alter << endl;

        V_Grundumsatz = 655.1+ VV_Gewicht+VV_Koerpergroesse  - VV_Alter;
        VV_Grundumsatz = 655.1 + (9.6 *V_Gewicht) + (1.8*V_Koerpergroesse) - (4.7 * V_Alter);
        }



// Ausgabe der Werte
    cout << "V_Geschlecht : " << V_Geschlecht << "VV_Geschlecht : " << VV_Geschlecht << endl;
    cout << "Grundumsatz (V_)        : " << V_Grundumsatz << endl;
    cout << "Grundumsatz (VV_)       : " << VV_Grundumsatz << endl;




// Schreiben der Werte in die Datei


    f << "Dies ist kein Test mehr!" << endl;
    f << "Name                  : " << V_Namen << endl;
    f << "K�rpergr��e           : " << V_Koerpergroesse << endl;
    f << "Gewicht               : " << V_Gewicht << endl;
//    f << "M�nnlich            : " << V_Maennlich << endl;
    f << "Alter                 : " << V_Alter << endl;
    f << "Geschlecht            : " << V_Geschlecht << endl;
    f << "---------------------------------------------------------------------------------" << endl;
    f << "VV_Gewicht            : " << VV_Gewicht << endl;
    f << "VV_Koerpergroesse     : " << VV_Koerpergroesse << endl;
    f << "VV_Alter              : " << VV_Alter << endl;
    f << "---------------------------------------------------------------------------------" << endl;
    f << "Grundumsatz  V_       : " << V_Grundumsatz << endl;
    f << "Grundumsatz  VV_      : " << VV_Grundumsatz << endl;
    f << "---------------------------------------------------------------------------------" << endl;



// Schreiben Schlussstempel
    cout << endl;
    f << "Basal_Metabolic_Rate am Ende ! "  << endl;
    f << "Stop  des Programms Basal_Metabolic_Rate " << akt_year << akt_month << akt_day << akt_hour << akt_minute << endl;
    f << "---------------------------------------------------------------------------------" << endl;
    f << "---------------------------------------------------------------------------------" << endl << endl;
    f.close();


    return 0;
}
