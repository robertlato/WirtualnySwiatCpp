//
// Created by Robert on 23.12.2019.
//

#include "Wilk.h"

Wilk::Wilk(int x, int y, WirtualnySwiat *swiat) {
    znak = 'W';
    sila = 9;
    inicjatywa = 5;
    polozenie.x = x;
    polozenie.y = y;
    aktualnySwiat = swiat;

}

Wilk::~Wilk() = default;;