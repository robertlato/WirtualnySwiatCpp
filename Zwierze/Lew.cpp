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

//void Lew::kolizja(int nowyX, int nowyY, Organizm *przeciwnik)
//{
//    if(przeciwnik->getSila() < 5) return;
//    else Zwierze::kolizja(nowyX, nowyY, przeciwnik);
//}

Lew::~Lew() = default;