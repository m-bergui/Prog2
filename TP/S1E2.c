#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, i, premier;

    // Saisie de l'utilisateur avec vérification de la positivité
    do {
        printf("Entrez un nombre strictement positif: ");
        scanf("%d", &N);
        if (N <= 0) {
            printf("Erreur: Veuillez entrer un nombre strictement positif.\n");
        }
    } while (N <= 0);

    // Cas particulier où N est égal à 1
    if (N == 1) {
        printf("Il n'y a pas de nombre premier inférieur à 1.\n");
        return 0; // Fin du programme si N = 1
    }

    // Recherche du plus grand nombre premier inférieur à N
    for (i = N - 1; i > 1; i--) {
        premier = 1; // Initialisation de l'indicateur de primalité

        // Vérification de la primalité de i
        for (int j = 2; j * j <= i; j++) { // On teste jusqu'à √i pour optimiser
            if (i % j == 0) {
                premier = 0; // i n'est pas premier
                break;
            }
        }

        // Si i est premier, on affiche et on sort de la boucle
        if (premier) {
            printf("Le plus grand nombre premier inférieur à %d est: %d\n", N, i);
            break;
        }
    }

    // Si aucun nombre premier n'est trouvé (cas où N <= 2)
    if (i == 1) {
        printf("Il n'y a pas de nombre premier inférieur à %d.\n", N);
    }

    return 0;
}
