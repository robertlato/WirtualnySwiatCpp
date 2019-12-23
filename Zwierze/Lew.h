//
// Created by Robert on 23.12.2019.
//

#ifndef WIRTUALNY_SWIAT_LEW_H
#define WIRTUALNY_SWIAT_LEW_H


#include "Zwierze.h"
#include "../WirtualnySwiat.h"

class Lew : public Zwierze {
public:

    Lew(int x, int y, WirtualnySwiat *swiat);

    ~Lew();
};


#endif //WIRTUALNY_SWIAT_LEW_H
