#include <stdio.h>

int main() {
    // Valeur absolue
    float nombre;

    // Saisie du nombre par l'utilisateur
    printf("Entrez un nombre réel : ");
    scanf("%f", &nombre);

    // Structure de sélection complète pour calculer la valeur absolue
    if (nombre < 0) {
        nombre = -nombre;   // Si le nombre est négatif, on le rend positif
    } else {
        // Si le nombre est déjà positif ou égal à 0, aucun changement n'est nécessaire
        nombre = nombre;
    }

    // Structure de sélection simple pour calculer la valeur absolue
    // if (nombre < 0) {
    //     nombre = -nombre;  // Si le nombre est négatif, on le rend positif
    // }
    

    // Opérateur ternaire pour calculer la valeur absolue de manière concise
    // nombre = (nombre < 0) ? -nombre : nombre;

    // Affichage de la valeur absolue
    printf("La valeur absolue est : %.2f\n", nombre);
    // Fin Valeur absolue

    // Maximum de 3 entiers
    int a, b, c, max;

    // Saisie des 3 entiers
    printf("Entrez trois nombres entiers : ");
    scanf("%d %d %d", &a, &b, &c);

    // Trouver le maximum parmi les trois nombres en utilisant des conditions simples
    max = a;  // On suppose initialement que 'a' est le maximum

    if (b > max) {
        max = b;  // Si 'b' est plus grand que 'a', 'b' devient le maximum
    }
    if (c > max) {
        max = c;  // Si 'c' est plus grand que le maximum actuel, 'c' devient le maximum
    }

    // max = (a >= b && a >= c) ? a : (b >= c ? b : c);
    // La condition  (a >= b && a >= c) ? a : Vérifie si a est supérieur ou égal à b ET c. Si cette condition est vraie, a est attribué à max.
    // Sinon, Si a n'est pas le plus grand, on vérifie si b est supérieur ou égal à c (b >= c ? b : c).
        // Si b >= c est vrai, alors b est attribué à max.
        // Sinon, c est le plus grand et est attribué à max.

    // Affichage du maximum
    printf("Le maximum des trois nombres est : %d\n", max);

    return 0;
}
