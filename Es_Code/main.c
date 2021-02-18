#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int value;
    struct elemento* next;
} Elemento;

void enque(Elemento** queue, int value);
int deque(Elemento** queue);

int main(){

    Elemento* p=NULL;

    enque(&p, 5);
    enque(&p, 6);
    enque(&p, 13);

    int n;
    while ((n=deque(&p))>=0)
    {
        printf("%d\n", n);
    }

    return 0;
}

void enque(Elemento** queue, int value){
    Elemento* newHead = (Elemento*)malloc(sizeof(Elemento));
    newHead->value = value;
    newHead->next = *queue;

    *queue = newHead;
}

int deque(Elemento** queue){
    if (*queue==NULL){
        return -1;
    }
    else{
        Elemento* ultimo = *queue;
        Elemento* penultimo = NULL;
        while (ultimo->next!=NULL){
            penultimo=ultimo;
            ultimo=ultimo->next;
        }
        int tmpValue = ultimo->value;

        free(ultimo);

        if (penultimo==NULL){
            *queue = NULL;
        }
        else{
            penultimo->next = NULL;
        }

        return tmpValue;
    }
}