#include "btree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*la struttura del nodo radice, nodo sinistro e nodo destro*/
struct node{
    item value;
    struct node *sinistro;
    struct node *destro;
};

/* Restituisce il puntatore al nodo radice */
static struct node *getRoot(Btree T) {
    return T;
}

/* Estrae il dato dal nodo */
static item getItem(struct node *N) {
    if (N == NULL) return NULLITEM;
    return N->value;
}

/*creiamo il nostro albero*/
Btree newBtree(void){
    return NULL;
}

/*controlla se l'albero è vuoto*/
int emptyBtree(Btree T){
    return T==NULL;
}

Btree insertBtree(Btree T, item val){
    if (emptyBtree(T)) {   //controlliamo se è vuoto
        struct node *nuovo = malloc(sizeof(struct node)); //allochiamo la dimensione di un nodo
        if (nuovo != NULL) { // se l allocazione ha successo
            nuovo->value = val;  //il valore viene assegnato 
            nuovo->sinistro = NULL; //predisponiamo un ramo sinistro
            nuovo->destro = NULL;  // predisponiamo un ramo destro
        }
        return nuovo;
    }
    /*decidiamo se andare a sinistra o a destra usando cmpItem */
    int cmp = cmpItem(val, T->value);
    
    if (cmp < 0) {
        /* Il nome viene prima: scendiamo nel sottoalbero sinistro */
        T->sinistro = insertBtree(T->sinistro, val);
    } else if (cmp > 0) {
        /* Il nome viene dopo: scendiamo nel sottoalbero destro */
        T->destro = insertBtree(T->destro, val);
    }
    /* Se cmp == 0, la carta esiste già, ignoriamo i duplicati */

    return T;
}

item searchBtree(Btree T, char *nomeChiave) {
    if (emptyBtree(T)) return NULLITEM;
    int cmp = strcmp(nomeChiave, getNome(getItem(getRoot(T))));
    if (cmp == 0) return getItem(getRoot(T));
    if (cmp < 0)  return searchBtree(figlioSX(T), nomeChiave);
    else          return searchBtree(figlioDX(T), nomeChiave);
}

/* Restituisce il sottoalbero sinistro */
Btree figlioSX(Btree T) {
    if (T != NULL) return T->sinistro;
    return NULL;
}

/* Restituisce il sottoalbero destro */
Btree figlioDX(Btree T) {
    if (T != NULL) return T->destro;
    return NULL;
}

/*stampa in ordine alfabetico*/
void inorder(Btree T) {
    if (emptyBtree(T)) return;         
    
    inorder(figlioSX(T));               
    output_item(getItem(getRoot(T)));   
    inorder(figlioDX(T));               
}