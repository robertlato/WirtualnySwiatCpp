//
// Created by Robert on 23.12.2019.
//

#include <iostream>
#include "Zmija.h"

Zmija::Zmija(int x, int y, WirtualnySwiat *swiat) {
    znak = 'Z';
    sila = 2;
    inicjatywa = 3;
    polozenie.x = x;
    polozenie.y = y;
    aktualnySwiat = swiat;

}

void Zmija::kolizja(int nowyX, int nowyY, Organizm* przeciwnik)
{
    Zwierze::kolizja(nowyX, nowyY, przeciwnik);
    if (this->getDoUsuniecia()) // zmija przegrala pojedynek z przeciwnikiem
    {
        aktualnySwiat->usunOrganizm(nowyX, nowyY, przeciwnik);
        //std::cout << "\nOrganizm umiera w wyniku zatrucia przez zmije\n";
        std::cout << przeciwnik->getNazwa() << " [" << przeciwnik->getPolozenieX()
            << "][" << przeciwnik->getPolozenieY() <<"] umiera w wyniku zatrucia przez zmije ["
            << polozenie.x << "][" << polozenie.y << "]\n";
    }

}


Zmija::~Zmija() = default;