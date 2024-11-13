#include <stdio.h>
#include <stdlib.h>

// Fonction pour calculer le Nième terme de la suite Vn
int vnCalculator(int n){
    if (n == 0)
        return 2; // Base de la récursion : V0 = 2
    
    if(n % 2 == 0)
        return vnCalculator(n-1) + 2; // Si n est pair, ajouter 2
    else
        return vnCalculator(n-1) + 4; // Si n est impair, ajouter 4
}

// Fonction pour calculer la somme des n premiers termes de la suite Vn
int sumCalculator(int n)
{
    if(n == 0)
        return vnCalculator(0); // Base de la récursion : somme = V0
    
    // Calcul de la somme des termes de 0 à n
    return vnCalculator(n) + sumCalculator(n-1);
}

int main()
{
    int Vn, n, somme;

    // Demander à l'utilisateur de saisir un nombre entier positif n
    do
    {
        printf("Entrer la valeur de N: ");
        scanf("%d", &n);
    } while (n < 0); // Valider que n est positif
    
    // Calculer le Nième terme de la suite Vn
    Vn = vnCalculator(n);

    // Calculer la somme des n premiers termes de la suite
    somme = sumCalculator(n);
    
    // Afficher les résultats
    printf("Le Nième terme de la suite Vn est : %i\n", Vn);
    printf("La somme des %i premiers termes de la suite est: %i\n", n+1, somme);
    
    return 0;
}
