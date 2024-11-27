#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure représentant un étudiant
typedef struct {
    char nom[30];  // Nom de l'étudiant
    float note;    // Note obtenue par l'étudiant
} Etudiant;

// Fonction pour lire les informations des étudiants
void LireTabEtudiant(Etudiant *T, int N) {
    printf("Saisie des noms et des notes des etudiants:\n\n");
    for (int i = 0; i < N; i++) {
        // Saisie du nom de l'étudiant
        printf("Donner le nom de l'etudiant %d: ", i+1);
        scanf("%s", T[i].nom);

        // Saisie de la note correspondante
        printf("Donner la note de %s: ", T[i].nom);
        scanf("%f", &T[i].note);
    }
    printf("\n\n");
}

// Fonction pour afficher le tableau des étudiants
void AfficherTabEtudiant(Etudiant *T, int N) {
    printf("Nom\tNotes\n");
    for (int i = 0; i < N; i++) {
        // Affiche le nom et la note de chaque étudiant
        printf("%s\t%.2f\n", T[i].nom, T[i].note);
    }
    printf("\n");
}

// Fonction pour calculer et afficher la moyenne des notes
void MoyennePromotion(Etudiant *T, int N) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        // Additionne toutes les notes des étudiants
        sum += T[i].note;
    }

    // Calcule et affiche la moyenne de la promotion
    printf("La moyenne de la promotion est : %.2f\n\n", sum / N);
}

// Fonction pour afficher les étudiants ayant validé le module
void ValiderModule(Etudiant *T, int N) {
    printf("Liste des etudiants ayant valide le module Algo et Prog 2:\n\n");
    printf("Nom\tNotes\n");
    for (int i = 0; i < N; i++) {
        // Affiche uniquement les étudiants ayant une note >= 10
        if (T[i].note >= 10.0) {
            printf("%s\t%.2f\n", T[i].nom, T[i].note);
        }
    }
    printf("\n");
}

// Fonction de tri par bulle pour trier les étudiants par nom (ordre alphabétique)
void TrierBulleTabEtudiant(Etudiant *T, int N) {
    Etudiant tempE;  // Variable temporaire pour les échanges
    int echange;     // Indique si un échange a eu lieu
    for (int i = 0; i < N - 1; i++) {
        echange = 0;
        for (int j = 0; j < N - 1 - i; j++) {
            if (strcmp(T[j].nom, T[j + 1].nom) > 0) {
                // Échange les étudiants si nécessaire
                tempE = T[j];
                T[j] = T[j + 1];
                T[j + 1] = tempE;
                echange = 1;
            }
        }
        if (echange == 0) {
            // Arrête le tri si aucune permutation n'est effectuée
            break;
        }
    }
    printf("Liste des etudiants classes par nom:\n\n");
    AfficherTabEtudiant(T, N);
}

// Fonction de tri par sélection pour trier les étudiants par note (ordre croissant)
void TrierSelectionTabEtudiant(Etudiant *T, int N) {
    Etudiant tempE;  // Variable temporaire pour les échanges
    int index_min;   // Index de l'élément minimum
    for (int i = 0; i < N - 1; i++) {
        index_min = i;
        for (int j = i + 1; j < N; j++) {
            if (T[j].note < T[index_min].note) {
                // Mise à jour de l'index de l'élément minimum
                index_min = j;
            }
        }
        // Échange des éléments si un plus petit est trouvé
        tempE = T[index_min];
        T[index_min] = T[i];
        T[i] = tempE;
    }
    printf("Liste des etudiants classes par note:\n\n");
    AfficherTabEtudiant(T, N);
}

int main(int argc, char const *argv[]) {
    Etudiant *T;  // Pointeur vers un tableau dynamique d'étudiants
    int N;        // Nombre d'étudiants

    // Saisie de la taille du tableau
    printf("Entrez la taille du tableau des etudiants: ");
    scanf("%d", &N);

    // Allocation dynamique de mémoire pour le tableau
    T = (Etudiant*)malloc(N * sizeof(Etudiant));

    // Lecture des informations des étudiants
    LireTabEtudiant(T, N);

    // Affichage initial du tableau
    AfficherTabEtudiant(T, N);

    // Tri par bulle et affichage
    TrierBulleTabEtudiant(T, N);

    // Tri par sélection et affichage
    TrierSelectionTabEtudiant(T, N);

    // Calcul et affichage de la moyenne de la promotion
    MoyennePromotion(T, N);

    // Affichage des étudiants ayant validé le module
    ValiderModule(T, N);

    // Libération de la mémoire allouée
    free(T);

    return 0;
}
