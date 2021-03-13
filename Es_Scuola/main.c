#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct persona {
    char nome[20];
    char cognome[20];
    int annoNascita;
} Persona;

typedef struct nodo {
    Persona* value;
    struct nodo* next;
} Nodo;

void add(Nodo** list, char* nome, char* cognome, int annoNascita);
void print(Nodo* list);

int main()
{

    Nodo* p = NULL;

    add(&p, "Luca", "Rossi", 1988);
    add(&p, "Mario", "Rossi", 2000);
    add(&p, "Luca", "Verdi", 1968);
    add(&p, "Pippo", "Verdi", 1968);

    print(p);

    return 0;
}


void add(Nodo** list, char* nome, char* cognome, int annoNascita)
{
    Nodo* newValue = (Nodo*)malloc(sizeof(Nodo));
    newValue->value = (Persona*)malloc(sizeof(Persona));

    strcpy(newValue->value->nome, nome);
    strcpy(newValue->value->cognome, cognome);
    newValue->value->annoNascita=annoNascita;

    newValue->next = *list;

    *list = newValue;
}

void print(Nodo* list)
{
    if(list!=NULL)
    {
        printf("%s %s %d\n", list->value->nome, list->value->cognome, list->value->annoNascita);
        print(list->next);
    }
}