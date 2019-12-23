//
// Created by Robert on 18.12.2019.
//

#ifndef WIRTUALNY_SWIAT_ORGANIZM_H
#define WIRTUALNY_SWIAT_ORGANIZM_H


// forward declaration - deklarujesz, ze bedzie istniala
// taka klasa, zeby moc zadeklarowac wskaznik do instancji takiej klasy
// dzieki temu unikasz sytuacji, w ktorej includujesz pliki naglowkowe
// rekurencyjnie (oba pliki naglowkowe includuja siebie nawzajem)
class WirtualnySwiat;

class Organizm {
public:
    //void akcja();

    //void kolizja();

    //void rysowanie();

    static bool porownaj(Organizm *pierwszy, Organizm *drugi)
    {
        return (pierwszy->getPierwszenstwo() > drugi->getPierwszenstwo());
    }

    int getPierwszenstwo()
    {
        return (wiek+inicjatywa);
    }

    char getZnak()
    {
        return this->znak;
    }

    int getInicjatywa()
    {
        return this->inicjatywa;
    }

protected:
    char znak = 0;
    int wiek = 0;
    int sila = 0;
    int inicjatywa = 0;
    struct polozenie {
        int x = 0;
        int y = 0;
    } polozenie;

    WirtualnySwiat *aktualnySwiat = nullptr;

};


#endif //WIRTUALNY_SWIAT_ORGANIZM_H
