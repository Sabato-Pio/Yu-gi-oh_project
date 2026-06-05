#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carta.h"
/*Definizione della struct nascosta al client*/
typedef struct ccarta
{
    int id;
    char nome[100];
    char archetipo[50];
    int atk;
    int def;
};

carta creaCarta(int id, char *nome, char *archetipo, int atk, int def)
{
    carta nuova = malloc(sizeof(struct ccarta));
    if (nuova == NULL)
    {
        return NULL;
    }

    nuova->id = id;

    /*passo il nome con 99 per farlo in modo sicuro*/
    strncpy(nuova->nome, nome, 99);
    nuova->nome[99] = '\0';

    strncpy(nuova->archetipo, archetipo, 49);
    nuova->archetipo[49] = '\0';

    nuova->atk = atk;
    nuova->def = def;

    return nuova;
}
/*Operatori getter*/
int getId(carta c)
{
    if (c == NULL)
        return -1;
    return c->id;
}

char *getNome(carta c)
{
    if (c == NULL)
        return NULL;
    return c->nome;
}

char *getArchetipo(carta c)
{
    if (c == NULL)
        return NULL;
    return c->archetipo;
}

int getAtk(carta c)
{
    if (c == NULL)
        return -1;
    return c->atk;
}

int getDef(carta c)
{
    if (c == NULL)
        return -1;
    return c->atk;
}

void cancellaCarta(carta c)
{
    if (c != NULL)
    {
        free(c);
    }
}