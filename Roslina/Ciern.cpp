//
// Created by Robert on 18.12.2019.
//

#include "Ciern.h"


Ciern::Ciern(int x, int y, WirtualnySwiat *swiat) {
    znak = 'C';
    sila = 2;
    inicjatywa = 0;
    polozenie.x = x;
    polozenie.y = y;
    aktualnySwiat = swiat;

}

Ciern::~Ciern() = default;
