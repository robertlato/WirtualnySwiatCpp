//
// Created by Robert on 18.12.2019.
//

#ifndef WIRTUALNY_SWIAT_ORGANIZM_H
#define WIRTUALNY_SWIAT_ORGANIZM_H

#include <string>
// forward declaration - deklarujesz, ze bedzie istniala
// taka klasa, zeby moc zadeklarowac wskaznik do instancji takiej klasy
// dzieki temu unikasz sytuacji, w ktorej includujesz pliki naglowkowe
// rekurencyjnie (oba pliki naglowkowe includuja siebie nawzajem)
class WirtualnySwiat;

class Organizm {
public:
    virtual void akcja() = 0;

    virtual void kolizja(int nowyX, int nowyY) = 0;

    virtual std::string getNazwa() = 0;

    //void rysowanie();

    static bool porownaj(Organizm *pierwszy, Organizm *drugi)
    {
        return (pierwszy->getPierwszenstwo() > drugi->getPierwszenstwo());
    }

    int getPierwszenstwo()
    {
        return (wiek+inicjatywa);
    }

    int getWiek(){return wiek;}

    char getZnak()
    {
        return this->znak;
    }

    int getInicjatywa()
    {
        return this->inicjatywa;
    }

    int getSila()
    {
        return sila;
    }


    virtual ~Organizm()
    {}

    void setPolozenie(int nowyX, int nowyY);

protected:
    char znak;
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
