//
// Created by Robert on 18.12.2019.
//
#include <iostream>
#include "Guarana.h"


Guarana::Guarana(int x, int y, WirtualnySwiat *swiat) {
    znak = 'G';
    sila = 0;
    inicjatywa = 0;
    polozenie.x = x;
    polozenie.y = y;
    aktualnySwiat = swiat;

}

void Guarana::kolizja(int nowyX, int nowyY, Organizm *przeciwnik)
{
    std::cout << przeciwnik->getNazwa() << " [" << przeciwnik->getPolozenieX()
        << "][" << przeciwnik->getPolozenieY() << "] zjada Guarane ["
        << polozenie.x << "][" << polozenie.y << "], zajmuje jej pole i otrzymuje +3 do sily.\n";
    przeciwnik->increaseSila(3);
    aktualnySwiat->setOrganizm(przeciwnik->getPolozenieX(), przeciwnik->getPolozenieY(), przeciwnik, nowyX, nowyY);
    przeciwnik->setPolozenieX(nowyX);
    przeciwnik->setPolozenieY(nowyY);

    // Roslina::kolizja(nowyX, nowyY, przeciwnik);
}

Guarana::~Guarana() = default;
