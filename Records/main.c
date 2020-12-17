#include <stdio.h>

struct studente {
    char nome[20];
    char cognome[20];
    int eta;
    float media_voti;
};

typedef struct studente stud_t;

typedef struct {
    char nome[20];
    char cognome[20];
    int eta;
    float media_voti;
} stud2_t;

typedef char byte;
typedef short half_word_t;
typedef int word_t;
typedef long double_word_t;
typedef int size_t;

#define DIM 3
#define stampa(x,y) printf(x,y)

int main(){

    stud_t persona;
    struct studente persona2 = { "mario", "rossi", 16, 6.5};
    stud2_t pippo;

    int x = DIM;
    stampa("%d", x);

    return 0;
}