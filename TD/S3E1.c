#include <stdio.h> 

// Fonction qui vérifie si un nombre est triangulaire
int triangulaire(int n) {  
    int somme = 0, i = 0;

    // La boucle continue jusqu'à ce que la somme des entiers soit égale ou dépasse n
    do {
        i++;  // Incrémentation de l'entier
        somme += i;  // Additionner l'entier à la somme
        if (somme == n) {  // Si la somme atteint n
            return 1;  // Le nombre est triangulaire, retourner 1
        }    
    } while (somme < n);  // La boucle continue tant que la somme est inférieure à n

    // Si la somme dépasse n, retourner 0 car n n'est pas triangulaire
    return 0;    
} 

// Fonction qui vérifie si un nombre est tétraédrique
int tetraedrique(int n) {  
    int somme = 0, i = 1, p = 0;

    // Tant que la somme est inférieure à n, calculer la somme des entiers triangulaires
    while (somme < n) {
        // Vérifier si i est triangulaire
        if (triangulaire(i) == 1) {
            p++;  // Incrémenter l'ordre p
            somme += i;  // Ajouter i (un nombre triangulaire) à la somme
        }
        i++;  // Incrémenter i pour tester le prochain nombre
    }

    // Si la somme est égale à n, retourner l'ordre p du nombre tétraédrique
    if (somme == n) {
        return p;
    } else {
        // Si la somme dépasse n, retourner 0 car n n'est pas tétraédrique
        return 0;
    }
}

int main() {
    int n;

    // Demander à l'utilisateur d'entrer un nombre
    printf("Entrer n : "); 
    scanf("%d", &n); 

    // Vérifier si le nombre est triangulaire et afficher le résultat
    if (triangulaire(n))
        printf("%d est triangulaire\n", n); 
    else 
        printf("%d est non triangulaire\n", n);

    // Vérifier si le nombre est tétraédrique et afficher le résultat
    int t = tetraedrique(n);
    if (t != 0)
        printf("%d est tétraédrique d'ordre %d\n", n, t);
    else
        printf("%d n'est pas tétraédrique\n", n);

    return 0;  // Fin du programme
}
