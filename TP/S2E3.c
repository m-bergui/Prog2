#include <stdio.h>

// Fonction Max_Min qui calcule le maximum et le minimum
void Max_Min(int a, int b, int *max, int *min) {
    // Si a est plus grand que b, alors on assigne a à max et b à min
    if (a > b) {
        *max = a;  
        *min = b;  
    } else {
        // Sinon, si b est plus grand que a, alors on assigne b à max et a à min
        *max = b;  
        *min = a;  
    }
}

int main() {
    int a, b, max, min;

    // Saisie des deux entiers
    printf("Entrez la valeur de a : ");
    scanf("%d", &a);  
    printf("Entrez la valeur de b : ");
    scanf("%d", &b);  

    // Appel de la fonction Max_Min pour calculer le max et le min
    Max_Min(a, b, &max, &min);

    // Affichage des résultats
    printf("Le maximum est : %d\n", max);
    printf("Le minimum est : %d\n", min); 

    return 0;  // Fin du programme
}
