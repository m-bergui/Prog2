#include <stdio.h> 

int x = 4;  // Variable globale 'x' initialisée à 4

// Fonction qui augmente 'x' de 1 et retourne la nouvelle valeur
int avancer1() {  
    x += 1;  // 'x' devient 5
    return x; 
}

// Fonction qui prend une copie de 'y' et augmente cette copie de 2
void avancer2(int y) {  
    y += 2;  // 'y' devient 'y+2', mais cela n'affecte pas la variable 'y' dans main
}

// Fonction qui diminue 'x' de 2
void reculer2() { 
    x -= 2;  // 'x' devient 3
}

// Fonction qui prend une copie de 'x' (locale) et diminue cette copie de 3
int reculer3(int x) {  
    x -= 3;  // Cette 'x' locale devient 'x-3', mais n'affecte pas la variable globale
    return x; 
}

int main() { 
    int y; 

    // Appel de 'avancer1' : x devient 5, y devient 7 (5 + 2)
    y = avancer1() + 2;  
    printf("\n x=%d", x); // x=5 (après 'avancer1')
    printf("\n y=%d", y); // y=7 (valeur de 'y' dans main)

    // Appel de 'avancer2' : y n'est pas modifié dans main car c'est une copie locale
    avancer2(y); 
    printf("\n\n x=%d", x); // x=5 (pas de changement de 'x' après 'avancer2')
    printf("\n y=%d", y); // y=7 (pas de changement de 'y' après 'avancer2')

    // Appel de 'reculer2' : 'x' devient 3
    reculer2(); 
    printf("\n\n x=%d", x); // x=3 (après 'reculer2')
    printf("\n y=%d", y); // y=7 (pas de changement de 'y')

    // Appel de 'reculer3' : 'x' devient 1 (y est passé à 'reculer3' mais ne change rien)
    x = reculer3(y) - 3; 
    printf("\n\n x=%d", x); // x=1 (après 'reculer3')
    printf("\n y=%d", y); // y=7 (pas de changement de 'y')

    return 0; 
}

