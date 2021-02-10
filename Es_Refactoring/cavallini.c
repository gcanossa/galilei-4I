#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char cognome[20];
    int anni;
    float altezza;
} Persona;

void setUp1(Persona* p);
void setUp2(Persona* p);
void setUp3(Persona* p);

void stampaPersona(Persona p);
void stampaPersone(Persona* p, int length);

int personeEquals(Persona a, Persona b);
int findPersona(Persona* arr, int length, Persona p);
void addIfNotPresent(Persona **destination, int* length, Persona p);
void merge(Persona **destination, int* dstLength, Persona* source, int srcLength);

int main(){
    int i,j,cnt=0;
    Persona* v1;
    Persona* v2;
    Persona* v3;

    v1 = (Persona*) malloc(5*sizeof(Persona));
    v2 = (Persona*) malloc(5*sizeof(Persona));
    v3 = NULL;
    
    setUp1(v1);
    setUp2(v2);

    merge(&v3, &cnt, v1, 5);
    merge(&v3, &cnt, v2, 5);

    printf("v1:\n");
    stampaPersone(v1, 5);

    printf("v2:\n");
    stampaPersone(v2, 5);

    printf("v3:\n");
    stampaPersone(v3, cnt);    
}


void setUp1(Persona* p){
    (*(p+0)).anni = 10;
    strcpy((*(p+0)).cognome, "Lillo");

    (*(p+1)).anni = 11;
    strcpy((*(p+1)).cognome, "Asan");

    (*(p+2)).anni = 12;
    strcpy((*(p+2)).cognome, "Marce");

    (*(p+3)).anni = 13;
    strcpy((*(p+3)).cognome, "Fabione");

    (*(p+4)).anni = 14;
    strcpy((*(p+4)).cognome, "Ganz");
}
void setUp2(Persona* p){
    
    (*(p+0)).anni = 10;
    strcpy((*(p+0)).cognome, "Lillo");

    (*(p+1)).anni = 36;
    strcpy((*(p+1)).cognome, "CR7");

    (*(p+2)).anni = 25;
    strcpy((*(p+2)).cognome, "Paolino");

    (*(p+3)).anni = 77;
    strcpy((*(p+3)).cognome, "Kulugol");

    (*(p+4)).anni = 3;
    strcpy((*(p+4)).cognome, "Gorgione");
}
void setUp3(Persona* p){
    
    (*(p+0)).anni = 11;
    strcpy((*(p+0)).cognome, "Lillo");

    (*(p+1)).anni = 36;
    strcpy((*(p+1)).cognome, "CR7");

    (*(p+2)).anni = 25;
    strcpy((*(p+2)).cognome, "Paolino");

    (*(p+3)).anni = 77;
    strcpy((*(p+3)).cognome, "Kulugol");

    (*(p+4)).anni = 3;
    strcpy((*(p+4)).cognome, "Gorgione");
}

void stampaPersona(Persona p){
    printf("anni: %d, cognome: %s", p.anni, p.cognome);
}

void stampaPersone(Persona* p, int length){
    for(int i=0; i < length; i++){
        stampaPersona(*(p+i));
        printf("\n");
    }
}

int personeEquals(Persona a, Persona b){
    if(a.anni==b.anni && strcmp(a.cognome, b.cognome)==0 && a.altezza==b.altezza)
        return 1;
    else
        return 0;
}

int findPersona(Persona* arr, int length, Persona p){
    for(int i=0;i<length;i++){
        if(personeEquals(p, *(arr+i))){
            return i;
        }
    }
    return -1;
}

void addIfNotPresent(Persona **destination, int* length, Persona p){
    if(findPersona(*destination, *length, p)<0){
        *destination = (Persona*) realloc(*destination, (*length+1)*sizeof(Persona));
        *(*destination+*length)=p;
        *length++;
        
        // Persona* tmp = (Persona*) malloc((*length+1)*sizeof(Persona));

        // for(int i=0;i<*length;i++){
        //     *(tmp+i)=*(*destination+i);
        // }
        // *(tmp+*length)=p;
        // *length++;

        // free(*destination);
        // *destination=tmp;
    }
}

void merge(Persona **destination, int* dstLength, Persona* source, int srcLength){
    for(int i=0;i<srcLength;i++){
        addIfNotPresent(destination, dstLength, *(source+i));
    }
}