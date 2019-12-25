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
    virtual void akcja() = 0;

    virtual void kolizja() = 0;

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

    virtual ~Organizm();

//     getPolozenie()
//    {
//        return polozenie;
//    }

protected:
    char znak;
    int wiek;
    int sila;
    int inicjatywa;
    struct polozenie {
        int x;
        int y;
    } polozenie;

    WirtualnySwiat *aktualnySwiat = nullptr;

};


#endif //WIRTUALNY_SWIAT_ORGANIZM_H
