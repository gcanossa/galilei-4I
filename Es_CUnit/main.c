#include <stdio.h>

#define NUMERO 3
#define STAMPA_NUMERO(xy) printf("%d\n", xy)

int main(void){

    int n = 3;
    printf("%d\n", 3);

    #if DEBUG

    printf("%d\n", n);
    printf("%d\n", NUMERO);
    STAMPA_NUMERO(3);

    #endif

    return 0;
}