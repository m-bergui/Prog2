#include <stdio.h>
#include <stdlib.h>

// Fonction pour afficher les éléments du tableau
void afficher_tab(int *tab, int n) {
    // Affiche chaque élément du tableau avec son indice
    printf("\nTableau :\n");
    for (int i = 0; i < n; i++) {
        printf("T[%d] = %d\n", i, tab[i]);
    }
}

// Fonction pour rechercher l'indice de la première occurrence de la valeur v dans le tableau
int rechercheVal(int *tab, int n, int v) {
    // Parcourt le tableau pour trouver la première position où la valeur v apparaît
    for (int i = 0; i < n; i++) {
        if (tab[i] == v) {  // Si l'élément à l'indice i est égal à v
            return i;       // Retourne l'indice de la première occurrence
        }
    }
    return -1;  // Retourne -1 si v n'est pas dans le tableau
}

// Fonction pour afficher toutes les occurrences de v et leurs indices
void afficher_occurance(int *tab, int n, int v) {
    int occu = 0;  // Variable pour compter le nombre d'occurrences de v
    printf("Indices des occurrences de %d : ", v);
    for (int i = 0; i < n; i++) {
        if (tab[i] == v) {  // Si l'élément à l'indice i est égal à v
            printf("%d \t", i);  // Affiche l'indice de l'occurrence trouvée
            occu++;
        }
    }

    if (occu == 0) {  // Si aucune occurrence n'est trouvée
        printf("Aucune occurrence trouvée.");
    } else {
        printf("\nNombre total d'occurrences de %d : %d\n", v, occu);
    }
}

// Fonction pour supprimer la première occurrence de v dans le tableau
void supprimerVal(int *tab, int *n, int v) {
    int indice = rechercheVal(tab, *n, v);  // Recherche l'indice de la première occurrence de v

    if (indice == -1) {  // Si l'indice est -1, alors v n'est pas dans le tableau
        printf("La valeur %d n'existe pas dans le tableau.\n", v);
        return;
    }

    // Décale tous les éléments après l'occurrence trouvée pour supprimer cette valeur
    for (int i = indice; i < *n - 1; i++) {
        tab[i] = tab[i + 1];  // Déplace chaque élément vers la gauche
    }
    
    (*n)--;  // Réduit la taille logique du tableau
    printf("La première occurrence de la valeur %d a été supprimée.\n", v);
}

int main() {
    int *tab, n, v;

    // Demande la taille du tableau et s'assure qu'elle est positive
    do {
        printf("Entrez la taille du tableau (N) : ");
        scanf("%d", &n);
    } while (n <= 0);  // Assure que la taille est supérieure à 0

    // Allocation dynamique de mémoire pour le tableau
    tab = (int *)malloc(n * sizeof(int));

    // Demande à l'utilisateur de saisir les éléments du tableau
    printf("Entrez les éléments du tableau :\n");
    for (int i = 0; i < n; i++) {
        printf("T[%d] = ", i);
        scanf("%d", &tab[i]);
    }

    // Affiche le tableau initial
    afficher_tab(tab, n);

    // Demande la valeur V à rechercher dans le tableau
    printf("Entrez la valeur à rechercher (V) : ");
    scanf("%d", &v);

    // Appelle la fonction rechercheVal pour obtenir l'indice de la première occurrence
    int indice = rechercheVal(tab, n, v);
    if (indice != -1) {  // Si une occurrence est trouvée
        printf("La première occurrence de %d est à l'indice %d.\n", v, indice);
    } else {  // Si aucune occurrence n'est trouvée
        printf("La valeur %d n'existe pas dans le tableau.\n", v);
    }

    // Affiche toutes les occurrences de la valeur V et leurs indices
    afficher_occurance(tab, n, v);

    // Supprime la première occurrence de V dans le tableau
    supprimerVal(tab, &n, v);

    // Affiche le tableau après suppression
    afficher_tab(tab, n);

    // Libération de la mémoire allouée dynamiquement
    free(tab);

    return 0;
}
