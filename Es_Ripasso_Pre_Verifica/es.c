#include <stdio.h>

void prova(char** p);
void caso2(char* p);

// se il comando è chiamato come ./es ciao mondo, fa OUTPUT
int main(int argc, char** argv){

    int a = 3;
    printf("%d\n", a+8);
    printf("%d\n", a);

    prova(argv);
    caso2(*argv);
    caso2(*(argv+1));

    return 0;
}

// dato p un puntatore ad array di puntatori a carattere...
void prova(char** p){
    // prendo il valore della prima cella del primo array puntato
    printf("%c\n",**p);

    // prendo il valore della prima cella del secondo array puntato
    printf("%c\n",*(*(p+1)));

    // prendo il valore della prima cella del primo array puntato aumetato di 1
    printf("%c\n",*(*(p))+1);
    
    // scrivo il valore del carattere '.' aumentato di 1
    printf("xy %c", '.'+1);

    // prendo il valore della terza cella del secondo array puntato
    printf("%c\n",*(*(p+1)+2)); 

    // prendo il valore della prima cella del primo array puntato
    printf("%c\n",**p);

    // prendo il valore della prima cella del primo array puntato (parentesi esplicite)
    printf("%c\n",*(*(p)));
}

// dato p un puntatore ad array di carattere...
void caso2(char* p){
    // prendo il valore della prima cella aumentato di 1
    printf("%c\n", *p+1);

    // prendo il valore della seconda cella
    printf("%c\n", *(p+1));

    // prendo il valore della seconda cella aumentato di 1
    printf("%c\n", *(p+1)+1);
}