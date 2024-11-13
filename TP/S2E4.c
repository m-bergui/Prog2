#include <stdio.h>

// Fonction qui affiche les entiers de 0 à 15 en hexadécimal
void aff_hexa() {
    for (int i = 0; i <= 15; i++) {
        printf("%X ", i);  // %X permet d'afficher en hexadécimal
    }
    printf("\n");
}

void aff_hexa1() {
    for (int i = 0; i <= 15; i++) {
        if (i < 10) {
            printf("%d ", i);  // Les chiffres de 0 à 9 sont les mêmes en hexadécimal
        } else {
            // Les chiffres de 10 à 15 sont représentés par les lettres A à F
            printf("%c ", 'A' + (i - 10));  
            // 'A' correspond à 10 en hexadécimal. Ajouter un entier à un caractère donne le caractère correspondant dans la table ASCII. 
            //  Par exemple, 'A' + 1 donne 'B', 'A' + 2 donne 'C', etc.
        }
    }
    printf("\n");
}

void hexa(int n) {
    // Si n est égal à 0, la fonction se termine (condition d'arrêt pour la récursion)
    if (n == 0) {
        return;  // Condition d'arrêt de la récursion
    }

    // Appel récursif de la fonction hexa avec n divisé par 16 (division entière)
    hexa(n / 16);

    // Calcul du reste de la division de n par 16 (pour obtenir le chiffre hexadécimal)
    int reste = n % 16;

    // Si le reste est inférieur à 10, cela signifie que c'est un chiffre entre 0 et 9
    if (reste < 10) {
        printf("%d", reste);  // Affiche les chiffres de 0 à 9
    } else {
        // Si le reste est supérieur ou égal à 10, il correspond à une lettre de A à F
        printf("%c", 'A' + (reste - 10));  // Affiche les lettres de A à F
        // 'A' est le caractère pour 10, 'B' pour 11, etc. 
        // La soustraction de 10 permet de récupérer l'indice de la lettre appropriée (0 = A, 1 = B, ..., 5 = F)
    }
}

int main() {
    printf("Les entiers de 0 à 15 en hexadécimal :\n");
    aff_hexa();  // Appel à la fonction aff_hexa
    aff_hexa1();  // Appel à la fonction aff_hexa1

    int n;

    // Demander à l'utilisateur d'entrer un entier tant que l'entier est <= 0
    do {
        printf("Entrer un entier (supérieur à 0) : ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("Erreur : l'entier doit être supérieur à 0.\n");
        }
    } while (n <= 0);

    printf("La représentation hexadécimale de %d est : ", n);
    hexa(n);  // Appel de la fonction récursive

    return 0;
}
