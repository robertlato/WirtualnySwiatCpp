//
// Created by Robert on 18.12.2019.
//

#ifndef WIRTUALNY_SWIAT_ROSLINA_H
#define WIRTUALNY_SWIAT_ROSLINA_H


#include "../Organizm.h"

class Roslina : public Organizm {
public:
// TODO: implementacja rozprzestrzenainia sie roslin w metodzie akcja()
    void akcja() override;

    void kolizja(int nowyX, int nowyY, Organizm* przeciwnik) override{}


    virtual ~Roslina(){}


};


#endif //WIRTUALNY_SWIAT_ROSLINA_H
