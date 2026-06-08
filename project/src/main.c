#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "carta.h"
#include "btree.h"
#include "loader.h"

int main()
{
    Btree db = newBtree();
    int scelta = -1;

    system("cls");
    printf("\033[34mCIAO! Benvenuto nel Database Tier di Carte Meta!\033[0m\n\n");

    printf("\nCaricamento carte in corso...\n");
    db=caricaDatabase(db, "data/carte.txt");
    printf("\nCaricamento carte completato!\n");

    system("cls");
    printf("Database di Carte Meta");
    while (scelta != 0)
    {
        printf("\n-----------------------------\n");
        printf("1. Inserisci una nuova carta manuale\n");
        printf("2. Stampa tutte le carte (alfabetico)\n");
        printf("3. Elimina una carta (Work in Progress)\n");
        printf("0. Esci\n");
        printf("\n-----------------------------\n");
        printf("Seleziona un'opzione: ");

        scanf("%d", &scelta);
        while (getchar() != '\n')
            ; // svuota il buffer

        switch (scelta)
        {
        case 1:
        {
            int id, atk, def;
            char nome[100];
            char archetipo[50];

            printf("\n INSERIMENTO NUOVA CARTA \n");

            printf("Inserisci ID: ");
            scanf("%d", &id);
            while (getchar() != '\n');

            printf("Inserisci Nome carta: ");
            fgets(nome, 100, stdin);       // leggi da file stdin indica che il file è la tastiera
            nome[strcspn(nome, "\n")] = 0; // rimuove l ultimo invio

            printf("Inseirisci Archetipo: ");
            fgets(archetipo, 50, stdin);
            archetipo[strcspn(archetipo, "\n")] = 0;

            printf("Inserisci ATK: ");
            scanf("%d", &atk);

            printf("Inserisci DEF: ");
            scanf("%d", &def);
            while (getchar() != '\n');

            carta nuova = creaCarta(id, nome, archetipo, atk, def);
            if (nuova != NULL)
            {
                db = insertBtree(db, nuova);
                printf("CARTA '%s' INSERITA CON SUCCESSO NEL DATABASE!\n", getNome(nuova));

                if(salvaCartaSuFile("data/carte.txt",nuova)){
                    printf("Carta salvata nel file di memoria.\n");
                }else{
                    printf("Errore durante il salvataggio sul file.\n");
                }
            }
            else
            {
                printf("Errore: Memoria insufficiente, impossibile creare la carta.\n");
            }
            break;
        }
        case 2:
            printf("\n DATABASE ATTUALE \n");
            if (emptyBtree(db))
            {
                printf("Ancora nessuna carta nel database.");
            }
            else
            {
                inorder(db);
            }
            break;

        case 3:
        {
            char nomeDaCancellare[100];
            printf("\n--- ELIMINAZIONE CARTA ---\n");
            
            if (emptyBtree(db)) {
                printf("Il database e' vuoto, nulla da eliminare.\n");
                break;
            }
            
            printf("Inserisci il NOME ESATTO della carta da eliminare: ");
            fgets(nomeDaCancellare, 100, stdin);
            nomeDaCancellare[strcspn(nomeDaCancellare, "\n")] = 0; /* Rimuove l'invio */
            
            /* Prima di cancellare, verifichiamo che esista davvero */
            if (searchBtree(db, nomeDaCancellare) != NULLITEM) {
                db = deleteBtree(db, nomeDaCancellare);
                printf("-> CARTA '%s' ELIMINATA CON SUCCESSO DAL DATABASE IN MEMORIA!\n", nomeDaCancellare);
            } else {
                printf("-> Errore: Carta '%s' non trovata nel Tier Meta.\n", nomeDaCancellare);
            }
            break;
        }

        case 0:
            printf("\n Grazie per aver usato il nostro programma a presto!");
            cancellaBtree(db);
            break;

        default:
            printf("\nScelta non valida. Riprova. \n");
        }
    }
}