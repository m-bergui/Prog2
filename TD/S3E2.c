#include <stdio.h> 

// Fonction pour calculer la factorielle de n de manière itérative
int fact(int n) {  
    int fact = 1;
    // Calcul de la factorielle de n
    for (int i = 1; i <= n; i++) {
        fact *= i;  // Multiplier fact par i à chaque itération
    }
    return fact;  // Retourner la factorielle calculée
}

// Fonction pour calculer la factorielle de n de manière récursive
int recfact(int n){
    if (n <= 1)  // Cas de base : la factorielle de 1 ou 0 est 1
        return 1;

    return n * recfact(n - 1);  // Appel récursif : n * (n-1) * (n-2) * ... * 1
}

// Fonction pour calculer le nombre de combinaisons (i parmi n), C(n, i)
int comb(int i, int n){
    // Utilisation de la formule C(n, i) = n! / (i! * (n-i)!)
    return fact(n) / (fact(i) * fact(n - i));
}

// Fonction pour afficher le triangle de Pascal jusqu'à la ligne n
void pascal(int n) {
    for (int i = 0; i <= n; i++) {  // Parcourir chaque ligne du triangle
        for (int j = 0; j <= i; j++) {  // Pour chaque élément dans la ligne
            printf("%d\t", comb(j, i));  // Afficher C(i, j)
        }
        printf("\n");  // Passer à la ligne suivante après avoir affiché tous les éléments de la ligne
    }
}

int main(int argc, char const *argv[]) {
    int n, i;

    // Demander à l'utilisateur de saisir la valeur de n
    printf("Saisir la valeur de n : ");
    scanf("%d", &n);

    // Afficher la factorielle de n
    printf("Le factorielle de %d est %d.\n", n, fact(n));

    // Afficher la factorielle de n de manière récursive
    printf("(Recursive) Le factorielle de %d est %d.\n", n, recfact(n));

    // Demander à l'utilisateur de saisir la valeur de i
    printf("Donner i: "); 
    scanf("%d", &i);

    // Afficher le nombre de combinaisons C(n, i)
    printf("\nComb(%d, %d) = %d\n\n", i, n, comb(i, n));

    // Afficher le triangle de Pascal jusqu'à la ligne n
    pascal(n);

    return 0;
}
