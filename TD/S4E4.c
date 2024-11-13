#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void saisieMatrice(int **M, int n) {
    printf("Entrez les valeurs de la matrice M(%d, %d).\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("M[%d][%d] : ", i, j);
            scanf("%d", &M[i][j]);
        }
        printf("\n");
    }
}

void afficheMatrice(int **M, int n) {
    for (int i = 0; i < n; i++) {
        printf("|");
        for (int j = 0; j < n; j++) {
            printf(" %d ", M[i][j]);
        }
        printf("|\n");
    }
}

int MDD(int **M, int n) {
    int sum;
    // On parcourt chaque ligne
    for (int i = 0; i < n; i++) {
        sum = 0;
        // On calcule la somme des valeurs absolues des éléments hors-diagonale
        for (int j = 0; j < n; j++) {
            if (i != j) {  // On exclut l'élément diagonal
                sum += abs(M[i][j]);
            }
        }
        // Vérifier si la diagonale dominante stricte est satisfaite
        if (abs(M[i][i]) <= sum) {
            return 0;  // Retourner 0 si la condition n'est pas remplie
        }
    }
    return 1;  // Retourner 1 si toutes les lignes satisfont la condition
}

int main() {
    int n;
    
    // Demander à l'utilisateur de saisir la taille de la matrice
    printf("Entrez la taille de la matrice M(n,n) : ");
    scanf("%d", &n);
    
    // Allocation dynamique pour la matrice M
    int** M = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        M[i] = (int*)malloc(n * sizeof(int));
    }

    // Saisie de la matrice
    saisieMatrice(M, n);
    
    // Affichage de la matrice
    printf("Matrice M:\n");
    afficheMatrice(M, n);

    // Vérification si la matrice est diagonale dominante stricte par lignes
    if (MDD(M, n) == 1) {
        printf("La matrice M est diagonale dominante stricte par lignes.\n");
    } else {
        printf("La matrice M n'est pas diagonale dominante stricte par lignes.\n");
    }

    // Libération de la mémoire allouée pour la matrice
    for (int i = 0; i < n; i++) {
        free(M[i]);
    }
    free(M);

    return 0;
}
