#ifndef ITEM_H
#define ITEM_H

#include "carta.h"
typedef carta item;

# define NULLITEM NULL

int cmpItem(item a, item b);
void output_item(item a);

#endif