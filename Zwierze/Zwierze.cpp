//
// Created by Robert on 18.12.2019.
//

#include <cstdlib>
#include <ctime>

#include "Zwierze.h"
#include "../WirtualnySwiat.h"


void Zwierze::akcja()
{
    srand(time(0));
    int nowyX;
    int nowyY;
    nowyX = abs(rand() % (polozenie.x + 1) + (polozenie.x -1));
    nowyY = abs(rand() % (polozenie.y + 1) + (polozenie.y -1));

    if (aktualnySwiat->getOrganizm(nowyX, nowyY) == nullptr) // nowe pole jest wolne
    {
        aktualnySwiat->setOrganizm(polozenie.x, polozenie.y, this, nowyX, nowyY);
    }
    else
        this->kolizja(); // nowe pole jest zajete
}