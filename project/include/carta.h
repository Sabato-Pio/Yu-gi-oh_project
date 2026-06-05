#ifndef CARTA_H
#define CARTA_H

/*Creiamo una struct per la carta dove usiamo un puntatore opaco per l'information hiding*/
typedef struct ccarta *carta;

/*Creiamo una carta e restituiamo il puntatore DOVREBBE*/
carta creaCarta(int id, char *nome, char *archetipo, int atk, int def);

/*getter*/
int getId(carta c);
char* getNome(carta c);
char* getArchetipo(carta c);
int getAtk(carta c);
int getDef(carta c);

/*Cancella carta*/
void cancellaCarta(carta c);

#endif