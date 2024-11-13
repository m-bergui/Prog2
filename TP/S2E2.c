#include <stdio.h>
#include <math.h>

#include <stdio.h>
#include <math.h>

void Signe(float A, float B) 
{
    // Cas où la somme est positive :
    // 1. Si les deux nombres sont positifs.
    // 2. Si A est négatif, B est positif et la valeur absolue de A est inférieure à celle de B.
    // 3. Si A est positif, B est négatif et la valeur absolue de A est supérieure à celle de B.
    if ((A >= 0 && B >= 0) || (A <= 0 && B >= 0 && fabs(A) < fabs(B)) || (A >= 0 && B <= 0 && fabs(A) > fabs(B)))
        printf("Le signe de la somme %.2f + %.2f est positif\n", A, B);
    // Cas où la somme est négative :
    // 1. Si les deux nombres sont négatifs.
    // 2. Si A est négatif, B est positif et la valeur absolue de A est supérieure à celle de B.
    // 3. Si A est positif, B est négatif et la valeur absolue de A est inférieure à celle de B.
    else if ((A <= 0 && B <= 0) || (A <= 0 && B >= 0 && fabs(A) > fabs(B)) || (A >= 0 && B <= 0 && fabs(A) < fabs(B)))
        printf("Le signe de la somme %.2f + %.2f est negatif\n", A, B);
    // Cas où la somme est nulle :
    // Si A et B ont des valeurs opposées et de même magnitude (A + B = 0).
    else
        printf("La somme %f + %f est zéro\n", A, B);
}

int Check(int x, int y, int n) {
    // Vérifier si x ou y sont compris entre 0 et n-1
    if ((x >= 0 && x < n) || (y >= 0 && y < n)) {
        return 1;  // Retourne vrai (1) si l'une des conditions est vraie
    } else {
        return 0;  // Retourne faux (0) sinon
    }
}

int main() {
    float A, B;

    printf("Entrez la valeur de A : ");
    scanf("%f", &A);

    printf("Entrez la valeur de B : ");
    scanf("%f", &B);

    Signe(A, B);

    int x, y, n;

    printf("Entrez la valeur de x : ");
    scanf("%d", &x);

    printf("Entrez la valeur de y : ");
    scanf("%d", &y);

    printf("Entrez la valeur de n : ");
    scanf("%d", &n);

    // Appel à la fonction Check
    int result2 = Check(x, y, n);
    
    // Affichage du résultat
    if (result2 != 0) {
        printf("%d ou %d sont compris entre 0 et %d.\n", x, y, n-1);
    } else {
        printf("%d et %d ne sont pas compris entre 0 et %d.\n", x, y, n-1);
    }

    return 0;
}
/*
Testing:
Case 1: Both positive
Input: a = 5, b = 3
Output: Positif
Case 2: Both negative
Input: a = -4, b = -1
Output: Negatif
Case 3: One positive, one negative
Input: a = 10, b = -4
Output: Positif
Case 4: Magnitudes are equal (result is zero)
Input: a = 4, b = -4
Output: Positif
Case 5: One number is zero
Input: a = 0, b = 5
Output: Positif
*/