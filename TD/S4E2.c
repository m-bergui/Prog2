#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;

    // Demander à l'utilisateur d'entrer la taille du tableau
    do{
        printf("Entrez la taille du tableau: ");
        scanf("%d", &N);

        // Vérifier si la taille est valide (entre 1 et 20)
        if (N > 20 || N < 1)
            printf("Erreur: La taille du tableau doit être entre 1 et 20.\n");

    }while (N < 1 || N > 20);  // Répéter la demande si la taille est invalide
    
    int T[N];  // Déclaration du tableau de taille N

    // Remplir le tableau avec des valeurs saisies par l'utilisateur
    for (int i = 0; i < N; i++)
    {
        printf("Entrez la valeur de T[%d] :", i);
        scanf("%d", &T[i]);
    }
    
    int count = 1;  // Initialisation du compteur des sous-séquences croissantes

    // Vérifier les éléments du tableau pour compter les sous-séquences strictement croissantes
    for (int i = 0; i < N - 1; i++)
    {
        // Si l'élément actuel est plus grand que le suivant, on a trouvé une sous-séquence croissante
        if (T[i] > T[i + 1])
        {
            // Affichage de la sous-séquence trouvée
            printf("T[%d] = %d > T[%d] = %d\n", i, T[i], i+1, T[i+1]);
            count++;  // Incrémenter le compteur
        }
    }

    // Affichage du nombre total de sous-séquences strictement croissantes
    printf("Le nombre de sous-sequences strictement croissantes du tableau est %d.\n", count);
    
    return 0;
}
