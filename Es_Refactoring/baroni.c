#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define DIM 2

typedef struct{
	
	int anni;
	
	char cognome[30];
	
}stru;

void stampa(stru *v,int c);

void inserisci(stru *v);

void controllo1(stru **v,stru *s, int *c);

void controllo2(stru **v,stru *x,stru *s, int *c);

int main(void){

	stru *v1,*v2,*v3;

	v1 = (stru*) malloc(DIM * sizeof(stru));

	v2 = (stru*) malloc(DIM * sizeof(stru));
	
	v3 = NULL;

	int cnt = 0;

	inserisci(v1);
	inserisci(v2);

	printf("\n\n");

	controllo1(&v3,v1,&cnt);
	
	controllo2(&v3,v1,v2,&cnt);
	
	stampa(v3,cnt);
}

void stampa(stru *v,int c){
	
	printf("STAMPA VETTORE: \n\n");
	
	
	for(int i=0;i<c;i++){
	
		printf("COGNOME: %s\n",(v+i)->cognome);
		printf("ANNI: %d\n",(v+i)->anni);
		printf("\n");
	}
}

void inserisci(stru *v){
	
	for(int i=0;i<DIM;i++){
	
		printf("Inserisci cognome:\n");
		scanf("%s",&(v+i)->cognome);
		printf("Inserisci eta':\n");
		scanf("%d",&(v+i)->anni);
		printf("\n");
	}
}

void controllo1(stru **v ,stru *s, int *c){

	for(int i=0;i<DIM;i++){
		
		*v = (stru*) realloc(*v,(i+1)*sizeof(stru));
	
		**(v+i) = *(s+i);
		
		*c = *c + 1;
	}
	
}

void controllo2(stru **v,stru *x, stru *s, int *c){

	for(int i=0;i<DIM;i++){
		
		int f = 0;
		
		for(int j=0;j<DIM;j++){
		
			if(strcmp((s+i)->cognome,(x+j)->cognome) == 0 && (s+i)->anni == (x+j)->anni){
			
				f = 1;
				break;
			}
		}
		
		if(!f){
			
			*v = (stru*) realloc(*v,(i+1+DIM)*sizeof(stru));
			
			**(v+i+DIM) = *(s+i);
			
			*c = *c + 1;
			
		}
	}
	
}