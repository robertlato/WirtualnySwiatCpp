//
// Created by Robert on 18.12.2019.
//

#include "Trawa.h"


Trawa::Trawa(int x, int y, WirtualnySwiat *swiat) {
    znak = 'T';
    sila = 0;
    inicjatywa = 0;
    polozenie.x = x;
    polozenie.y = y;
    aktualnySwiat = swiat;

}

Trawa::~Trawa() = default;