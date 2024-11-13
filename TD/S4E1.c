#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, tmp, chiffre = 0;

    // Demander à l'utilisateur de saisir un entier
    printf("Entrez un entier : ");
    scanf("%d", &n);

    // Prendre la valeur absolue de n pour gérer les nombres négatifs
    tmp = abs(n);

    // Calculer le nombre de chiffres de l'entier
    while (tmp > 0)
    {
        tmp = tmp / 10;  // Diviser n par 10 à chaque itération
        chiffre++;       // Incrémenter le compteur de chiffres
    }

    // Créer un tableau pour stocker les chiffres
    int t[chiffre];

    // Remplir le tableau avec les chiffres de n (de droite à gauche)
    for (int i = chiffre - 1; i >= 0; i--)
    {
        t[i] = n % 10;  // Récupérer le dernier chiffre de n
        n = n / 10;     // Supprimer le dernier chiffre de n
    }
    
    // Affichage du tableau Tp sous la forme spécifiée
    printf("T = |");
    for (int i = 0; i < chiffre; i++)
    {
        printf(" %d |", t[i]);  // Afficher chaque chiffre avec des barres verticales
    }
    
    return 0;
}
