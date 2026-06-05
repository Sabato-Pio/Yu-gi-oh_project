#include <stdio.h>
#include <string.h>
#include "item.h"
/*confronta i nomi e vede quale viene prima in ordine alfabetico*/
int cmpItem(item a, item b)
{
    if (a != NULLITEM && b != NULLITEM)
    {
        return strcmp(getNome(a), getNome(b));
    }
    else
    {
        return 0;
    }
}
/*stampa i dettagli della carta a schermo*/
void output_item(item a){
    if(a==NULLITEM){
        printf("Carta non valida (NULLITEM).\n");
        return;
    }
    printf("ID: %08d | %-25s | Archetipo: %-15s | ATK: %4d / DEF: %4d\n",
    getId(a), getNome(a), getArchetipo(a), getAtk(a), getDef(a));

}