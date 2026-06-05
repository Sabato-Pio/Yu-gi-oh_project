#include <stdio.h>
#include "item.h"
#include "carta.h"

int main()
{
    printf("CIAO! Benvenuto nel Database Tier di Yugioh Meta!\n");
    /*test del programma*/
    carta c1 = creaCarta(68464358, "Caduta di Albaz", "Albaz", 1800, 0);
    carta c2 = creaCarta(25801745, "Kitkallos Tearlaments", "Tearlaments", 2300, 1200);

    /*stampiamo le 2 carte*/
    output_item(c1);
    output_item(c2);

    /*test comp*/
    int risultato = cmpItem(c1, c2);
    printf("risultato numerico di cmpItem: %d \n");

    if (risultato < 0)
    {
        printf("-> '%s' viene PRIMA di '%s' in ordine alfabetico.\n", getNome(c1), getNome(c2));
    }
    else if (risultato > 0)
    {
        printf("-> '%s' viene DOPO di '%s' in ordine alfabetico.\n", getNome(c1), getNome(c2));
    }
    else
    {
        printf("-> Le carte hanno esattamente lo stesso nome.\n");
    }

    /*liberiamo la memoria*/
    cancellaCarta(c1);
    cancellaCarta(c2);
}