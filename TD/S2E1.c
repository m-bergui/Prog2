#include <stdio.h>
#include <stdlib.h> // Pour la fonction malloc

int main() {
    float x = 6, y = 4; 
    float *p1, *p2;

    //p1 = x; //-> Erreur : On ne peut pas assigner directement une valeur à un pointeur.
    p1 = &x; // Correction : p1 doit pointer vers l'adresse de x.

    // Allocation de mémoire
    p2 = (float *)malloc(sizeof(float)); // Correction : malloc prend la taille d'un type, ici un float.

    *p2 = 20; // Assigner la valeur 20 à l'espace mémoire pointé par p2.

    p1 = p2; // p1 pointe maintenant vers l'adresse où p2 pointe.

    *p1 = 300; // Modification de la valeur pointée par p1 (qui est aussi la même que p2) à 300.

    *p2 = 200; // Modification de la valeur pointée par p2 (qui est aussi la même que p1) à 200.

    //p1 = y;
    p1 = &y; // p1 pointe vers l'adresse de y

    // free(*p2); -> Erreur : free prend un pointeur, pas la valeur pointée.
    free(p2); // Correction : libérer la mémoire allouée dynamiquement à p2.

    p2 = &y; // p2 pointe maintenant vers l'adresse de y.

    return 0;
}