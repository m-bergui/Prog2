#include <stdio.h>

// Déclaration de la procédure message
void message(int n) {
    // Affiche "Bonjour MIP" n fois
    for (int i = 0; i < n; i++) {
        printf("Bonjour MIP\n");
    }
}

int main() {
    int n;

    // Demande de saisie de n par l'utilisateur
    printf("Entrez le nombre de répétitions : ");
    scanf("%d", &n);

    // Appel de la procédure message pour afficher "Bonjour MIP" n fois
    message(n);

    return 0;
}
