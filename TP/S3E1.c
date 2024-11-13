#include <stdio.h>
#include <math.h>

// Fonction pour afficher le tableau
void afficher_tab(float *tab, int n){
    printf("\nTableau : ");
    for (int i = 0; i < n; i++) {
        printf("| tab[%d] = %.2f", i, tab[i]); // Affiche chaque élément du tableau avec un format de 2 décimales
    }
}

// Fonction pour saisir un tableau de réels non nuls
void saisie_tab(float *tab, int n){
    for (int i = 0; i < n; i++) {
        // Demande à l'utilisateur de saisir un réel non nul
        printf("Entrez un réel non nul pour l'élément %d : ", i + 1);
        scanf("%f", &tab[i]);
        
        // Si l'utilisateur saisit 0, il doit recommencer à saisir cet élément
        if (tab[i] == 0)
        {
            printf("La valeur ne peut pas être nulle. Veuillez réessayer. \n");
            i--; // Décrémente i pour refaire la saisie de cet élément
        }
    }
}

// Fonction pour calculer les indices de la valeur maximale et minimale
void max_min_indice(float tab[], int *indice_max, int *indice_min, int n){
    *indice_max = 0;  // Initialisation de l'indice maximum avec l'indice du premier élément
    *indice_min = 0;  // Initialisation de l'indice minimum avec l'indice du premier élément

    // Parcours du tableau pour trouver l'indice du maximum et du minimum
    for (int i = 1; i < n; i++)
    {
        if (tab[i] > tab[*indice_max])  // Si l'élément courant est plus grand que le maximum actuel
        {
            *indice_max = i;  // Mise à jour de l'indice du maximum
        }
        if (tab[i] < tab[*indice_min])  // Si l'élément courant est plus petit que le minimum actuel
        {
            *indice_min = i;  // Mise à jour de l'indice du minimum
        }
    } 
}

// Fonction pour calculer la somme du tableau
float somme_tab(float tab[], int n){
    float s = 0.0; // Initialisation de la somme
    // Addition de chaque élément du tableau
    for (int i = 0; i < n; i++)
    {
        s += tab[i];  // Ajoute l'élément courant à la somme
    }
    return s;  // Retourne la somme totale
}

// Fonction pour trouver l'indice de la valeur la plus proche de la moyenne
int indice_val_plus_proche(float tab[], int n, float moyenne){
    int indice_val = 0;  // Initialisation de l'indice de la valeur la plus proche avec 0
    for (int i = 1; i < n; i++)
    {
        // Compare la distance entre l'élément courant et la moyenne avec celle de la valeur précédente
        if (fabs(moyenne - tab[indice_val]) > fabs(moyenne - tab[i]))
        {
            indice_val = i;  // Si la distance est plus petite, on met à jour l'indice de la valeur la plus proche
        }
    }
    return indice_val;  // Retourne l'indice de la valeur la plus proche de la moyenne
}

int main() {
    int N;  // Dimension du tableau
    float tab[50];  // Déclaration d'un tableau de 50 éléments
    float somme = 0.0, moyenne;  // Variables pour la somme et la moyenne
    int indicemax, indicemin, indiceValeurProche;  // Variables pour les indices du max, du min, et de la valeur la plus proche

    // Saisie de la dimension du tableau (doit être entre 1 et 50)
    do {
        printf("Entrez la dimension N du tableau (N <= 50) : ");
        scanf("%d", &N);
    } while (N <= 0 || N > 50);  // Vérifie que la dimension est valide

    // Saisie des éléments du tableau de réels non nuls
    saisie_tab(tab, N);
    
    // Affichage du tableau
    afficher_tab(tab, N);

    // Calcul des indices du maximum et du minimum
    max_min_indice(tab, &indicemax, &indicemin, N);
    
    // Calcul de la somme et de la moyenne du tableau
    somme = somme_tab(tab, N);
    moyenne = somme / N;  // Moyenne = somme des éléments / nombre d'éléments

    // Trouver l'indice de la valeur la plus proche de la moyenne
    indiceValeurProche = indice_val_plus_proche(tab, N, moyenne);

    // Affichage des résultats
    printf("\n\nIndice et valeur maximale : indice %d, valeur %.2f\n", indicemax, tab[indicemax]);
    printf("Indice et valeur minimale : indice %d, valeur %.2f\n", indicemin, tab[indicemin]);
    printf("Moyenne du tableau : %.2f\n", moyenne);
    printf("Valeur la plus proche de la moyenne : %.2f\n", tab[indiceValeurProche]);

    return 0;
}
