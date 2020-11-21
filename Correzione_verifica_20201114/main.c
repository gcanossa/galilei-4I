#include <stdio.h>

int es1(char* a, char* b);
int es2(char* a, char* b);
int es3(int n);
void es4(char*);
void es5(char*);
void es6();

int main(int argc, char** argv){

    printf("'%s' '%s' => %d\n", argv[1], argv[2], es1(argv[1], argv[2]));
    printf("'%s' '%s' => %d\n", argv[1], argv[2], es2(argv[1], argv[2]));

    return 0;
}

// a==b , a!=b , !(a==b && c!=d)
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

            if(a[j]==*(b+k)){
                if(indiceTrovato==-1)
                    indiceTrovato=j;
                k++;
            }
        }

        // if(a[j]!=b[k-1])... : per pinotti se vuol provare
        
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

int es2_r(char* a, char* b){
    
    int idx = es1(a,b);
    if(idx<0)
        return -1;
    else
        return 1 + idx + es2_r(a+idx+1,b);
}

/*
int fatt(int n){
    if(n<=0)
        return 1;
    else
        return n*fatt(n-1);
}
*/
int es3(int n){
    int cnt = 1;

    while(n>=0){ // !(n<=0)
        cnt = n * cnt;
        n = n -1;
    }

    return cnt;
}

/*
    void print(char* s){
        if(*s!='\0'){
            printf("%c", *s);
            print(s+1);
        }
    }
*/
void es4(char* s){
    if(*s!='\0'){
        if(*s=='a' || *s=='e' || *s=='i' || *s=='o' || *s=='u'){
            printf("%c", *s);
        }
        print(s+1);
    }
}
void es5(char* s){
    if(*s!='\0'){
        if(*s=='a' || *s=='e' || *s=='i' || *s=='o' || *s=='u'){
            printf("%c", *s);
        }

        print(s+1);

        // (*s!='\0' && *s=='a') || *s=='e' || *s=='i' || *s=='o' || *s=='u'
        // 5*3+2

        if(!(*s=='a' || *s=='e' || *s=='i' || *s=='o' || *s=='u')){
            printf("%c", *s);
        }
    }
}

void es6(){
    int arr[3];
    // [4]         [4]         [4]
    // [] [] [] [] [] [] [] [] [] [] [] []

    char* s = (char*)arr;

    scanf("%s", s);
    printf("%s", s);

    for(int i=0;*s!='\0';i++){
        printf("%c", s[i]);
        printf("%c", *(s+i));
    }
}
// ciao mondo iaa > aaiodnom oaic
// ia > ia