#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TACHES 100
#define MAX_LEN 100
 
typedef struct {
    char titre[MAX_LEN];      
    char description[MAX_LEN]; 
    char dateecheance[MAX_LEN];
    char priorite[MAX_LEN];
} Tache;

Tache taches[MAX_TACHES];
int nombreDeTaches = 0;

void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void afficherMenu(void) {
    printf("\n=== Menu ===\n");
    printf("1. Ajouter une tache\n");
    printf("2. Quitter\n");
    printf("Choisissez une option: ");
}

void ajouterTache(void) {
    if (nombreDeTaches < MAX_TACHES) {
        printf("Entrer le titre de la tache: ");
        fgets(taches[nombreDeTaches].titre, MAX_LEN, stdin);
        strtok(taches[nombreDeTaches].titre, "\n");

        printf("Entrer la description de la tache: ");
        fgets(taches[nombreDeTaches].description, MAX_LEN, stdin);
        strtok(taches[nombreDeTaches].description, "\n");

        printf("Entrer la date d'echeance (YYYY-MM-DD): ");
        fgets(taches[nombreDeTaches].dateecheance, MAX_LEN, stdin);
        strtok(taches[nombreDeTaches].dateecheance, "\n");

        printf("Entrer la priorite (high/low): ");
        fgets(taches[nombreDeTaches].priorite, MAX_LEN, stdin);
        strtok(taches[nombreDeTaches].priorite, "\n");

        printf("Tache ajoutee avec succes.\n");
        nombreDeTaches++;
    } else {
        printf("Le nombre maximum de taches a ete atteint.\n");
    }           
}



int main(void) {
    int choix;

    do {
        afficherMenu();
        if (scanf("%d", &choix) != 1) {
            printf("Entree invalide. Veuillez reessayer.\n");
            clearBuffer();
            continue;
        }
        clearBuffer();

        switch (choix) {
            case 1:
                ajouterTache();
                break;
            case 2:
                printf("Au revoir !\n");
                exit(0);
            default:
                printf("Option invalide, veuillez reessayer.\n");
        }
    } while (1);

    return 0;
}
