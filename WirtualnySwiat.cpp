//
// Created by Robert on 18.12.2019.
//


#include <iostream>
#include <algorithm>
//#include <cstdlib>
//#include <ctime>

#include "WirtualnySwiat.h"

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
    int i = iloscOrganizmow;
    srand(time(0));
    while (i > 0) {
        int x = rand() % rozmiar;
        int y = rand() % rozmiar;
        if (organizmy[x][y] == nullptr) {
            int wylosowanyOrganizm = rand() % 8 + 1;

            switch (wylosowanyOrganizm)
            {
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
                    break;
            }
            i -= 1;
        }
    }
    ustalKolejnosc();
}

void WirtualnySwiat::ustalKolejnosc()
{
    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            if (organizmy[i][j] != nullptr)
            {
                kolejnoscOrganizmow.push_back(organizmy[i][j]);
            }
        }
    }
    kolejnoscOrganizmow.sort(Organizm::porownaj);
}


void WirtualnySwiat::rysujSwiat()
{
    cout << endl;
    for (int i = rozmiar - 1; i >= 0; i--)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            if (organizmy[j][i] == nullptr) cout << '0';
            else
            {
                cout << organizmy[j][i]->getZnak();
            }
        }
        cout << endl;
    }
    cout << endl;

}

void WirtualnySwiat::wykonajTure()
{
    tura += 1;

// moglbys wykonac petle const auto, ale przy okazji i tak potrzebujesz
// zmienna it (iterator) przy usuwaniu
    int tabSize = kolejnoscOrganizmow.size() - 1;
    list<Organizm*>::iterator it;
    for (it = kolejnoscOrganizmow.begin(); tabSize != 0; ++it)
    {
        if(!(*it)->getDoUsuniecia()) (*it)->akcja();
        (*it)->increaseWiek();
        tabSize--;
    }

    // usun organizmy jezeli sa jakies do usuniecia
    if (!organizmyDoUsuniecia.empty())
    {
        for (const auto& j : organizmyDoUsuniecia)
        {
            it = find(kolejnoscOrganizmow.begin(), kolejnoscOrganizmow.end(), j);
            kolejnoscOrganizmow.erase(it);
        }
        organizmyDoUsuniecia.clear();
    }
    kolejnoscOrganizmow.sort(Organizm::porownaj);
}

void WirtualnySwiat::setOrganizm(int x, int y, Organizm* organizm, int nowyX, int nowyY)
{
    organizmy[x][y] = nullptr;
    if (organizmy[nowyX][nowyY] != nullptr)
    {
        usunOrganizm(nowyX, nowyY, organizmy[nowyX][nowyY]);
    }
    organizmy[nowyX][nowyY] = organizm;
}


WirtualnySwiat::~WirtualnySwiat() = default;



void WirtualnySwiat::usunOrganizm(int x, int y, Organizm* organizm)
{
    organizmy[x][y] = nullptr;

    // usun wskaznik z vectora kolejnoscOrganizmow
    organizmyDoUsuniecia.push_back(organizm);
    organizm->setDoUsuniecia();
}

void WirtualnySwiat::createOrganizm(int x, int y, char znak)
{
    switch (znak)
    {
        case 'C':
            organizmy[x][y] = new Ciern(x, y, this);
            // dalszy kod
            break;

        case 'D':
            organizmy[x][y] = new Dzik(x, y, this);
            // dalszy kod
            break;

        case 'G':
            organizmy[x][y] = new Guarana(x, y, this);
            // dalszy kod
            break;

        case 'L':
            organizmy[x][y] = new Lew(x, y, this);
            // dalszy kod
            break;

        case 'O':
            organizmy[x][y] = new Owca(x, y, this);
            // dalszy kod
            break;

        case 'T':
            organizmy[x][y] = new Trawa(x, y, this);
            // dalszy kod
            break;

        case 'W':
            organizmy[x][y] = new Wilk(x, y, this);
            // dalszy kod
            break;

        case 'Z':
            organizmy[x][y] = new Zmija(x, y, this);
            // dalszy kod
            break;

        default:
            break;
    }

    kolejnoscOrganizmow.push_back(organizmy[x][y]);
    cout << "Utworzono nowy organizm: " << organizmy[x][y]->getNazwa()
        <<  ". Jego pole to: ["
        << x << "]" << "[" << y << "].\n";
}


bool WirtualnySwiat::zajetoscPola(int x, int y) // true jezeli pole zajete lub pole wybiega poza tablice swiata
{
    if(czyWGranicy(x, y)) return organizmy[x][y] != nullptr;
    return true;
}

bool WirtualnySwiat::czyWGranicy(int x, int y)
{
    return !(x >= rozmiar || x < 0 ||
             y >= rozmiar || y < 0);
}


