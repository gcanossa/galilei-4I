#include <stdio.h>

void stampa(char* s); // char[]

int main(int argc, char** argv) { // char[][]
    printf("Ciao %s\n", argc == 1 ? "mondo" : argv[1]);
}

void stampa(char* s){
    printf("%s", s);
}