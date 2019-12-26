//
// Created by Robert on 18.12.2019.
//

#include "Guarana.h"


Guarana::Guarana(int x, int y, WirtualnySwiat *swiat) {
    znak = 'G';
    sila = 0;
    inicjatywa = 0;
    polozenie.y = y;
    aktualnySwiat = swiat;

}

Guarana::~Guarana() = default;
