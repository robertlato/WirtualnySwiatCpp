/*
    Autor: Robert Latoszewski
    Indeks: 167866
    Data utworzenia: 12.12.2019

    Opis: 
        Symulator wirtualnego swiata, LAB OTWARTE JPO
        Zwierzeta: wilk, owca, lew, zmija, dzik
        Rosliny: trawa, guarana, ciern
*/


#include <iostream>

#include "WirtualnySwiat.h"


using namespace std;

void rysujMenu()
{
    cout << "Witualny swiat\n1. Wykonaj ture\n2. Zakoncz program\n\n\n";
}

int main()
{
    // TODO: dopracuj main

    cout << "Inicjuje wirtualny swiat...\n";
    WirtualnySwiat pierwszySwiat(20, 100);
    pierwszySwiat.rysujSwiat();
    char operacja = 0;
    rysujMenu();
    while (operacja != '2')
    {
        cin >> operacja;
        switch (operacja)
        {
            case '1':
                system("clear"); // czyszczenie okna w clion nie dziala
                cout << "Wykonuje ture numer: " << pierwszySwiat.getTura() + 1 << endl;
                pierwszySwiat.wykonajTure();
                pierwszySwiat.rysujSwiat();
                rysujMenu();

                break;

            case'2':
                // koncze program
                break;

            default:
                cout << "Zly input, sprobuj ponownie\n";
                cout << "operacja = " << operacja << endl;
                break;
        }
    }

    return 0;
}