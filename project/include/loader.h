#ifndef LOADER_H
#define LOADER_H

#include "carta.h"
#include "btree.h"

/* Carica le carte da un file testuale e le inserisce nell'albero */
Btree caricaDatabase(Btree db, const char *filename);

/* salva una carta in fondo al file*/
int salvaCartaSuFile(const char *filename, carta c);

#endif