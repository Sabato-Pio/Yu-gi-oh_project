#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "carta.h"
#include "btree.h"
#include "loader.h"  

int main() {
    system("cls");
    printf("\033[34mCIAO! Benvenuto nel Database Tier di Yugioh Meta!\033[0m\n\n"); 

    Btree db = newBtree();

    printf("Caricamento carte in corso...\n");
    db = caricaDatabase(db, "data/carte.txt"); 

    printf("\n--- Database PRIMA dell'inserimento ---\n");
    inorder(db);

    printf("\nCreazione e salvataggio di una nuova carta...\n");
    carta nuova = creaCarta(33704273, "Lubellion il Drago Cenerino", "Albaz", 2500, 2000);
    
    if (nuova != NULL) {
        db = insertBtree(db, nuova);
        
        if (salvaCartaSuFile("data/carte.txt", nuova)) {
            printf("Carta salvata con successo sul file 'carte.txt'!\n");
        }
    }

    printf("\n--- Database DOPO l'inserimento ---\n");
    inorder(db);

    cancellaBtree(db);

    return 0;
}