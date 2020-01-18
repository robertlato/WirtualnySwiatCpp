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
        kolizja(nowyX, nowyY, aktualnySwiat->getOrganizm(nowyX, nowyY)); // nowe pole jest zajete
}

void Zwierze::kolizja(int nowyX, int nowyY, Organizm* przeciwnik)
{
//    if(przeciwnik->getNazwa() == "Lew" &&
//            sila < 5)
//    {
//        return;
//    }
    if (przeciwnik->getNazwa() == "Lew" && getSila() < 5) return;
    else if (przeciwnik->getNazwa() == "Guarana")
    {
        przeciwnik->kolizja(nowyX, nowyY, this);
    }
//    else if (aktualnySwiat->getOrganizm(nowyX, nowyY)->getNazwa() == "Guarana")
//    {
//        sila += 3;
//    }
//    else if (przeciwnik->getNazwa() == "Guarana")
//    {
//        przeciwnik->kolizja(polozenie.x, polozenie.y, this);
//    }
    else
    {

        // ROZMNAZANIE
         if (getNazwa() == przeciwnik->getNazwa())
        {
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
        //ATAKUJACY WYGRYWA
        else if (this->sila >= przeciwnik->getSila())
        {
            std:: cout << getNazwa() << " [" << polozenie.x << "]["
                << polozenie.y << "] wygrywa pojedynek z "
                << przeciwnik->getNazwa()
                << " [" << przeciwnik->getPolozenieX()
                << "][" << przeciwnik->getPolozenieY()
                <<"]. Pole wygranego to: [" << nowyX << "][" << nowyY << "]\n";

//            if (polozenie.x != nowyX || polozenie.y != nowyY) // wygrany nie byl organizmem broniacym sie
//            {
//                aktualnySwiat->setOrganizm(polozenie.x, polozenie.y, this, nowyX, nowyY);
//                polozenie.x = nowyX;
//                polozenie.y = nowyY;
//            } else
//                aktualnySwiat->usunOrganizm(przeciwnik->getPolozenieX(), przeciwnik->getPolozenieY(), przeciwnik);

                aktualnySwiat->setOrganizm(polozenie.x, polozenie.y, this, nowyX, nowyY);
                polozenie.x = nowyX;
                polozenie.y = nowyY;

        }
        // ATAKUJACY PRZEGRYWA
         else
        {
            std:: cout << getNazwa() << " [" << polozenie.x << "]["
                       << polozenie.y << "] przegrywa pojedynek z "
                       << przeciwnik->getNazwa()
                       << " [" << przeciwnik->getPolozenieX() << "]["
                       << przeciwnik->getPolozenieY() <<"],  i zwalnia swoje pole. ";

            aktualnySwiat->usunOrganizm(polozenie.x, polozenie.y, this);

//            if (polozenie.x == nowyX && polozenie.y == nowyY) // wygrany byl organizmem wykonujacym ruch
//            {
//                // wygrany zajmuje pole przegranego
//                aktualnySwiat->setOrganizm(przeciwnik->getPolozenieX(), przeciwnik->getPolozenieY(), przeciwnik, nowyX, nowyY);
//                przeciwnik->setPolozenieX(nowyX);
//                przeciwnik->setPolozenieY(nowyY);
//            }
            std::cout << "Pole wygranego to: [" << przeciwnik->getPolozenieX() << "]["
                << przeciwnik->getPolozenieY() << "]\n";
        }
    }
}