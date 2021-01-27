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
Elemento* remove(Elemento* lista, int value);