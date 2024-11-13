#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("The solution is in the comments :D \n\n");

        // Compléter le tableau suivant :
        //                 A       B       C       P1      P2
        // Init            1       2       3       /       /
        // P1=&A           1       2       3       &A      /
        // P2=&C           1       2       3       &A      &C
        // *P1=(*P2)++     3       2       4       &A      &C
        // P1=P2           3       2       4       &C      &C
        // P2=&B           3       2       4       &C      &B
        // *P1-=*P2        3       2       2       &C      &B
        // ++*P2           3       3       2       &C      &B

    return 0;
}
