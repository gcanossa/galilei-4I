#include <stdio.h>

int es1(char* a, char* b);
int es2(char* a, char* b);

int main(int argc, char** argv){

    printf("'%s' '%s' => %d\n", argv[1], argv[2], es1(argv[1], argv[2]));
    printf("'%s' '%s' => %d\n", argv[1], argv[2], es2(argv[1], argv[2]));

    return 0;
}

int es1(char* a, char* b){
    int indiceTrovato =-1;
    int j = 0;
    int k = 0;
    while (*(a+j)!='\0' && b[k]!='\0')
    {
        if(a[j]==*(b+k)){
            if(indiceTrovato==-1)
                indiceTrovato=j;
            k++;
        }
        else{
            indiceTrovato=-1;
            k=0;
        }
        j++;
    }
    
    return indiceTrovato;
}

int es2(char* a, char* b){
    int indicePenultimaRicerca = -1;
    int indiceUltimaRicerca = -1;
    
    indiceUltimaRicerca = es1(a, b);

    while (indiceUltimaRicerca>=0)
    {
        indicePenultimaRicerca += indiceUltimaRicerca + 1;
        indiceUltimaRicerca = es1(a + indicePenultimaRicerca + 1, b);
        printf("%d\n", indicePenultimaRicerca);
    }   

    return indicePenultimaRicerca;
}

// ciao mondo iaa > aaiodnom oaic
// ia > ia