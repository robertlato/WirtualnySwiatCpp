//
// Created by Robert on 18.12.2019.
//

#include "WirtualnySwiat.h"

#include <iostream>
#include <algorithm>
//#include <cstdlib>
//#include <ctime>

#include "Roslina/Ciern.h"
#include "Roslina/Guarana.h"
#include "Roslina/Trawa.h"

#include "Zwierze/Dzik.h"
#include "Zwierze/Lew.h"
#include "Zwierze/Owca.h"
#include "Zwierze/Wilk.h"
#include "Zwierze/Zmija.h"


using namespace std;

// konstruktor - inicjuje wirtualny swiat (tab 2D), tworzy zadana ilosc
// organizmow i przypisuje je do losowych pol wirtualnego swiata
// uzupelnia kontener kolejnoscOrganizmow i go sortuje

WirtualnySwiat::WirtualnySwiat(int rozmiar, int iloscOrganizmow) {
    this->rozmiar = rozmiar;
    this->iloscOrganizmow = iloscOrganizmow;

    //  tworze wirtualny swiat 2D (tab wskaznikow)
    organizmy = new Organizm **[rozmiar];
    for (int i = 0; i < rozmiar; i++)
        organizmy[i] = new Organizm *[rozmiar];

    // ustawiam nullptr dla kazdego wskazika tablicy 2D

    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar; j++) {
            organizmy[i][j] = nullptr;
        }
    }

    // tworze randomowe organizmy w randomowych polach
    // cout << "Ilosc organizmow = " << iloscOrganizmow << endl;
    int i = iloscOrganizmow;
    srand(time(0));
    while (i > 0) {
        int x = rand() % rozmiar;
        int y = rand() % rozmiar;
        if (organizmy[x][y] == nullptr) {
            int wylosowanyOrganizm = rand() % 8 + 1;

            switch (wylosowanyOrganizm) {
                case 1:
                    organizmy[x][y] = new Ciern(x, y, this);
                    // dalszy kod
                    break;

                case 2:
                    organizmy[x][y] = new Dzik(x, y, this);
                    // dalszy kod
                    break;

                case 3:
                    organizmy[x][y] = new Guarana(x, y, this);
                    // dalszy kod
                    break;

                case 4:
                    organizmy[x][y] = new Lew(x, y, this);
                    // dalszy kod
                    break;

                case 5:
                    organizmy[x][y] = new Owca(x, y, this);
                    // dalszy kod
                    break;

                case 6:
                    organizmy[x][y] = new Trawa(x, y, this);
                    // dalszy kod
                    break;

                case 7:
                    organizmy[x][y] = new Wilk(x, y, this);
                    // dalszy kod
                    break;

                case 8:
                    organizmy[x][y] = new Zmija(x, y, this);
                    // dalszy kod
                    break;

                default:
//                    cout << "Trafil sie default.. boomer\n"
//                            "Wylosowany organizm = "
//                            << wylosowanyOrganizm << endl;
                    break;
            }
//            cout << "Zmniejszam i o 1\niloscOrganizmow = " << i << endl;
            i -= 1;
            kolejnoscOrganizmow.push_back(organizmy[x][y]);
        }

    }
    sort(kolejnoscOrganizmow.begin(), kolejnoscOrganizmow.end(), Organizm::porownaj);
    // wypisuje vector kolejnosci:
    cout << "wypisuje kolejnosc po segregacji\n";
    for (const auto &j : kolejnoscOrganizmow) cout << j->getZnak() << ", inicjatywa = "
        << j->getInicjatywa() << ", wiek = " << j->getWiek()
        << ", pierwszenstwo = " << j->getPierwszenstwo() << endl;
}

void WirtualnySwiat::rysujSwiat() {
    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar; j++) {
            if (organizmy[i][j] == nullptr) cout << '0';
            else {
                cout << organizmy[i][j]->getZnak();
            }

            // organizmy[i][j] = nullptr;
        }
        cout << endl;
    }

}

void WirtualnySwiat::wykonajTure()
{
    for (const auto &i : kolejnoscOrganizmow)
    {
        i->akcja();
    }

}

void WirtualnySwiat::setOrganizm(int x, int y, Organizm* organizm, int nowyX, int nowyY)
{
    organizmy[x][y] = nullptr;
    if (organizmy[nowyX][nowyY] != nullptr)
    {
        delete organizmy[nowyX][nowyY];
        // usun wskaznik z vectora kolejnoscOrganizmow

        vector<Organizm*>::iterator it;
        it = find(kolejnoscOrganizmow.begin(), kolejnoscOrganizmow.end(), organizmy[nowyX][nowyY]);
        kolejnoscOrganizmow.erase(it);
    }
    organizmy[nowyX][nowyY] = organizm;
}


WirtualnySwiat::~WirtualnySwiat() = default;

