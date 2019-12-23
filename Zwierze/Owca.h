//
// Created by Robert on 23.12.2019.
//

#ifndef WIRTUALNY_SWIAT_OWCA_H
#define WIRTUALNY_SWIAT_OWCA_H


#include "Zwierze.h"
#include "../WirtualnySwiat.h"

class Owca : public Zwierze {
public:

    Owca(int x, int y, WirtualnySwiat *swiat);

    ~Owca();
};


#endif //WIRTUALNY_SWIAT_OWCA_H
