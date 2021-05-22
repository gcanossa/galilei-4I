#include <stdio.h>
#include <stdlib.h>

typedef struct el {
    int value;
    struct el* next;
} Element;

void add(Element** el, int value);
void print(Element*el);
void sort(Element* head, Element* current, int swapped);

int main(){

    Element* p = NULL;

    add(&p, 5);
    add(&p, 1);
    add(&p, 13);
    add(&p, 2);

    print(p);

    sort(p, p, 0);

    print(p);

    return 0;
}

void add(Element** el, int value){
    Element* newEl = (Element*)malloc(sizeof(Element));
    newEl->value = value;
    newEl->next = *el;

    *el = newEl;
}

void print(Element*el){
    if(el!=NULL){
        printf("%d\n", el->value);
        print(el->next);
    }
    else{
        printf("\n");
    }
}

void sort(Element* head, Element* current, int swapped){
    if(current != NULL && current->next != NULL){
        if(current->value > current->next->value){
            int tmp = current->value;
            current->value = current->next->value;
            current->next->value = tmp;

            swapped = 1;
        }

        sort(head, current->next, swapped);
    }
    else if(swapped){
        sort(head, head, 0);
    }
}

typedef struct {
    char marca[30];
    char* modello;
    int cavalli;
} Automobile;