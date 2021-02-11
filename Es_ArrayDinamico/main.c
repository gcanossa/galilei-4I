#include <stdio.h>
#include <stdlib.h>

void stampa(char **p, int length);
void aggiungi(char*** p, int* length);

int main(){
    char** argv = NULL;
    int length = 0;

    for(int i = 0;i < 3;i++)
        aggiungi(&argv, &length);

    printf("risultati\n");
    
    stampa(argv, length);

    return 0;
}


void stampa(char **p, int length){
    for(int i=0;i<length;i++){
        printf("%s\n", *(p+i));
    }
}

void aggiungi(char*** p, int* length){
    *p = (char**)realloc(*p, sizeof(char*)*(*length+1));
    char* s = (char*)malloc(sizeof(char)*30);

    scanf("%s", s);
    fflush(stdin);

    *(*p+*length)=s;
    (*length)++;
}