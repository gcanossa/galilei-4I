#include <stdio.h>

int haDoppie(char* s);
int haDoppieR(char*);

int compara(char*, char*);
int comparaR(char*, char*);

int main(int pippo, char** pluto){

    printf("'%s' e '%s' sono '%s'\n", pluto[1], pluto[2], 
        compara(pluto[1], pluto[2]) == 0 ? "uguali" : "diverse");

    printf("'%s' e '%s' sono '%s'\n", pluto[1], pluto[2], 
        comparaR(pluto[1], pluto[2]) == 0 ? "uguali" : "diverse");

    printf("carattere barra 0 ha numero: %d\n",'\0');
    printf("%s %d %d\n", *(pluto + 1), haDoppie(pluto[1]), haDoppieR(pluto[1]));

    char p[20];
    printf("Inserisci una stringa: ");
    scanf("%s", p);
    fflush(stdin);

    printf("%s %d %d\n", p, haDoppie(p), haDoppieR(p));

    return 0;
}

int haDoppie(char* s){
    while(*s!='\0'){     // if(*s!='\0')
        if(*s==*(s+1)){
            return 1;
        }

        s++;            // return ricorsione(s+1)
    }

    return 0;
}

int haDoppieR(char* s){
    if(*s!='\0'){
        if(*s==*(s+1)){
            return 1;
        }
        else{
            return haDoppieR(s+1);
        }
    }
    else{
        return 0;
    }
    /*
    if(*s!='\0'){
        if(*s==*(s+1)){
            return 1;
        }
        return haDoppieR(s+1);
    }
    
    return 0;
    */
}

//ciao
//ciaa
int compara(char* s, char* p){
    while (*s!='\0' && *p!='\0')
    {
        if(*s==*p){
            s++;
            p++;
        }
        else{
            break;
        }
    }    
    
    // return *s-*p;

    if(*s=='\0' && *p=='\0')
        return 0;
    else if(*s>*p)
        return -1;
    else
        return 1;    
}

int comparaR(char* s, char* p){
    if(*s!='\0' && *p!='\0')
    {
        if(*s==*p){
            return comparaR(s+1, p+1);
        }

        if(*s=='\0' && *p=='\0')
            return 0;
        else if(*s>*p)
            return -1;
        else
            return 1; 
    }
    
    // return *s-*p;

    if(*s=='\0' && *p=='\0')
        return 0;
    else if(*s>*p)
        return -1;
    else
        return 1;    
}