#include <stdio.h>
#include <stdlib.h>

// Fonction pour lire les valeurs d'un tableau
void Lire_Tab(int *T, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("Entrez la valeur de T[%d]: ", i);
        scanf("%d", &T[i]);
    }
}

// Fonction pour afficher les valeurs d'un tableau
void Afficher_Tab(int *T, int N)
{
    printf("\nTableau: ");
    for (int i = 0; i < N; i++)
    {
        printf("| %d ", T[i]);
    }
    printf("|\n\n");
}

// Fonction pour rechercher un élément dans un tableau
// Retourne l'indice de la première occurrence, ou -1 si l'élément n'est pas trouvé
int Recherche(int *T, int N, int V)
{
    for (int i = 0; i < N; i++)
    {
        if (T[i] == V)
        {
            return i; // Retourner l'indice de l'élément
        }
    }
    return -1; // Si l'élément n'est pas trouvé, retourner -1
}

// Fonction pour trier un tableau avec l'algorithme de tri à bulle (Bubble Sort)
void Tri_Bulle(int *T, int N)
{
    int tmp, echange;

    // Tri à bulle: à chaque itération, on place l'élément le plus grand à la fin du tableau
    for (int i = 0; i < N-1; i++)
    {
        echange = 0;  // Variable pour vérifier si un échange a eu lieu
        for (int j = 0; j < N-1-i; j++)
        {
            if (T[j] > T[j+1])  // Si l'élément actuel est plus grand que le suivant
            {
                // Échanger les éléments
                tmp = T[j+1];
                T[j+1] = T[j];
                T[j] = tmp;
                echange = 1;  // Marquer qu'un échange a eu lieu
                Afficher_Tab(T, N);  // Afficher l'état du tableau après l'échange
            }
        }
        printf("--------------------------\n");
        if (echange == 0)  // Si aucun échange n'a eu lieu, le tableau est déjà trié
        {
            break;
        }
    }
}

// Fonction pour trier un tableau avec l'algorithme de tri par sélection (Selection Sort)
void Tri_Selection(int *T, int N)
{
    int index_Min, temp;

    // Tri par sélection: on trouve le plus petit élément et on le place au début du tableau
    for (int i = 0; i < N - 1; i++)
    {
        index_Min = i;  // Initialiser index_Min à l'index de l'élément non trié
        // Trouver l'élément le plus petit dans la partie non triée
        for (int j = i + 1; j < N; j++)
        {
            if (T[j] < T[index_Min])  // Si l'élément j est plus petit que l'élément à index_Min
            {
                index_Min = j;  // Mettre à jour index_Min
            }
        }

        // Échanger l'élément le plus petit avec l'élément à l'index i
        temp = T[index_Min];
        T[index_Min] = T[i];
        T[i] = temp;

        Afficher_Tab(T, N);  // Afficher l'état du tableau après l'échange
        printf("--------------------------\n");
    }
}

int main()
{
    int N, V, occu;

    // Contrôle de saisie de la taille du tableau T
    do
    {
        printf("\nEntrer la taille du Tableau T: ");
        scanf("%d", &N);
        if (N < 1)
            printf("Erreur: La taille du tableau doit être supérieure à 0.\n");
    } while (N < 1);

    // Allocation dynamique de mémoire pour le tableau T
    int *T = (int *)malloc(N * sizeof(int));

    // Lecture des valeurs du tableau
    Lire_Tab(T, N);

    // Affichage du tableau
    Afficher_Tab(T, N);

    // Recherche d'un élément dans le tableau
    printf("\nEntrer une valeur à rechercher dans le Tableau T: ");
    scanf("%d", &V);

    // Appel de la fonction Recherche
    occu = Recherche(T, N, V);

    if (occu == -1)
    {
        printf("%d n'existe pas dans le tableau.\n", V);
    }
    else
    {
        printf("L'indice de la première occurrence de %d dans le tableau est %d.\n", V, occu);
    }

    Afficher_Tab(T, N);
    // Tri du tableau avec l'algorithme de tri à bulle
    //Tri_Bulle(T, N);

    // Tri du tableau avec l'algorithme de tri par selection
    Tri_Selection(T, N);

    // Affichage du tableau trié
    Afficher_Tab(T, N);

    // Libération de la mémoire allouée pour le tableau
    free(T);

    return 0;
}
