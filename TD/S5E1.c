#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char verbe[30];  // Déclaration d'un tableau pour le verbe
    int N;  // Variable pour stocker la longueur du verbe

    // Contrôle de saisie du verbe pour s'assurer qu'il soit régulier (se termine par "er")
    do{
        printf("Saisir un verbe régulier qui se termine par \"er\" : ");
        scanf("%s", verbe);  // Lecture du verbe
        N = strlen(verbe);  // Calcul de la longueur du verbe
    }while(verbe[N-2] != 'e' || verbe[N-1] != 'r');  // Vérifie que le verbe se termine bien par "er"

    // Affichage du titre de la conjugaison
    printf("\n\nLa conjugaison du verbe '%s' au futur est :\n\n", verbe);

    // Affichage de la conjugaison au futur
    printf("Je %serai\n", verbe);  // Conjugaison pour "je"
    printf("Tu %seras\n", verbe);  // Conjugaison pour "tu"
    printf("Il/Elle %sera\n", verbe);  // Conjugaison pour "il/elle"
    printf("Nous %serons\n", verbe);  // Conjugaison pour "nous"
    printf("Vous %serez\n", verbe);  // Conjugaison pour "vous"
    printf("Ils/Elles %seront\n", verbe);  // Conjugaison pour "ils/elles"

    return 0;  // Fin du programme
}
