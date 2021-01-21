#include <stdio.h>
#include <stdlib.h>

/*
    Ctrl + C => copia
    Ctrl + X => taglia
    Ctrl + V => incolla
    F2 => rinomina simbolo (variabile, funzione, struttura, ...)
    Ctrl + H => trova e sostituisci
    Ctrl + F => trova
    Ctrl + Shift + (F|H) => trova/sostituisci su tutti i file
    Ctrl + Shift + B => compila
    Ctrl + K, C => commenta righe selezione
    Ctrl + K, U => scommenta righe selezione
*/

typedef struct elemento {
    int value;
    struct elemento* next;
} Elemento;

int head(Elemento* lista);
Elemento* tail(Elemento* lista);
Elemento* addToHead(Elemento* lista, int value);

void stampaLista(Elemento* lista);
void stampaListaRev(Elemento* lista);

int main(){

    Elemento* s = NULL;

    printf("%d\n", head(s));

    s = addToHead(s, 3);
    printf("%d\n", head(s));
    s = addToHead(s, 6);
    printf("%d\n", head(s));
    s = addToHead(s, 9);
    printf("%d\n", head(s));

    stampaLista(s);
    printf("\n");
    stampaListaRev(s);
    printf("\n");

    return 0;
}

void stampaLista(Elemento* lista){
    if(lista!=NULL){
        printf("%d ", head(lista)); //printf("%d", lista->value);
        stampaLista(tail(lista)); //stampaLista(lista->next);
    }
}

void stampaListaRev(Elemento* lista){
    if(lista!=NULL){
        stampaListaRev(tail(lista)); //stampaLista(lista->next);
        printf("%d ", head(lista)); //printf("%d", lista->value);
    }
}

// void stampaStringa(char* s){
//     if(*s!='\0'){
//         printf("%c", *s);
//         stampaStringa(s+1);
//     }
// }

int head(Elemento* lista){
    if(lista==NULL)
        return 0;
    else
        return lista->value;
}

Elemento* tail(Elemento* lista){
    if(lista==NULL)
        return NULL;
    else
        return lista->next;
}

Elemento* addToHead(Elemento* lista, int value){
    Elemento* newHead = (Elemento*)malloc(sizeof(Elemento));

    newHead->value = value;
    newHead->next = lista;

    return newHead;
}