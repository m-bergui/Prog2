#include <stdio.h>
#include <stdlib.h>

int main() {
    int Vn = 2, n, somme;

    // Saisie de la valeur de 'n' avec vérification
    do {
        printf("Entrez une valeur positive pour N : ");
        scanf("%i", &n);
    } while (n < 0);  // Répète la saisie tant que 'n' est inférieur à 0
    
    // Initialisation de la somme avec la première valeur de Vn
    somme = Vn;

    // Boucle pour calculer les termes de la suite et leur somme
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            Vn += 2;  // Si l'indice 'i' est pair, on ajoute 2 à Vn
        } else {
            Vn += 4;  // Si l'indice 'i' est impair, on ajoute 4 à Vn
        }
        somme += Vn;  // Ajoute le terme actuel de Vn à la somme totale
    }
    
    // Affichage des résultats
    printf("Le Nième terme de la suite Vn est : %i\n", Vn);
    printf("La somme des %i premiers termes de la suite est : %i\n", n + 1, somme);

    return 0;
}
