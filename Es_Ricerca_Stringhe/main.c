#include <stdio.h>

int find(char* s, char* p);
int countOccurrences(char* s, char* p);

// argc => arguments count
// argv => arguments values

int main(int argc, char** argv)
{
    printf("Occorrenze di \"%s\" in \"%s\": %d\n", argv[1], *(argv+2), countOccurrences(argv[1], *(argv+2)));

    return 0;
}

int find(char* s, char* p){ // ritorna -1 se p non è in s, altrimenti il suo indice
    // todo
    return 0;
}

int countOccurrences(char* s, char* p){ // ritorna il numero di volte in cui p è contenuta in s
    // finire
    return 0;
}