#include <stdio.h>

// Fonction avancée qui augmente la valeur de x de 1, mais ne modifie pas la valeur de x dans la fonction main
void avancer1(int x) {
    x += 1;  // x est local à la fonction et n'affecte pas le x de la fonction main
}

// Fonction avancée qui prend un pointeur vers x et augmente la valeur de x de 2
int avancer2(int *x) {
    *x += 2;  // Modifie directement la valeur pointée par x
    return *x;  // Retourne la nouvelle valeur de x
}

// Fonction reculer qui prend x en paramètre, mais ne modifie pas x dans la fonction main
void reculer2(int x) {
    x -= 2;  // x est local à la fonction et n'affecte pas le x de la fonction main
}

// Fonction reculer qui prend un pointeur vers x et diminue la valeur de x de 3
int reculer3(int *x) {
    *x -= 3;  // Modifie directement la valeur pointée par x
    return *x;  // Retourne la nouvelle valeur de x
}

// Fonction principale
int main() {
    int x = 6, y = 1;

    // Appel de avancer1, mais la valeur de x dans main ne change pas
    avancer1(x);
    printf("\n x=%d", x); // Affiche x = 6 car avancer1 ne modifie pas x dans main

    // Appel de avancer2, y est passé par adresse et sa valeur est modifiée
    x = avancer2(&y);  // x prend la valeur retournée par avancer2 (y + 2)
    printf("\n\n y=%d", y); // Affiche y = 3 car avancer2 ajoute 2 à y
    printf("\n x=%d", x); // Affiche x = 3 car x prend la valeur retournée par avancer2

    // Appel de reculer2, mais la valeur de y dans main ne change pas
    reculer2(y);
    printf("\n\n y=%d", y); // Affiche y = 3 car reculer2 ne modifie pas y dans main

    // Appel de avancer2 à nouveau, cette fois x est passé par adresse
    y = avancer2(&x);  // x est modifié dans main et y prend la nouvelle valeur de x
    printf("\n\n y=%d", y); // Affiche y = 5 car avancer2 ajoute 2 à x
    printf("\n x=%d", x); // Affiche x = 5 car x est modifié par avancer2

    // Appel de reculer3, x est passé par adresse et est diminué de 3
    y = reculer3(&x);  // x est modifié directement et la valeur retournée est assignée à y
    printf("\n\n y=%d", y); // Affiche y = 2 car x a été diminué de 3
    printf("\n x=%d", x); // Affiche x = 2 car x a été diminué de 3 par reculer3

    // Appel de reculer3 sur y cette fois, y est modifié
    x = reculer3(&y);  // y est diminué de 3, et la nouvelle valeur est assignée à x
    printf("\n\n x=%d", x); // Affiche x = -1 car y a été diminué de 3
    printf("\n y=%d", y); // Affiche y = -1 car y a été diminué de 3

    return 0;
}
