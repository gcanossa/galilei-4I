#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    char value;
    struct elemento* next;
    struct elemento* prev;
} Elemento;

Elemento* addToHead(Elemento* lista, char value);
Elemento* removeFromList(Elemento* lista, char value);
void stampaLista(Elemento* lista);

int main(){

    Elemento* p=NULL;
    p = addToHead(p, 'a');
    p = addToHead(p, 'r');
    p = addToHead(p, 'z');

    stampaLista(p);
    printf("\n");

    printf("%c\n", p->next->next->prev->value);

    p = removeFromList(p, 'r');

    stampaLista(p);
    printf("\n");
    
    return 0;
}

Elemento* addToHead(Elemento* lista, char value){
    Elemento* newHead = (Elemento*)malloc(sizeof(Elemento));

    newHead->value = value;
    newHead->next = lista;
    newHead->prev = NULL;
    
    if(lista!=NULL){
        lista->prev = newHead;
    }

    return newHead;
}

void stampaLista(Elemento* lista){
    if(lista!=NULL){
        printf("%c", lista->value);
        stampaLista(lista->next);
    }
}

Elemento* removeFromList(Elemento* lista, char value){
    if(lista==NULL){
        return lista;
    }
    else if(lista->value!=value){
        removeFromList(lista->next, value);
    }
    else{
        Elemento* tmp = lista;
        lista->prev->next=tmp->next;
        tmp->next->prev = tmp->prev;

        free(tmp);
    }

    return lista;
}