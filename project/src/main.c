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

    printf("Caricamento carte dal file in corso...\n");
    db = caricaDatabase(db, "data/carte.txt"); 

    printf("\n--- Database Attuale ---\n");
    inorder(db);

    printf("\nDeallocazione memoria in corso...\n");
    cancellaBtree(db);
    printf("Memoria liberata con successo. Arrivederci!\n");

    return 0;
}