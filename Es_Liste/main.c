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
Elemento* addToEnd(Elemento* lista, int value);
void addToEndRef(Elemento** lista, int value);

Elemento* addOrdered(Elemento* lista, int value);

void stampaLista(Elemento* lista);
void stampaListaRev(Elemento* lista);

int find(Elemento* lista, int value);
int findIndex(Elemento* lista, int value);
int length(Elemento* lista);
Elemento* removeFromList(Elemento* lista, int value);

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

    addToEnd(s, 1);
    addToEnd(s, 103);

    Elemento* q = NULL;

    q = addToEnd(q, 4);
    addToEndRef(&q, 8);

    stampaLista(q);
    printf("\n");

    Elemento* m = NULL;
    addToEndRef(&m, 7);
    addToEnd(m, 6);

    stampaLista(m);
    printf("\n");

    Elemento* ord = NULL;

    ord = addOrdered(ord, 3);
    stampaLista(ord);
    printf("\n");

    ord = addOrdered(ord, 9);
    stampaLista(ord);
    printf("\n");

    ord = addOrdered(ord, 7);
    stampaLista(ord);
    printf("\n");

    ord = addOrdered(ord, 8);
    stampaLista(ord);
    printf("\n");

    printf("length: %d\n", length(ord));
    printf("find: %d\n", find(ord, 7));
    printf("find: %d\n", find(ord, 5));
    printf("findIndex: %d\n", findIndex(ord, 8));
    printf("findIndex: %d\n", findIndex(ord, 5));

    ord = removeFromList(ord, 7);
    stampaLista(ord);
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

Elemento* addToEnd(Elemento* lista, int value){
    if(lista == NULL){ // lista vuota 0 elementi
        Elemento* newEnd = (Elemento*)malloc(sizeof(Elemento));

        newEnd->next = NULL;
        newEnd->value = value;

        return newEnd;
    }
    else if(lista->next == NULL){ // lista contiene 1 solo elemento
        Elemento* newEnd = (Elemento*)malloc(sizeof(Elemento));

        newEnd->next = NULL;
        newEnd->value = value;
        lista->next = newEnd;
    }
    else{ // lista contiene n elementi
        addToEnd(lista->next, value);
    }

    return lista;
}


void addToEndRef(Elemento** lista, int value){
    if(*lista == NULL){
        Elemento* newEnd = (Elemento*)malloc(sizeof(Elemento));

        newEnd->next = NULL;
        newEnd->value = value;

        *lista = newEnd;
    }
    else if((*lista)->next == NULL){
        Elemento* newEnd = (Elemento*)malloc(sizeof(Elemento));

        newEnd->next = NULL;
        newEnd->value = value;
        (*lista)->next = newEnd;
    }
    else{
        addToEndRef(&(*lista)->next, value);
    }
}

Elemento* addOrdered(Elemento* lista, int value){
    if(lista == NULL){ // lista vuota con 0 elementi
        Elemento* newElement = (Elemento*)malloc(sizeof(Elemento));

        newElement->next = NULL;
        newElement->value = value;

        return newElement;
    }
    else if(lista->next == NULL){ // lista con un solo elemento
        Elemento* newElement = (Elemento*)malloc(sizeof(Elemento));

        newElement->value = value;

        if(lista->value < value){
            lista->next = newElement;
            newElement->next = NULL;
        }
        else{
            newElement->next = lista;
            return newElement;
        }
    }
    else if(lista->next->value < value){ // elemento corrente non è l'ultimo dei minori di value
        addOrdered(lista->next, value);
    }
    else{ // sono sull'ultimo elemento minore di value
        Elemento* newElement = (Elemento*)malloc(sizeof(Elemento));

        newElement->value = value;

        newElement->next = lista->next;
        lista->next = newElement;
    }

    return lista;
}

int find(Elemento* lista, int value){
    if(lista == NULL){
        return 0;
    }
    else if(lista->value == value){
        return 1;
    }
    else {
        return find(lista->next, value);
    }
}

int findIndex(Elemento* lista, int value){
    int index = 0;
    while (lista!=NULL)
    {
        if(lista->value == value){
            return index;
        }
        else{
            lista=lista->next;
            index++;
        }
    }

    return -1;
}

int length(Elemento* lista){

    if(lista == NULL){
        return 0;
    }
    else {
        return 1 + length(lista->next);
    }
}

Elemento* removeFromList(Elemento* lista, int value){
    if(lista == NULL){ // lista vuota con 0 elementi
        return lista;
    }
    else if(lista->value == value){
        Elemento* result = lista->next;

        free(lista);

        return result;
    }
    else if(lista->next == NULL){ // lista con un solo elemento
        return lista;
    }
    else if(lista->next->value != value){ // elemento corrente non è l'ultimo dei minori di value
        removeFromList(lista->next, value);
    }
    else{ // sono sull'ultimo elemento minore di value
        Elemento* tmp = lista->next;
        lista->next = lista->next->next;

        free(tmp);
    }

    return lista;
}