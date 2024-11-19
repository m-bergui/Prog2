#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction pour afficher une chaîne avec des caractères spéciaux (comme '\n' et '\t') sous forme lisible
// Juste pour les curieux
void printS(const char *str) {
    printf("\nString = ");
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            printf("\\n");  // Affiche un retour à la ligne
        } else if (str[i] == '\t') {
            printf("\\t");  // Affiche une tabulation
        } else if (str[i] == '\0') {
            printf("\\0");  // Affiche le caractère nul
        } else {
            printf("%c", str[i]);  // Affiche les autres caractères normalement
        }
    }
    printf("\\0\n");  // Indique la fin de la chaîne
}

// Fonction pour calculer la longueur d'une chaîne manuellement
int LgChaine(char *ch) {
    int i = 0;

    // Compte les caractères jusqu'à rencontrer le caractère nul '\0'
    while (ch[i] != '\0') {
        i++;
    }
    return i;
}

int main(int argc, char const *argv[]) {
    char ch1[30];  // Déclaration de la première chaîne (max 30 caractères)
    char ch2[50];  // Déclaration de la deuxième chaîne (max 50 caractères)

    // Lecture de la première chaîne (taille max 30)
    do {
        printf("Entrez une chaine de caractere: ");
        gets(ch1);  // Lecture de la chaîne
        if (strlen(ch1) > 30) {  // Vérifie si la chaîne dépasse 30 caractères
            printf("La taille de cette chaine de caractere '%s' est superieur a 30.\n", ch1);
        }
    } while (strlen(ch1) > 30);  // Répète jusqu'à ce que la chaîne soit valide

    // Lecture de la deuxième chaîne (taille max 50)
    do {
        printf("Entrez une chaine de caractere: ");
        gets(ch2);  // Lecture de la chaîne
        if (strlen(ch2) > 50) {  // Vérifie si la chaîne dépasse 50 caractères
            printf("La taille de cette chaine de caractere '%s' est superieur a 50.\n", ch2);
        }
    } while (strlen(ch2) > 50);  // Répète jusqu'à ce que la chaîne soit valide

    // Affiche les chaînes saisies
    puts(ch1);  // Affiche ch1 avec un retour à la ligne
    puts(ch2);  // Affiche ch2 avec un retour à la ligne

    // Affiche les longueurs calculées par `strlen` et la fonction `LgChaine`
    printf("strlen(ch1) = %d, LgChaine(ch1) = %d\n", strlen(ch1), LgChaine(ch1));
    printf("strlen(ch2) = %d, LgChaine(ch2) = %d\n", strlen(ch2), LgChaine(ch2));

    // Compare les deux chaînes avec `strcmp`
    if (strcmp(ch1, ch2)) {
        // Si les chaînes sont différentes
        printf("'%s' et '%s' sont différentes.\n", ch1, ch2);
    } else {
        // Si les chaînes sont identiques
        printf("'%s' et '%s' sont identiques.\n", ch1, ch2);
    }

    // Échange les deux chaînes si la longueur de ch2 est inférieure à 30
    if (strlen(ch2) < 30) {
        printf("Avant echange: ch1 = '%s' , ch2 = '%s'\n", ch1, ch2);

        char temp[30];  // Temporaire pour effectuer l'échange
        strcpy(temp, ch2);  // Copie ch2 dans temp
        strcpy(ch2, ch1);  // Copie ch1 dans ch2
        strcpy(ch1, temp);  // Copie temp (ancienne ch2) dans ch1

        printf("Apres echange: ch1 = '%s' , ch2 = '%s'\n", ch1, ch2);
    } else {
        // Sinon, affiche un message indiquant que l'échange n'est pas possible
        printf("La taille de ch2 est superieure a la taille de ch1\n");
    }

    return 0;
}
