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
    // znajdz nowe wspolrzedne nie wychodzace poza zakres rozmiaruSwiata
    while (nowyX > rozmiarSwiata - 1 || nowyY > rozmiarSwiata - 1)
    {
        // rand() % 3 + n daje nam 3 wartosci: n-1, n, n+1
        nowyX = abs((rand() % 3) + (polozenie.x - 1));
        nowyY = abs((rand() % 3) + (polozenie.y - 1));
    }
//    std::cout << "Aktualny x i y: " << polozenie.x << " " << polozenie.y
//                << ", znak: " << getZnak() << std::endl;
//    std::cout << "Nowy x i y: " << nowyX << " " << nowyY << std::endl;

    if (aktualnySwiat->getOrganizm(nowyX, nowyY) == nullptr) // nowe pole jest wolne
    {
        aktualnySwiat->setOrganizm(polozenie.x, polozenie.y, this, nowyX, nowyY);
        polozenie.x = nowyX;
        polozenie.y = nowyY;
        //this->setPolozenie(nowyX, nowyY); // zapisuje zmiane polozenia w polach organizmu
    }
    else if (nowyX == polozenie.x && nowyY == polozenie.y){} // organizm nie ruszyl sie w tej turze
    else
        kolizja(nowyX, nowyY); // nowe pole jest zajete
}

void Zwierze::kolizja(int nowyX, int nowyY)
{
    // rozmnazanie
     if (getNazwa() == aktualnySwiat->getOrganizm(nowyX, nowyY)->getNazwa())
    {
//
//        int rozmiarSwiata = aktualnySwiat->getRozmiar();
//        int nowyX = rozmiarSwiata;
//        int nowyY = rozmiarSwiata;
//        while (aktualnySwiat->zajetoscPola(nowyX, nowyY))
//        {
//            while (nowyX > rozmiarSwiata - 1 || nowyY > rozmiarSwiata - 1)
//            {
//                // rand() % 3 + n daje nam 3 wartosci: n-1, n, n+1
//                nowyX = abs((rand() % 3) + (polozenie.x - 1));
//                nowyY = abs((rand() % 3) + (polozenie.y - 1));
//            }
//        }
        // sprawdz po kolei zajetosc pol, nowy organizm przypisz do pierwszego wolnego pola
        bool gotowe = false;
        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                if (!aktualnySwiat->zajetoscPola(polozenie.x + i, polozenie.y + j))
                {
                    aktualnySwiat->createOrganizm(polozenie.x + i, polozenie.y + j, getZnak());
                    gotowe = true;
                    break;
                }
                else if(!aktualnySwiat->zajetoscPola(aktualnySwiat->getOrganizm(nowyX, nowyY)->getPolozenieX() + i,
                    aktualnySwiat->getOrganizm(nowyX, nowyY)->getPolozenieY() + j))
                {
                    aktualnySwiat->createOrganizm(aktualnySwiat->getOrganizm(nowyX, nowyY)->getPolozenieX() + i,
                                                    aktualnySwiat->getOrganizm(nowyX, nowyY)->getPolozenieY() + j,
                                                    getZnak());
                    gotowe = true;
                    break;
                }
            }
            if (gotowe) break;
        }


        // wybierz nowe, niezajete pole
        // stworz nowy organizm
    }
    //atakujacy wygrywa
    else if (this->sila >= aktualnySwiat->getOrganizm(nowyX, nowyY)->getSila())
    {
        std:: cout << getNazwa() << " z pola [" << polozenie.x << "]["
            << polozenie.y << "] wygrywa pojedynek z "
            << aktualnySwiat->getOrganizm(nowyX, nowyY)->getNazwa()
            << " [" << nowyX << "][" << nowyY <<"] i zajmuje jego pole\n";

        aktualnySwiat->setOrganizm(polozenie.x, polozenie.y, this, nowyX, nowyY);
        polozenie.x = nowyX;
        polozenie.y = nowyY;
    }
    // atakujacy przegrywa
     else
    {
        std:: cout << getNazwa() << " [" << polozenie.x << "]["
                   << polozenie.y << "] atakuje "
                   << aktualnySwiat->getOrganizm(nowyX, nowyY)->getNazwa()
                   << " [" << nowyX << "][" << nowyY <<"], przegrywa i zwalnia swoje pole\n";

        aktualnySwiat->usunOrganizm(polozenie.x, polozenie.y, this);
    }
}