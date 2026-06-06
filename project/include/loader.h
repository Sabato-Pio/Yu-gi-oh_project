#ifndef LOADER_H
#define LOADER_H

#include "btree.h"

/* Carica le carte da un file testuale e le inserisce nell'albero */
Btree caricaDatabase(Btree db, const char *filename);

#endif