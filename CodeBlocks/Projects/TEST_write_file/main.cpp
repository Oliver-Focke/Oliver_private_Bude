#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

int main()                            // Most important part of the program!
{
  int age;                            // Need a variable
  int i = 1;                          // Counter Programmdurchl�ufe = 1
  int i_soll = 2;                     // Anzahl der Durchl�ufe

  char32_t dat_name;
  char32_t dat_name_test;

  time_t Zeitstempel;                    //Variablen f�r die Zeit f�llen
    tm *nun;
    Zeitstempel = time(0);
    nun = localtime(&Zeitstempel);

  int akt_year = nun->tm_year+1900;          //aktuelles Jahr errechnen
  int akt_month = nun->tm_mon +1;
  int akt_day = nun->tm_mday;
  int akt_hour = nun->tm_hour ;
  int akt_minute = nun->tm_min;

  //dat_name = "20181217-1130.txt";                            //akt_year-akt_month-akt_day-akt_hour-akt_minute.dat;
  //dat_name_test = "akt_year-akt_month-akt_day-akt_hour-akt_minute.dat";

  int Tamina_GJahr = 2009;                   // Geburtsjahr declarieren -> soll sp�ter in eine SQL Datenbank
  int Laura_GJahr = 2008;
  int Viktoria_GJahr = 2002;
  int Yvonne_GJahr = 1974;
  int Oliver_GJahr =1970;

  int Tamina_Alter = akt_year - Tamina_GJahr;      // wir haben eine Geburtstagsliste
  int Laura_Alter = akt_year - Laura_GJahr;
  int Viktoria_Alter = akt_year - Viktoria_GJahr;
  int Yvonne_Alter = akt_year - Yvonne_GJahr;
  int Oliver_Alter = akt_year - Oliver_GJahr;

  // Filehandlin definieren
  fstream f;
    f.open("z_test.dat", ios::app);
    f << "Start des Programms Datei" << akt_year << akt_month << akt_day << akt_hour << akt_minute << endl;




  cout << "Das aktuelle Jahr ist        : " << akt_year << "\n";                     //aktuelles Jahr anzeigen
  cout << "Der aktuelle Monat ist       :   " << akt_month << "\n";
  cout << "Der aktuelle Tag ist         :   " << akt_day << "\n";
  cout << "Die aktuelle Stunde ist      :   " << akt_hour << "\n";
  cout << "Die aktuelle Minute ist      :   " << akt_minute << "\n";

  cout << "Der aktuelle Dateiname ist   :   " << dat_name << "\n";
  cout << "Der aktuelle Dateiname (TEST) ist   :   " << dat_name_test << "\n";

  cout << "\n Liste der Geburtsjahre: \n";
  cout << "Taminas   Geburtsjahr ist: " << Tamina_GJahr << "\n";                     //Taminas Geburtsjahr anzeigen
  cout << "Lauras    Geburtsjahr ist: " << Laura_GJahr << "\n";                     //Lauras Geburtsjahr anzeigen
  cout << "Viktorias Geburtsjahr ist: " << Viktoria_GJahr << "\n";                     //Viktorias Geburtsjahr anzeigen
  cout << "Yvonnes   Geburtsjahr ist: " << Yvonne_GJahr << "\n";                     //Yvonnes Geburtsjahr anzeigen
  cout << "Olivers   Geburtsjahr ist: " << Oliver_GJahr << "\n";                     //Olivers Geburtsjahr anzeigen

  cout << "\n Altersliste der Familie: \n";
  cout << "Taminas   Alter ist : " << Tamina_Alter << "\n";                     //Taminas Alter anzeigen
  cout << "Laura     w�re jetzt: " << Laura_Alter << "\n";                     //Lauras Alter anzeigen
  cout << "Viktorias Alter ist : " << Viktoria_Alter << "\n";                     //Viktorias Alter anzeigen
  cout << "Yvonnes   Alter ist : " << Yvonne_Alter << "\n";                     //Yvonnes Alter anzeigen
  cout << "Olivers   Alter ist : " << Oliver_Alter << "\n";                     //Olivers Alter anzeigen

  cout << "\n Sonstige Paramaeter: " << "\n";                     //aktuelles Jahr anzeigen
  cout << "Zeitstempel : " << Zeitstempel << "\n";
  cout << "NUN         : " << nun << "\n";
  cout << "LOCALTIME   : " << localtime << "\n";
  // cout << "NUN         : " << nun << "\n";
  // cout << "TM         : " << tm << "\n";
  cout << "\n \n";

  while (i <= i_soll)  {                            // Do it 10 times



  cout << "Du bist im " << i << " Durchlauf des Programs von" << i_soll << "\n"
   <<"    Please input your age: ";                                       // Asks for age
  cin>> age;                                                              // The input is put in age

   f << "dies ist der " << i << " Durchlauf von " << i_soll << " Durchl�ufen." << endl;

  i++;                                                                    //increase counter

  cin.ignore();
                                  // Throw away enter
  if ( age < 30 ) {                  // If the age is less than 100
     cout<<"You are pretty young!\n"; // Just to show you it works...
  }
  else if ( age < 40 ) {            // I use else just to show an example
     cout<<"You are between 30 and 40\n";           // Just to show you it works...
  }
  else if ( age < 50 ) {            // I use else just to show an example
     cout<<"You are between 40 and 50\n";           // Just to show you it works...
  }
  else if ( age < 60 ) {            // I use else just to show an example
     cout<<"You are between 50 and 60\n";           // Just to show you it works...
  }
  else if ( age < 70 ) {            // I use else just to show an example
     cout<<"You are between 60 and 70\n";           // Just to show you it works...
  }
  else if ( age == 70 ) {            // I use else just to show an example
     cout<<"You are excatly 70\n";           // Just to show you it works...
  }
  else if ( age < 80 ) {            // I use else just to show an example
     cout<<"You are between 70 and 80\n";           // Just to show you it works...
  }
  else if ( age < 90 ) {            // I use else just to show an example
     cout<<"You are between 80 and 90\n";           // Just to show you it works...
  }
  else if ( age < 100 ) {            // I use else just to show an example
     cout<<"You are between 90 and 100\n";           // Just to show you it works...
  }
  else {
    cout<<"You are really old\n";     // Executed if no other statement is
  }
  // cout<<"You are exactly \n\n" << age << "\n\n years old\n";

  // Treffer in der Familien Geburtstagsliste
  f << "Du bist genau " << age << " Jahre alt." << endl;


   if ( age == Tamina_Alter ) {            // I use else just to show an example
     cout<<"Du bist genauso alt wie Tamina Kr�ger\n";           // Just to show you it works...
     f << "Du bist genauso alt wie Tamina Kr�ger" << endl;
  }
    else if ( age == Laura_Alter ) {            // I use else just to show an example
     cout<<"Du bist genauso alt wie Laura Kr�ger jetzt w�re. \n";           // Just to show you it works...
     f << "Du bist genauso alt wie Laura Kr�ger jetzt w�re." << endl;
  }
    else if ( age == Viktoria_Alter ) {            // I use else just to show an example
     cout<<"Du bist genauso alt wie Viktoria Kr�ger\n";           // Just to show you it works...
     f << "Du bist genauso alt wie Viktoria Kr�ger" << endl;
  }
    else if ( age == Yvonne_Alter )   {            // I use else just to show an example
     cout<<"Du bist genauso alt wie Yvonne Kr�ger\n";           // Just to show you it works...
     f << "Du bist genauso alt wie Yvonne Kr�ger" << endl;
  }
    else if ( age == Oliver_Alter ) {            // I use else just to show an example
     cout<<"Du bist genauso alt wie Oliver Kr�ger\n";           // Just to show you it works...
     f << "Du bist genauso alt wie Oliver Kr�ger" << endl;
  }
  cin.get();
}
f << "Stop des Programms Datei" << akt_year << akt_month << akt_day << akt_hour << akt_minute << endl;
f.close();
}