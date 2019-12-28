/*
    Autor: Robert Latoszewski
    Indeks: 167866
    Data utworzenia: 12.12.2019

    Opis: 
        Symulator wirtualnego swiata, LAB OTWARTE JPO
*/


#include <iostream>

#include "WirtualnySwiat.h"

//#include "Roslina/Ciern.h"
//#include "Roslina/Guarana.h"
//#include "Roslina/Trawa.h"
//
//#include "Zwierze/Dzik.h"
//#include "Zwierze/Lew.h"
//#include "Zwierze/Owca.h"
//#include "Zwierze/Wilk.h"
//#include "Zwierze/Zmija.h"


using namespace std;

void rysujMenu()
{
    cout << "Witualny swiat\n1. Wykonaj ture\n2. Zakoncz program\n\n\n";
}

int main()
{
    // TODO: dopracuj main

    cout << "Inicjuje wirtualny swiat...\n";
    WirtualnySwiat pierwszySwiat;
    pierwszySwiat.rysujSwiat();
    char operacja = 0;
    rysujMenu();
    while (operacja != '2')
    {
//        operacja = getchar();
        cin >> operacja;
        switch (operacja)
        {
            case '1':
                //system("clear");
                cout << "Wykonuje ture numer: " << pierwszySwiat.tura + 1 << endl;
                pierwszySwiat.wykonajTure();
                pierwszySwiat.rysujSwiat();
                rysujMenu();

                break;

            case'2':
                break;

            default:
                cout << "Zly input, sprobuj ponownie\n";
                cout << "operacja = " << operacja << endl;
                break;
        }
    }
//    WirtualnySwiat pierwszySwiat;
//    pierwszySwiat.rysujSwiat();
//    pierwszySwiat.wykonajTure();
//    pierwszySwiat.rysujSwiat();
//    cout << "Koncze program\n";


    return 0;
}