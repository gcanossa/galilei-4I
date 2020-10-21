#include <stdio.h>

void stampa(char* s); // char[]

int main(int argc, char** argv) { // char[][]
    if(argc == 1)
        printf("Ciao mondo\n");
    else
        printf("Ciao %s\n", argv[1]);
}

void stampa(char* s){
    printf("%s", s);
}