//
// Created by Robert on 18.12.2019.
//

#include "Dzik.h"

Dzik::Dzik(int x, int y, WirtualnySwiat *swiat) {
    znak = 'D';
    sila = 8;
    inicjatywa = 6;
    polozenie.x = x;
    polozenie.y = y;
    aktualnySwiat = swiat;
}

Dzik::~Dzik() = default;