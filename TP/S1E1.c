#include <stdio.h>

int main() {
    int code; // Code de l'activité (1: voiture neuve, 2: voiture d'occasion, 3: pièces de rechange, 4: réparations)
    float prix, commission;

    // Saisie du code d'activité avec vérification de validité
    do {
        printf("Entrez le code de l'activité (1-4): ");
        scanf("%d", &code);
        if (code < 1 || code > 4) {
            printf("Erreur: Le code d'activité doit être compris entre 1 et 4.\n");
        }
    } while (code < 1 || code > 4);  // Répéter jusqu'à obtenir un code valide

    // Message d'invite personnalisé selon le code d'activité
    switch (code) {
        case 1:
            printf("Entrez le prix de vente d'une voiture neuve: ");
            break;
        case 2:
            printf("Entrez le prix de vente d'une voiture d'occasion: ");
            break;
        case 3:
            printf("Entrez le prix des pièces de rechange: ");
            break;
        case 4:
            printf("Entrez le montant des réparations: ");
            break;
    }

    // Saisie du prix/montant avec vérification qu'il soit positif
    do {
        scanf("%f", &prix);
        if (prix <= 0) {
            printf("Erreur: Le montant doit être supérieur à 0. Veuillez ressaisir: ");
        }
    } while (prix <= 0);  // Répéter jusqu'à obtenir un montant valide

    // Calcul de la commission en fonction du code de l'activité
    switch(code) {
        case 1: // Vente de voitures neuves
            commission = prix * 0.02;
            if (commission > 5000) {
                commission = 5000; // Plafond de 5000 DH pour les voitures neuves
            }
            break;

        case 2: // Vente de voitures d'occasion
            commission = prix * 0.05;
            if (commission < 500) {
                commission = 500; // Minimum de 500 DH pour les voitures d'occasion
            }
            break;

        case 3: // Vente de pièces de rechange
            commission = prix * 0.06;
            break;

        case 4: // Réparation des voitures
            commission = prix * 0.10;
            break;
    }

    // Affichage de la commission calculée
    printf("La commission est de: %.2f DH\n", commission);

    return 0;
}
