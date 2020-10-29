#include <stdio.h>

int find(char* s, char* p);
int countOccurrences(char* s, char* p);

// argc => arguments count
// argv => arguments values

int main(int argc, char** argv)
{
    // printf("%d\n", find(argv[1],argv[2]));
    printf("Occorrenze di \"%s\" in \"%s\": %d\n", argv[2], *(argv+1), countOccurrences(argv[1], *(argv+2)));

    return 0;
}

int findR(char* s, char* p, char* c){ // ritorna -1 se p non è in s, altrimenti il suo indice
    
    if(*s=='\0' && *s!=*p){
        return -1;
    }
    else if(*p=='\0'){
        return 0;
    }
    else if(*s==*p){
        return findR(s+1,p+1,c);
    }
    else{
        int tmp = findR(s+1,c,c);

        return tmp < 0 ? -1 : 1 + tmp;
    }
}
int find(char* s, char* p){ // ritorna -1 se p non è in s, altrimenti il suo indice
    
    return findR(s,p,p);
}

int countOccurrences(char* s, char* p){ // ritorna il numero di volte in cui p è contenuta in s
    
    int idx = find(s,p);
    if(idx<0)
        return 0;
    else
        return 1 + countOccurrences(s+idx+1,p);
}