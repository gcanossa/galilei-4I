#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int value;
    struct elemento* next;
} Elemento;

typedef int size;

void push(Elemento** stack, int value);
int pop(Elemento** stack);

Elemento* push_alt(Elemento* stack, int value);
Elemento* pop_alt(Elemento* stack, int* value);

int main(){
    
    Elemento* p=NULL;

    push(&p, 5);
    push(&p, 6);
    push(&p, 13);

    int n;
    while ((n=pop(&p))>=0)
    {
        printf("%d\n", n);
    }

    Elemento* q=NULL;
    q=push_alt(q, 5);
    q=push_alt(q, 6);
    q=push_alt(q, 13);

    int n_alt=0;
    while (n_alt>=0)
    {
        q=pop_alt(q, &n_alt);
        printf("%d\n", n_alt);
    }

    return 0;
}

void push(Elemento** stack, int value){
    Elemento* newEl = (Elemento*)malloc(sizeof(Elemento));
    newEl->value = value;
    newEl->next = *stack;

    *stack = newEl;
}
int pop(Elemento** stack){
    if (*stack == NULL){
        return -1;
    }
    else {
        int tmp = (*stack)->value;
        Elemento* oldHead = *stack;

        *stack = (*stack)->next;

        free(oldHead);

        return tmp;
    }
}

Elemento* push_alt(Elemento* stack, int value){
    Elemento* newHead = (Elemento*)malloc(sizeof(Elemento));
    newHead->value = value;
    newHead->next = stack;

    return newHead;
}

Elemento* pop_alt(Elemento* stack, int* value){

    if (stack == NULL){
        *value=-1;
        return NULL;
    }
    else {
        *value = stack->value;
        Elemento* newHead = stack->next;

        free(stack);

        return newHead;
    }
}