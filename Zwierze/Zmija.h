//
// Created by Robert on 23.12.2019.
//

#ifndef WIRTUALNY_SWIAT_ZMIJA_H
#define WIRTUALNY_SWIAT_ZMIJA_H


#include "Zwierze.h"
#include "../WirtualnySwiat.h"

class Zmija : public Zwierze {
public:

    Zmija(int x, int y, WirtualnySwiat *swiat);

    ~Zmija();

    std::string getNazwa()
    {
        return ("Zmija");
    }

    void kolizja(int nowyX, int nowyY) override;
};


#endif //WIRTUALNY_SWIAT_ZMIJA_H
