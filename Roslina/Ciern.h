//
// Created by Robert on 18.12.2019.
//

#ifndef WIRTUALNY_SWIAT_CIERN_H
#define WIRTUALNY_SWIAT_CIERN_H


#include "Roslina.h"
#include "../WirtualnySwiat.h"

class Ciern : public Roslina {
public:

    Ciern(int x, int y, WirtualnySwiat *swiat);
    ~Ciern();
    std::string getNazwa() {return ("Ciern");}

};


#endif //WIRTUALNY_SWIAT_CIERN_H
