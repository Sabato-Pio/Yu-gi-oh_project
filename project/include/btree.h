#ifndef BTREE_H
#define BTREE_H

#include "item.h"
typedef struct node *Btree;

/* Crea un albero e controlla se e' vuoto */
Btree newBtree(void);
int emptyBtree(Btree T);

/* inserisci e cerca nell albero binario */
Btree insertBtree(Btree T, item val);
item searchBtree(Btree T, char *nomeChiave);

/* Operatori base dell'ADT Albero */
Btree figlioSX(Btree T);
Btree figlioDX(Btree T);

/* stampa le carte in ordine alfabetico*/
void inorder(Btree T);

/* distrugge l'albero e dealloca tutte le carte*/
void cancellaBtree(Btree T);
#endif