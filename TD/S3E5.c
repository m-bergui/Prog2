#include <stdio.h> 

/* Fonction récursive pour calculer le nombre de combinaisons */
int C(int i, int n) 
{
    // Cas de base : C(i, 0) = 1 et C(n, n) = 1
    if (i == 0 || n == i)  
        return 1; 
    // Appel récursif basé sur la relation de récurrence
    return ( C(i, n-1) + C(i-1, n-1) ); 
}

int main(int argc, char const *argv[])
{
    int i, n; 
    // Saisie des valeurs de n et i
    printf("Donner n: "); 
    scanf("%d", &n);
    printf("Donner i: "); 
    scanf("%d", &i); 
    
    // Affichage du résultat de la combinaison C(i, n)
    printf("\nC(%d, %d) = %d\n\n", i, n, C(i, n)); 
    
    return 0;
}
