//
// Created by Robert on 18.12.2019.
//

#ifndef WIRTUALNY_SWIAT_ZWIERZE_H
#define WIRTUALNY_SWIAT_ZWIERZE_H


#include "../Organizm.h"

class Zwierze : public Organizm {
public:
    void akcja() override;

    void kolizja(int nowyX, int nowyY, Organizm* przeciwnik) override;

    virtual ~Zwierze(){}


};


#endif //WIRTUALNY_SWIAT_ZWIERZE_H
