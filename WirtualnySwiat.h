//
// Created by Robert on 18.12.2019.
//

#ifndef WIRTUALNY_SWIAT_WIRTUALNYSWIAT_H
#define WIRTUALNY_SWIAT_WIRTUALNYSWIAT_H

#include <vector>

#include "Organizm.h"



class WirtualnySwiat {
    Organizm*** organizmy;
    int iloscOrganizmow;
    std::vector <Organizm*> kolejnoscOrganizmow;
    int tura = 0;
    int rozmiar;

public:

    WirtualnySwiat(int rozmiar = 20, int iloscOrganizmow = 20);

    ~WirtualnySwiat();

    void wykonajTure();

    void rysujSwiat();

    Organizm* getOrganizm(int x, int y)
    {
        return organizmy[x][y];
    }

    int getRozmiar()
    {
        return rozmiar;
    }

    void setOrganizm(int x, int y, Organizm* organizm, int nowyX, int nowyY);
//    void setOrganizm(int x, int y, Organizm* organizm)
//    {
//        organizmy[x][y] = nullptr;
//    }

    void usunOrganizm(int x, int y, Organizm* organizm)
    {
        organizmy[x][y] = nullptr;
        delete organizm;
    }

};


#endif //WIRTUALNY_SWIAT_WIRTUALNYSWIAT_H
