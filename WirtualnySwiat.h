//
// Created by Robert on 18.12.2019.
//

#ifndef WIRTUALNY_SWIAT_WIRTUALNYSWIAT_H
#define WIRTUALNY_SWIAT_WIRTUALNYSWIAT_H

#include <list>

#include "Organizm.h"



class WirtualnySwiat {
    Organizm*** organizmy;
    int iloscOrganizmow;
    std::list<Organizm*> kolejnoscOrganizmow;
    std::list<Organizm*> organizmyDoUsuniecia;
    int rozmiar; // rozmiar tablicy2D: rozmiar x rozmiar
    int tura = 0;

public:

    WirtualnySwiat(int rozmiar = 20, int iloscOrganizmow = 20);

    ~WirtualnySwiat();

    void wykonajTure();
    void rysujSwiat();
    void usunOrganizm(int x, int y, Organizm* organizm);
    void ustalKolejnosc();
    bool zajetoscPola(int x, int y); // true jezeli pole zajete lub pole wybiega poza tablice swiata
    bool czyWGranicy(int x, int y);
    void createOrganizm(int x, int y, char znak);

    // GETTERS

    Organizm* getOrganizm(int x, int y){return organizmy[x][y];}
    int getRozmiar(){return rozmiar;}
    int getTura(){return tura;}

    // SETTERS

    void setOrganizm(int x, int y, Organizm* organizm, int nowyX, int nowyY);

};


#endif //WIRTUALNY_SWIAT_WIRTUALNYSWIAT_H

/* adnotacja dotyczaca list:
Uzywasz listy do ustalenia kolejnosci organizmow - w tym przypadku jest to preferowana
 struktura danych. Wykonujac ture iterujesz przez liste i przy okazji chcesz
 wprowadzac na niej zmiany. Dodawanie (utworzOrganizm) elementow do listy nie ma wplywu
 na aktualny przebieg iteracji. Usuwanie unieważnia tylko iteratory i odwołania do wymazanych elementów.
 Aby usuwanie nie zepsulo przebiegu iteracji poczatkowo ustawiasz tylko flage
 organizmu, informujaca o tym, ze organizm nadaje sie do usuniecia.
 Organizmy nadajace sie do usuniecia usuwasz juz po calym cyklu iteracji przez liste.

 Lista jest lepszym rozwiazaniem od vectora, bo gdy dodajemy elementy do vectora
 moze nastapic realokacja calego konteneru, co spowoduje blad, bo aktualna iteracja
 nie uwzgledni realokacji kontenera w pamieci. Czyli w przypadku listy trzeba obsluzyc
 tylko usuwanie elementow, a w przypadku vectora trzeba dodawanie oraz usuwanie.

 Zrodlo: https://stackoverflow.com/questions/6438086/iterator-invalidation-rules

*/
