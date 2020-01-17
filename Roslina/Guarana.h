//
// Created by Robert on 18.12.2019.
//

#ifndef WIRTUALNY_SWIAT_GUARANA_H
#define WIRTUALNY_SWIAT_GUARANA_H


#include "Roslina.h"
#include "../WirtualnySwiat.h"

class Guarana : public Roslina {
public:

    Guarana(int x, int y, WirtualnySwiat *swiat);

    ~Guarana();

    void kolizja(int nowyX, int nowyY, Organizm* przeciwnik) override;

    std::string getNazwa() {
        return ("Guarana");
    }
};


#endif //WIRTUALNY_SWIAT_GUARANA_H
