#include <stdio.h>

// Déclaration de la fonction fct
float fct(float x) {
    // Calcul de la formule : (x^2 + 1) / 2
    return (x * x + 1) / 2;
}

int main() {
    float x, resultat;

    // Demande de saisie de x par l'utilisateur
    printf("Entrez une valeur pour x : ");
    scanf("%f", &x);

    // Appel de la fonction fct pour calculer le résultat
    resultat = fct(x);

    // Affichage du résultat
    printf("Le résultat de la formule (x^2 + 1) / 2 pour x = %.2f est : %.2f\n", x, resultat);

    return 0;
}
