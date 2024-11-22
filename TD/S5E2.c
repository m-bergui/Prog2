#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure typeTel pour représenter les informations d'un téléphone
typedef struct {
    char marque[30];  // Marque du téléphone
    int modele;       // Modèle du téléphone
} typeTel;

// Définition de la structure smartPhone pour représenter un client et son téléphone
typedef struct {
    int id_client;     // Identifiant unique du client
    typeTel typeT;     // Informations sur le téléphone
    int type_panne;    // Type de panne : 1 pour matérielle, 2 pour logicielle
} smartPhone;

// Fonction pour saisir les informations des téléphones
void saisieT(smartPhone *T, int N) {
    int doublon;  // Variable pour vérifier les doublons d'ID client
    for (int i = 0; i < N; i++) {
        do {
            printf("Entrez l'id du client: ");
            scanf("%d", &T[i].id_client);

            doublon = 0;  // Réinitialisation de la vérification des doublons

            // Recherche de doublons dans les IDs des clients précédents
            for (int j = 0; j < i; j++) {
                if (T[j].id_client == T[i].id_client) {
                    doublon = 1;
                    printf("Erreur: l'id du client %d existe déjà.\n", T[j].id_client);
                }
            }
        } while (doublon == 1);  // Répéter la saisie si un doublon est détecté

        // Saisie de la marque et du modèle du téléphone
        printf("Entrez la marque du téléphone: ");
        scanf("%s", T[i].typeT.marque);
        printf("Entrez le modèle du téléphone: ");
        scanf("%d", &T[i].typeT.modele);

        // Saisie et validation du type de panne
        do {
            printf("Entrez le type de panne, 1 (matériel) ou 2 (logiciel): ");
            scanf("%d", &T[i].type_panne);
            if (T[i].type_panne != 1 && T[i].type_panne != 2) {
                printf("Erreur: Le type de panne doit être 1 (matériel) ou 2 (logiciel).\n");
            }
        } while (T[i].type_panne != 1 && T[i].type_panne != 2);  // Validation
    }
}

// Fonction pour afficher tous les smartphones
void afficheT(smartPhone *T, int N) {
    for (int i = 0; i < N; i++) {
        printf("ID Client: %d\n", T[i].id_client);
        printf("Téléphone:\n");
        printf("\tMarque: %s\n", T[i].typeT.marque);
        printf("\tModèle: %d\n", T[i].typeT.modele);
        printf("\tType de panne: %s\n\n", T[i].type_panne == 1 ? "matérielle" : "logicielle");
    }
}

// Fonction pour afficher les clients ayant un téléphone spécifique
void afficheTypeT(smartPhone *T, int N, typeTel TT) {
    int found = 0;  // Indicateur pour vérifier si un téléphone correspondant est trouvé
    printf("\nLes clients ayant une marque %s et un modèle %d sont :", TT.marque, TT.modele);
    for (int i = 0; i < N; i++) {
        if (strcmp(T[i].typeT.marque, TT.marque) == 0 && T[i].typeT.modele == TT.modele) {
            printf("\nLe client %d a une panne %s\n", T[i].id_client, T[i].type_panne == 1 ? "matérielle" : "logicielle");
            found = 1;
        }
    }
    if (found == 0) {
        printf(" Aucun client trouvé.\n");
    }
}

// Fonction pour trier les téléphones par modèle (tri à bulle)
// Fonction pour trier les smartphones par modèle en ordre croissant (tri à bulle)
void TriModele(smartPhone *T, int N) {
    int echange;        // Indicateur pour détecter si un échange a eu lieu dans une itération
    smartPhone Temp;    // Variable temporaire pour échanger les éléments du tableau

    // Parcours des éléments du tableau
    for (int i = 0; i < N; i++) {
        echange = 0;  // Réinitialisation de l'indicateur d'échange pour chaque itération

        // Comparaison des éléments adjacents et échange si nécessaire
        for (int j = 0; j < N - i - 1; j++) {
            if (T[j].typeT.modele > T[j + 1].typeT.modele) {  // Vérifie si les modèles sont dans le mauvais ordre
                Temp = T[j];            
                T[j] = T[j + 1];        
                T[j + 1] = Temp;        
                echange = 1;            // Signale qu'un échange a eu lieu
            }
        }

        // Si aucun échange n'a eu lieu, le tableau est déjà trié, donc arrêt anticipé
        if (echange == 0) {
            break;
        }
    }
}

// Fonction pour trier les smartphones par marque en ordre alphabétique (tri par sélection)
void TriSelectionMarque(smartPhone *T, int N) {
    int indice_min;     // Index de l'élément ayant la plus petite valeur dans la portion non triée
    smartPhone Temp;    // Variable temporaire pour échanger les éléments du tableau

    // Parcours des éléments du tableau
    for (int i = 0; i < N - 1; i++) {
        indice_min = i;  // Supposition initiale que le premier élément de la portion non triée est le minimum

        // Recherche du plus petit élément dans la portion non triée
        for (int j = i + 1; j < N; j++) {
            // Compare les marques (ordre alphabétique) et met à jour indice_min si un plus petit est trouvé
            if (strcmp(T[indice_min].typeT.marque, T[j].typeT.marque) > 0) {
                indice_min = j;
            }
        }

        // Si l'élément minimum trouvé n'est pas déjà à la bonne position, échange les éléments
        if (indice_min != i) {
            Temp = T[indice_min];
            T[indice_min] = T[i];
            T[i] = Temp;
        }
    }
}


// Fonction pour afficher le nombre de smartphones avec une panne matérielle
void AffichePanne(smartPhone *T, int N) {
    int count = 0;  // Compteur pour les pannes matérielles
    for (int i = 0; i < N; i++) {
        if (T[i].type_panne == 1) {
            count++;
        }
    }
    printf("Le nombre de smartphones ayant une panne matérielle est: %d\n", count);
}

// Fonction principale
int main(int argc, char const *argv[]) {
    int N;  // Nombre de smartphones
    smartPhone *T;  // Tableau dynamique de smartphones

    // Saisie du nombre de smartphones
    printf("Entrez la taille du tableau de téléphones: ");
    scanf("%d", &N);

    // Allocation dynamique du tableau
    T = (smartPhone*)malloc(N * sizeof(smartPhone));

    // Saisie des informations
    saisieT(T, N);

    // Recherche par marque et modèle
    typeTel TT;
    printf("Entrez la marque du téléphone: ");
    scanf("%s", TT.marque);
    printf("Entrez le modèle du téléphone: ");
    scanf("%d", &TT.modele);
    afficheTypeT(T, N, TT);

    // Affichage des téléphones non triés
    printf("\nNon Trié\n\n");
    afficheT(T, N);

    // Tri par modèle
    printf("Tri des smartphones par modèle\n");
    TriModele(T, N);
    afficheT(T, N);

    // Tri par marque
    printf("\nTri des smartphones par marque\n\n");
    TriSelectionMarque(T, N);
    afficheT(T, N);

    // Affichage des pannes matérielles
    AffichePanne(T, N);

    // Libération de la mémoire
    free(T);

    return 0;
}
