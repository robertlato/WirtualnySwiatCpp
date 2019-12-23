//
// Created by Robert on 23.12.2019.
//

#include "Lew.h"

Lew::Lew(int x, int y, WirtualnySwiat *swiat) {
    znak = 'L';
    sila = 11;
    inicjatywa = 7;
    polozenie.x = x;
    polozenie.y = y;
    aktualnySwiat = swiat;
}

Lew::~Lew() = default;