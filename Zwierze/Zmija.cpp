//
// Created by Robert on 23.12.2019.
//

#include "Zmija.h"

Zmija::Zmija(int x, int y, WirtualnySwiat *swiat) {
    znak = 'Z';
    sila = 2;
    inicjatywa = 3;
    polozenie.x = x;
    polozenie.y = y;
    aktualnySwiat = swiat;
}

Zmija::~Zmija() = default;