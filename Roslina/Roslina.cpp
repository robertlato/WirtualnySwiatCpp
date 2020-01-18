//
// Created by Robert on 18.12.2019.
//
#include <cstdlib>


#include "Roslina.h"
#include "../WirtualnySwiat.h"


void Roslina::akcja()
{
    srand(time(nullptr));
    int szansa = rand() % 100;
    if(getNazwa() == "Ciern") szansa = 100;

    if (szansa > 80)
    {
        bool gotowe = false;
        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                // jezeli pole jest wolne i jest w granicy swiata to stworz nowy organizm
                if (!aktualnySwiat->zajetoscPola(polozenie.x + i,polozenie.y + j))
                {
                    aktualnySwiat->createOrganizm(polozenie.x + i,polozenie.y + j, getZnak());
                    gotowe = true;
                    break;
                }
            }
            if (gotowe) break;
        }
    }
}
