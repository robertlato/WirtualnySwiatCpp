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

int main()
{
    // TODO: dopracuj main

    cout << "Inicjuje wirtualny swiat...\n";
    WirtualnySwiat pierwszySwiat;
    pierwszySwiat.rysujSwiat();
    char operacja = 0;
    while (operacja != '2')
    {
        system("clear");
        cout << "Witualny swiat\n1. Wykonaj ture\n2. Zakoncz program\n";
        operacja = getchar();
        switch (operacja)
        {
            case '1':
                pierwszySwiat.wykonajTure();
                pierwszySwiat.rysujSwiat();

                break;

            case'2':
                break;

            default:
                cout << "Zly input, sprobuj ponownie\n";
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