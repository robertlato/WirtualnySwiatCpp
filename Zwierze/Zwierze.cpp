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
     //  int nowyX = 21;
    //    int nowyY = 21;
    int rozmiarSwiata = aktualnySwiat->getRozmiar();
    int nowyX = rozmiarSwiata;
    int nowyY = rozmiarSwiata;
    while (nowyX > rozmiarSwiata - 1 || nowyY > rozmiarSwiata - 1)
    {
        nowyX = abs((rand() % 3) + (polozenie.x - 1));
        nowyY = abs((rand() % 3) + (polozenie.y - 1));
    }
    std::cout << "Aktualny x i y: " << polozenie.x << " " << polozenie.y
                << ", znak: " << getZnak() << std::endl;
    std::cout << "Nowy x i y: " << nowyX << " " << nowyY << std::endl;

    if (aktualnySwiat->getOrganizm(nowyX, nowyY) == nullptr) // nowe pole jest wolne
    {
        aktualnySwiat->setOrganizm(polozenie.x, polozenie.y, this, nowyX, nowyY);
    }
    else if (nowyX == polozenie.x && nowyY == polozenie.y){} // organizm nie ruszyl sie w tej turze
    else
        kolizja(nowyX, nowyY); // nowe pole jest zajete
}

void Zwierze::kolizja(int nowyX, int nowyY) // popraw walke i usuwanie organizmow?
{
    if (this->sila >= aktualnySwiat->getOrganizm(nowyX, nowyY)->getSila())
    {
        std:: cout << getNazwa() << " z pola [" << polozenie.y << "]["
            << polozenie.x << "] wygrywa pojedynek z "
            << aktualnySwiat->getOrganizm(nowyX, nowyY)->getNazwa()
            << " [" << nowyY << "][" << nowyX <<"] i zajmuje jego pole\n";

        aktualnySwiat->setOrganizm(polozenie.x, polozenie.y, this, nowyX, nowyY);
    }
    else
    {
        std::cout << "Atakujacy przegrywa i zwalnia pole\n";
        //aktualnySwiat->setOrganizm(polozenie.x, polozenie.y, this); // setting nullptr
        aktualnySwiat->usunOrganizm(polozenie.x, polozenie.y, this);
    }
}