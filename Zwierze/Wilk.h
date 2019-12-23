//
// Created by Robert on 23.12.2019.
//

#ifndef WIRTUALNY_SWIAT_WILK_H
#define WIRTUALNY_SWIAT_WILK_H


#include "Zwierze.h"
#include "../WirtualnySwiat.h"

class Wilk : public Zwierze {
public:

    Wilk(int x, int y, WirtualnySwiat *swiat);

    ~Wilk();
};


#endif //WIRTUALNY_SWIAT_WILK_H
