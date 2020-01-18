//
// Created by Robert on 18.12.2019.
//

#ifndef WIRTUALNY_SWIAT_DZIK_H
#define WIRTUALNY_SWIAT_DZIK_H


#include "Zwierze.h"
#include "../WirtualnySwiat.h"

class Dzik : public Zwierze {
public:

    Dzik(int x, int y, WirtualnySwiat *swiat);
    ~Dzik();
    std::string getNazwa(){return ("Dzik");}

};


#endif //WIRTUALNY_SWIAT_DZIK_H
