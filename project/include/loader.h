#ifndef LOADER_H
#define LOADER_H

#include "carta.h"
#include "btree.h"

/* Carica le carte da un file testuale e le inserisce nell'albero */
Btree caricaDatabase(Btree db, const char *filename);

/* salva una carta in fondo al file*/
int salvaCartaSuFile(const char *filename, carta c);

/* Sovrascrive il file originale salvando l'intero stato attuale dell'albero */
int salvaInteroDatabase(Btree db, const char *filename);

#endif