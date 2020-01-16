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

void Zmija::kolizja(int nowyX, int nowyY)
{
    Zwierze::kolizja(nowyX, nowyY);
    if (this->getDoUsuniecia())
    {
        aktualnySwiat->usunOrganizm(nowyX, nowyY, aktualnySwiat->getOrganizm(nowyX, nowyY));
        std::cout << "\nAtakujacy organizm umiera w wyniku zatrucia przez zmije\n";
    }

}


Zmija::~Zmija() = default;