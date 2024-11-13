#include <stdio.h>
#include <stdlib.h>

// Fonction pour saisir les valeurs d'une matrice de dimensions n x m
void saisieMatrice(int** M, int n, int m) {
    printf("Entrez les valeurs de la matrice M(%d, %d).\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("M[%d][%d] : ", i, j);
            scanf("%d", &M[i][j]); // Saisie de chaque élément de la matrice
        }
        printf("\n");
    }
}

// Fonction pour transposer une matrice M dans une matrice MT
void transposeMatrice(int** M, int** MT, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            MT[j][i] = M[i][j]; // Place les éléments de M en position transposée dans MT
        }
    }
}

// Fonction pour afficher une matrice en utilisant l'indice direct
void afficheMatrice(int** M, int n, int m) {
    for (int i = 0; i < n; i++) {
        printf("|");
        for (int j = 0; j < m; j++) {
            printf(" %d ", M[i][j]); // Affiche chaque élément de la matrice
        }
        printf("|\n");
    }
}

// Fonction pour afficher une matrice en utilisant des pointeurs
void afficheMatricePointeurs(int** M, int n, int m) {
    for (int i = 0; i < n; i++) {
        printf("|");
        for (int j = 0; j < m; j++) {
            printf(" %d ", *(*(M + i) + j)); // Affiche chaque élément via un accès avec des pointeurs
        }
        printf("|\n");
    }
}

int main() {
    int m, n;
    
    // Demande à l'utilisateur de saisir les dimensions n et m de la matrice
    printf("Entrez les valeur de n et m pour la matrice M(n,m) : ");
    scanf("%d%d", &n, &m);
    
    // Allocation dynamique pour la matrice M de taille n x m
    int** M = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        M[i] = (int*)malloc(m * sizeof(int));
    }

    // Allocation dynamique pour la matrice transposée MT de taille m x n
    int** MT = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        MT[i] = (int*)malloc(n * sizeof(int));
    }

    // Saisie de la matrice M
    saisieMatrice(M, n, m);

    // Demo 

    // printf("M est un pointeur qui pointe sur un tableau de pointeurs\n\n");
    // printf("M = %X\t", M);
    // printf("M+1 = %X\n\n", M+1);
    // printf("*M = %X\t", *M);
    // printf("*(M+1) = %X\n\n", *(M+1));

    // printf("M[] est un tableau de pointeurs ou chaque pointeurs du tableau pointe sur un tableau de int\n\n");
    // printf("&M[0] = %X\t", &M[0]);
    // printf("&M[1] = %X\n\n", &M[1]);
    // printf("M[0] = %X\t", M[0]);
    // printf("M[1] = %X\n\n", M[1]);
    // printf("*M[0] = %X\t", *M[0]);
    // printf("*M[1] = %X\n\n", *M[1]);

    // printf("&M[0][0] = %X\t", &M[0][0]);
    // printf("&M[1][0] = %X\n", &M[1][0]);
    // printf("M[0][0] = %X\t", M[0][0]);
    // printf("M[1][0] = %X\n\n", M[1][0]);


    // printf("*(*(M+0)+0) = %X\t", *(*(M+0)+0));
    // printf("*(*(M+0)+1) = %X\n", *(*(M+0)+1));
    // printf("*(*(M+1)+0) = %X\t", *(*(M+1)+0));
    // printf("*(*(M+1)+1) = %X\n\n", *(*(M+1)+1));

    // Affiche la matrice M en utilisant deux méthodes d'affichage différentes
    printf("Affichage normal\n\n");
    afficheMatrice(M, n, m);
    printf("Affichage pointeurs\n\n");
    afficheMatricePointeurs(M, n, m);

    // Transpose la matrice M et affiche la matrice transposée MT
    transposeMatrice(M, MT, n, m);
    printf("\nMatrice Transposée :\n");
    afficheMatrice(MT, m, n);

    // Libération de la mémoire allouée pour M
    for (int i = 0; i < n; i++) {
        free(M[i]);
    }
    free(M);

    // Libération de la mémoire allouée pour MT
    for (int i = 0; i < m; i++) {
        free(MT[i]);
    }
    free(MT);

    return 0;
}

    
