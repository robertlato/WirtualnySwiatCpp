//
// Created by Robert on 18.12.2019.
//

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Zwierze.h"
#include "../WirtualnySwiat.h"


void Zwierze::akcja()
{
    //srand(time(0));

    // losuje nowyX i nowyY:
     // edytuj dla zadanego rozmiaru planszy
    int nowyX = 21;
    int nowyY = 21;
    while (nowyX > 20 || nowyY > 20)
    {
        nowyX = abs((rand() % 3) + (polozenie.x - 1)); // do zmiany
        nowyY = abs((rand() % 3) + (polozenie.y - 1)); // do zmiany
    }
    std::cout << "Aktualny x i y: " << polozenie.x << " " << polozenie.y << std::endl;
    std::cout << "Nowy x i y: " << nowyX << " " << nowyY << std::endl;

    if (aktualnySwiat->getOrganizm(nowyX, nowyY) == nullptr) // nowe pole jest wolne
    {
        aktualnySwiat->setOrganizm(polozenie.x, polozenie.y, this, nowyX, nowyY);
    }
    else
        kolizja(nowyX, nowyY); // nowe pole jest zajete
}

void Zwierze::kolizja(int nowyX, int nowyY)
{
    if (this->sila >= aktualnySwiat->getOrganizm(nowyX, nowyY)->getSila())
    {
        std::cout << "Atakujacy wygrywa i zajmuje pole broniacego\n";
        aktualnySwiat->setOrganizm(polozenie.x, polozenie.y, this, nowyX, nowyY);
    }
    else
    {
        std::cout << "Atakujacy przegrywa i zwalnia pole\n";
        aktualnySwiat->setOrganizm(polozenie.x, polozenie.y, this); // setting nullptr
        aktualnySwiat->usunOrganizm(this);
    }
}