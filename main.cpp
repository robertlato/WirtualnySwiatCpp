/*
    Autor: Robert Latoszewski
    Indeks: 167866
    Data utworzenia: 12.12.2019

    Opis: 
        Symulator wirtualnego swiata, LAB OTWARTE JPO
*/


#include <iostream>

#include "WirtualnySwiat.h"

#include "Roslina/Ciern.h"
#include "Roslina/Guarana.h"
#include "Roslina/Trawa.h"

#include "Zwierze/Dzik.h"
#include "Zwierze/Lew.h"
#include "Zwierze/Owca.h"
#include "Zwierze/Wilk.h"
#include "Zwierze/Zmija.h"


using namespace std;

int main()
{
    WirtualnySwiat pierwszySwiat;
    pierwszySwiat.rysujSwiat();
    return 0;
}