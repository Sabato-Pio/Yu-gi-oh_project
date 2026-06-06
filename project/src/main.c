#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "carta.h"
#include "btree.h"

int main() {
    system("cls");
    printf("\033[34mCIAO! Benvenuto nel Database Tier di Yugioh Meta!\033[0m\n\n"); 
    carta c1 = creaCarta(68464358, "Caduta di Albaz", "Albaz", 1800, 0);
    carta c2 = creaCarta(25801745, "Kitkallos Tearlaments", "Tearlaments", 2300, 1200);

    output_item(c1);
    output_item(c2);

    int risultato = cmpItem(c1, c2);
    printf("Risultato numerico di cmpItem: %d\n", risultato); 

    if (risultato < 0) {
        printf("-> '%s' viene PRIMA di '%s' in ordine alfabetico.\n", getNome(c1), getNome(c2));
    } else if (risultato > 0) {
        printf("-> '%s' viene DOPO '%s' in ordine alfabetico.\n", getNome(c1), getNome(c2));
    } else {
        printf("-> Le carte hanno esattamente lo stesso nome.\n");
    }
    
    Btree db = newBtree();
    db = insertBtree(db, c1);
    db = insertBtree(db, c2);
    inorder(db);

    cancellaCarta(c1);
    cancellaCarta(c2);

    return 0;
}