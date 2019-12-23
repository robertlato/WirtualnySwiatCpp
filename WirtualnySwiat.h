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

    //void wykonajTure();

    void rysujSwiat();

};


#endif //WIRTUALNY_SWIAT_WIRTUALNYSWIAT_H
