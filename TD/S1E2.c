#include <stdio.h>

int main() {
    int a, b, reste;

    // Saisie des deux entiers a et b, avec la condition que a >= b
    do {
        printf("Entrez deux nombres entiers (a >= b) : ");
        scanf("%d %d", &a, &b);

        // Vérification que 'a' est bien supérieur ou égal à 'b'
        if (a < b) {
            printf("Erreur : a doit être supérieur ou égal à b. Veuillez réessayer.\n");
        }
    } while (a < b);  // Recommence la saisie tant que 'a' est inférieur à 'b'

    // Algorithme de divisions successives pour calculer le PGCD
    do {
        reste = a % b;  // Calcul du reste de la division de 'a' par 'b'
        
        if (reste != 0) {
            // Si le reste n'est pas nul, on continue le processus
            a = b;      // 'a' prend la valeur de 'b'
            b = reste;  // 'b' prend la valeur du reste
        }
    } while (reste != 0);  // Boucle tant que le reste est différent de zéro

    // Affichage du PGCD, qui est la dernière valeur de 'b'
    printf("Le PGCD est : %d\n", b);

    return 0;
}
