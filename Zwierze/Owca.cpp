//
// Created by Robert on 23.12.2019.
//

#include "Owca.h"

Owca::Owca(int x, int y, WirtualnySwiat *swiat) {
    znak = 'O';
    sila = 4;
    inicjatywa = 4;
    polozenie.x = x;
    polozenie.y = y;
    aktualnySwiat = swiat;
}

Owca::~Owca() = default;
