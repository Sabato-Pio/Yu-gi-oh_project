#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loader.h"
#include "carta.h"

#define MAX_LINE 256

Btree caricaDatabase(Btree db, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Errore: Impossibile aprire il file %s\n", filename);
        return db;
    }

    char linea[MAX_LINE];
    
    while (fgets(linea, sizeof(linea), file) != NULL) {
        linea[strcspn(linea, "\n")] = 0;

        char *token_id = strtok(linea, ",");
        char *token_nome = strtok(NULL, ",");
        char *token_archetipo = strtok(NULL, ",");
        char *token_atk = strtok(NULL, ",");
        char *token_def = strtok(NULL, ",");

        if (token_id && token_nome && token_archetipo && token_atk && token_def) {
            int id = atoi(token_id);
            int atk = atoi(token_atk);
            int def = atoi(token_def);

            carta nuovaCarta = creaCarta(id, token_nome, token_archetipo, atk, def);
            if (nuovaCarta != NULL) {
                db = insertBtree(db, nuovaCarta);
            }
        }
    }

    fclose(file);
    return db;
}