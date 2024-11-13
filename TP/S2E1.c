#include <stdio.h>
#include <stdlib.h>

// This one is from last year I belive, has the sum, product and average of N integer.

int main() {
    int N;
    int *pSum, *pProduct;
    float *pAverage;

    // Demander à l'utilisateur le nombre d'entiers à saisir
    do {
        printf("Entrez le nombre d'entiers (N > 0) : ");
        scanf("%d", &N);
        if (N <= 0) {
            printf("Erreur: Le nombre N doit être strictement positif.\n");
        }
    } while (N <= 0);

    // Allouer dynamiquement de la mémoire pour la somme, le produit et la moyenne
    pSum = (int*)malloc(sizeof(int));       // Pointeur pour la somme
    pProduct = (int*)malloc(sizeof(int));   // Pointeur pour le produit
    pAverage = (float*)malloc(sizeof(float)); // Pointeur pour la moyenne

    // Initialisation de la somme et du produit
    *pSum = 0;
    *pProduct = 1;

    // Saisie des entiers et calculs
    printf("Entrez %d entiers :\n", N);
    for (int i = 0; i < N; i++) {
        int num;
        printf("Entier %d : ", i + 1);
        scanf("%d", &num);
        *pSum += num;         // Ajoute à la somme
        *pProduct *= num;     // Multiplie au produit
    }

    // Calcul de la moyenne
    *pAverage = (float)(*pSum) / N;

    // Affichage des résultats
    printf("La somme des %d entiers est : %d\n", N, *pSum);
    printf("Le produit des %d entiers est : %d\n", N, *pProduct);
    printf("La moyenne des %d entiers est : %.2f\n", N, *pAverage);

    // Libération de la mémoire allouée
    free(pSum);
    free(pProduct);
    free(pAverage);

    return 0;
}
