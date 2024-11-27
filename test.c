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
    printf("2. Afficher liste tache\n");
    printf("3. Modifier une tache\n");
    printf("4. Supprimer une tache\n");        
    printf("5. Filtrer par priorite\n");
    printf("6. Quitter\n");
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
void afficherListesTaches(void) {
    if (nombreDeTaches == 0) {
        printf("Aucune tache a afficher.\n");
    } else {
        printf("\n== Liste des taches ==\n");
        for (int i = 0; i < nombreDeTaches; i++) {
            printf("Tache %d:\n", i + 1);
            printf("  Titre: %s\n", taches[i].titre);
            printf("  Description: %s\n", taches[i].description);
            printf("  Date d'echeance: %s\n", taches[i].dateecheance);
            printf("  Priorite: %s\n", taches[i].priorite);
        }
    }
}
void modifierTache(void) {
    int numeroTache;
    printf("Entrer le numero de la tache a modifier: ");
    if (scanf("%d", &numeroTache) != 1) {
        printf("Entree invalide.\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    if (numeroTache < 1 || numeroTache > nombreDeTaches) {
        printf("Numero de tache incorrect.\n");
        return;
    }

    int index = numeroTache - 1;

    printf("Nouveau titre de la tache: ");
    fgets(taches[index].titre, MAX_LEN, stdin);
    strtok(taches[index].titre, "\n");

    printf("Nouvelle description de la tache: ");
    fgets(taches[index].description, MAX_LEN, stdin);
    strtok(taches[index].description, "\n");

    printf("Nouvelle date d'echeance: ");
    fgets(taches[index].dateecheance, MAX_LEN, stdin);
    strtok(taches[index].dateecheance, "\n");

    printf("Nouvelle priorite (high/low): ");
    fgets(taches[index].priorite, MAX_LEN, stdin);
    strtok(taches[index].priorite, "\n");

    printf("Tache modifiee avec succes.\n");
}
void supprimerTache(void) {
    int numeroTache;

    printf("Entrer le numero de la tache a supprimer: ");
    if (scanf("%d", &numeroTache) != 1) {
        printf("Entree invalide.\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    if (numeroTache < 1 || numeroTache > nombreDeTaches) {
        printf("Numero de tache incorrect.\n");
        return;
    }

    int index = numeroTache - 1;
    for (int i = index; i < nombreDeTaches - 1; i++) {
        taches[i] = taches[i + 1];
    }

    nombreDeTaches--;
    printf("Tache supprimee avec succes.\n");
}
void filtrerParPriorite(void) {
    char prioriteFiltree[MAX_LEN];
    int trouve = 0;

    printf("Entrer la priorite a filtrer (high/low): ");
    fgets(prioriteFiltree, MAX_LEN, stdin);
    strtok(prioriteFiltree, "\n");

    printf("\n== Taches de priorite %s ==\n", prioriteFiltree);
    for (int i = 0; i < nombreDeTaches; i++) {
        if (strcmp(taches[i].priorite, prioriteFiltree) == 0) {
            printf("Tache %d:\n", i + 1);
            printf("  Titre: %s\n", taches[i].titre);
            printf("  Description: %s\n", taches[i].description);
            printf("  Date d'echeance: %s\n", taches[i].dateecheance);
            trouve = 1;
        }
    }
    if (!trouve) {
        printf("Aucune tache trouvee avec cette priorite.\n");
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
                afficherListesTaches();
                break;  
            case 3:
                modifierTache();
                break;
            case 4:
                supprimerTache();
                break;
            case 5:
                filtrerParPriorite();
                break;
            case 6:
                printf("Au revoir !\n");
                exit(0);
            default:
                printf("Option invalide, veuillez reessayer.\n");
        }
    } while (1);

    return 0;
}