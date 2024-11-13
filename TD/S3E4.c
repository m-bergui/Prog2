#include <stdio.h>
#include <stdlib.h>

// Fonction Max_Min qui prend des pointeurs vers n, min et max
void Max_Min(int *n, int *min, int *max) {
    int nombre;  // Variable pour stocker les entiers saisis

    // Demande à l'utilisateur de saisir les n entiers
    printf("Entrez %d entiers :\n", *n);
    // Lecture du premier entier
    scanf("%d", &nombre);

    // Initialisation du min et max avec le premier entier
    *min = nombre;
    *max = nombre;

    // Lecture des autres entiers et mise à jour du min et du max
    for (int i = 1; i < *n; i++) {
        scanf("%d", &nombre);  // Lecture d'un entier
        if (nombre > *max)      // Si l'entier est supérieur à max, on met à jour max
            *max = nombre;
        if (nombre < *min)      // Si l'entier est inférieur à min, on met à jour min
            *min = nombre;
    }
}

int main(int argc, char const *argv[]) {
    // Méthode 1 : Utilisation de variables locales
    int n, min, max; 
    // Contrôle de saisie pour s'assurer que n est positif
    do {   
        printf("Saisir n>0 : "); 
        scanf("%d", &n); 
    } while (n <= 0);  // S'assurer que n est positif

    // Appel de la fonction Max_Min avec l'adresse de n, min et max
    Max_Min(&n, &min, &max);
    // Affichage des résultats
    printf("\nLe max = %d ", max);
    printf("\nLe min = %d\n", min);

    // Méthode 2 : Utilisation de la mémoire dynamique
    int n1, *min1, *max1;

    // Allocation dynamique de mémoire pour min1 et max1
    min1 = (int*)malloc(sizeof(int));
    max1 = (int*)malloc(sizeof(int));

    // Contrôle de saisie pour s'assurer que n1 est positif
    do {   
        printf("Saisir n>0 : "); 
        scanf("%d", &n1); 
    } while (n1 <= 0);  // S'assurer que n1 est positif

    // Appel de la fonction Max_Min avec l'adresse de n1, min1 et max1
    Max_Min(&n1, min1, max1);
    // Affichage des résultats
    printf("\nLe max = %d ", *max1);
    printf("\nLe min = %d\n", *min1);

    // Libération de la mémoire allouée dynamiquement
    free(max1);
    free(min1);
    
    // Méthode 3 : Utilisation de la mémoire dynamique pour n2, min2 et max2
    int *n2, *min2, *max2;

    // Allocation dynamique de mémoire pour n2, min2 et max2
    n2 = (int*)malloc(sizeof(int));
    min2 = (int*)malloc(sizeof(int));
    max2 = (int*)malloc(sizeof(int));

    // Contrôle de saisie pour s'assurer que n2 est positif
    do {   
        printf("Saisir n>0 : "); 
        scanf("%d", n2);  // Lecture de n2 (par référence)
    } while (*n2 <= 0);  // S'assurer que n2 est positif

    // Appel de la fonction Max_Min avec les adresses de n2, min2 et max2
    Max_Min(n2, min2, max2);
    // Affichage des résultats
    printf("\nLe max = %d ", *max2);
    printf("\nLe min = %d\n", *min2);

    // Libération de la mémoire allouée dynamiquement
    free(n2);
    free(max2);
    free(min2);

    return 0;
}
