#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// typedef struct persona {
//     char nome[20];
//     char cognome[20];
//     int annoNascita;
// } Persona;

typedef struct persona {
    char* nome;
    char* cognome;
    int annoNascita;
} Persona;

typedef struct nodo {
    Persona* value;
    struct nodo* next;
} Nodo;

Persona* newPersona(char* nome, char* cognome, int annoNascita);
void printPersona(Persona* p);
int equalsPersona(Persona* p1, Persona* p2);
void setNomePersona(Persona* p, char* nome);
void setCognomePersona(Persona* p, char* cognome);
void setAnnoNascitaPersona(Persona* p, int anno);

void add(Nodo** list, Persona* p);
void printList(Nodo* list);
int findPersona(Nodo* list, Persona* p, int n);
Nodo* getAt(Nodo* list, int index);
void removeAt(Nodo** list, int index);
void save(Nodo* list, char* path);
Nodo* load(char* path);

// int findPersonaGen(Nodo* list, int fun(Persona*));

// int nomeUguale(Persona* p)
// {
//     return strcmp(p->nome, "Luca") == 0;
// }

int main()
{

    Nodo* p = NULL;

    add(&p, newPersona("Luca", "Rossi", 1988));
    add(&p, newPersona("Mario", "Rossi", 2000));
    add(&p, newPersona("Luca", "Verdi", 1968));
    add(&p, newPersona("Pippo", "Verdi", 1968));

    printList(p);

    Persona x = {"Piero", "Lui", 1900};

    printf("\n");
    printPersona(&x);

    int idx = findPersona(p, newPersona("Luca", "Verdi", 1968), 0);

    Nodo* v = getAt(p, idx);
    setNomePersona(v->value, "diverso");

    printf("\n");
    printList(p);

    save(p, "./data.bin");

    idx = findPersona(p, newPersona("Mario", "Rossi", 2000), 0);
    removeAt(&p, idx);

    printf("\n");
    printList(p);

    // findPersonaGen(p, nomeUguale);

    p = load("./data.bin");

    printf("\n");
    printList(p);

    return 0;
}

Persona* newPersona(char* nome, char* cognome, int annoNascita)
{
    Persona* value = (Persona*)malloc(sizeof(Persona));

    value->nome = (char*)malloc(sizeof(char)*(strlen(nome)+1));
    value->cognome = (char*)malloc(sizeof(char)*(strlen(cognome)+1));

    strcpy(value->nome, nome);
    strcpy(value->cognome, cognome);
    value->annoNascita=annoNascita;

    return value;
}

void printPersona(Persona* p)
{
    printf("nome:%s, cognome:%s, anno di nascita:%d\n", p->nome, p->cognome, p->annoNascita);
}

int equalsPersona(Persona* p1, Persona* p2)
{
    return strcmp(p1->nome, p2->nome)==0 && 
        strcmp(p1->cognome, p2->cognome)==0 && 
        p1->annoNascita == p2->annoNascita;
}


void setNomePersona(Persona* p, char* nome)
{
    free(p->nome);
    p->nome = (char*)malloc(sizeof(char)*(strlen(nome)+1));
    strcpy(p->nome, nome);

    if(p->nome[0] >= 'a' && p->nome[0]<='z')
    {
        p->nome[0] = 'A' + (p->nome[0] - 'a');
    }
}

void setCognomePersona(Persona* p, char* cognome)
{
    free(p->cognome);
    p->cognome = (char*)malloc(sizeof(char)*(strlen(cognome)+1));
    strcpy(p->cognome, cognome);

    if(p->cognome[0] >= 'a' && p->cognome[0]<='z')
    {
        p->cognome[0] = 'A' + (p->cognome[0] - 'a');
    }
}

void setAnnoNascitaPersona(Persona* p, int anno)
{
    p->annoNascita = anno;
}

void add(Nodo** list, Persona* p)
{
    Nodo* newValue = (Nodo*)malloc(sizeof(Nodo));
    newValue->value = p;

    newValue->next = *list;

    *list = newValue;
}

void printList(Nodo* list)
{
    if(list!=NULL)
    {
        printPersona(list->value);
        printList(list->next);
    }

    /*
        if(list==NULL)
            return;

        printPersona(list->value);
        printList(list->next);
    */
}

int findPersona(Nodo* list, Persona* p, int n)
{
    if(list!=NULL)
    {
        if(equalsPersona(p, list->value))
            return n;
        else
            return findPersona(list->next, p, n+1);
    }

    return -1;
}

// int findPersonaGen(Nodo* list, int fun(Persona*))
// {
//     int i = -1;
//     while (list!=NULL)
//     {
//         i++;
//         if(fun(list->value))
//             return i;
//     }
    
//     return -1;
// }

Nodo* getAt(Nodo* list, int index)
{
    if(list == NULL)
        return NULL;
    else if (index<0)
        return NULL;
    else
    {
        int i=0;
        while (i<index && list!=NULL)
        {
            i++;
            list=list->next;
        }

        return list;
    }    
}

void removeAt(Nodo** list, int index)
{
    Nodo* nodo = getAt(*list, index); // index - 1 per ottimizzare le performace
    if(nodo!=NULL)
    {
        if(nodo==*list)
            *list=nodo->next;
        else
        {
            Nodo* prev = getAt(*list, index-1);
            prev->next = nodo->next;
        }        

        free(nodo);
    }
}


void save(Nodo* list, char* path)
{
    FILE* fp = fopen(path, "wb");

    int size;
    while (list!=NULL)
    {
        size = strlen(list->value->nome)+1;
        fwrite(&size, sizeof(int), 1, fp);
        fwrite(list->value->nome, sizeof(char), size, fp);

        size = strlen(list->value->cognome)+1;
        fwrite(&size, sizeof(int), 1, fp);
        fwrite(list->value->cognome, sizeof(char), size, fp);

        size = sizeof(int);
        fwrite(&size, sizeof(int), 1, fp);
        fwrite(&list->value->annoNascita, sizeof(int), 1, fp);

        list=list->next;
    }
    
    fclose(fp);
}

Nodo* load(char* path)
{
    FILE* fp = fopen(path, "rb");

    Persona p;
    Nodo* list = NULL;

    int size;

    int iteamsRead=1;

    while (iteamsRead)
    {
        // int n;
        // while ((n=fread(&size, 1, 10*1024, fp))!=0)
        // {
        //     /* code */
        // }

        iteamsRead=fread(&size, sizeof(int), 1, fp);
        p.nome = (char*)malloc(size);
        iteamsRead=fread(&p.nome, sizeof(char), size, fp);

        iteamsRead=fread(&size, sizeof(int), 1, fp);
        p.cognome = (char*)malloc(size);
        iteamsRead=fread(&p.cognome, sizeof(char), size, fp);

        iteamsRead=fread(&size, sizeof(int), 1, fp);
        iteamsRead=fread(&p.annoNascita, sizeof(int), 1, fp);
        
        add(&list, newPersona(p.nome, p.cognome, p.annoNascita));

        free(p.nome);
        free(p.cognome);
    }

    // Persona* q = newPersona("","",-1);
    // while (fread(&q,sizeof(Persona),1,fp)!=0)
    // {
    //     add(&list, q);
    //     q = newPersona("","",-1);
    // }

    fclose(fp);

    return list;
}
