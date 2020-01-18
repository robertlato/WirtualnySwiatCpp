//
// Created by Robert on 18.12.2019.
//

#ifndef WIRTUALNY_SWIAT_TRAWA_H
#define WIRTUALNY_SWIAT_TRAWA_H


#include "Roslina.h"
#include "../WirtualnySwiat.h"

class Trawa : public Roslina {
public:

    Trawa(int x, int y, WirtualnySwiat *swiat);
    ~Trawa();
    std::string getNazwa(){return ("Trawa");}

};


#endif //WIRTUALNY_SWIAT_TRAWA_H
