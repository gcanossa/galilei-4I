#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int value;
    struct nodo* left;
    struct nodo* right;
} Nodo;

void add(Nodo** root, int value);
void print(Nodo* root);
void print2(Nodo* root);

int main(){

    Nodo* tree = NULL;

    add(&tree, 1);
    add(&tree, 2);
    add(&tree, 3);
    add(&tree, 4);
    add(&tree, 5);
    add(&tree, 6);

    print(tree);

    printf("\n");

    print2(tree);

    FILE* fp = fopen("test.txt","wt");

    fprintf(fp, "Ciao mondo questo numero è %d\n", 120);

    fclose(fp);

    fprintf(stdout, "Ciao mondo questo numero è %d\n", 120);
    printf("Ciao mondo questo numero è %d\n", 120);

    int x;
    fscanf(stdin,"%d", &x);
    fflush(stdin);
    printf("Ciao mondo questo numero è %d\n", x);

    // Per leggere una stringa da un file senza sapere la lunghezza e quante ce ne sono
    // char buff[10];
    // char s[1000];

    // int n;
    // int i=0;

    // while ((n=fread(buff, 1, 10, fp))>0)
    // {
    //     int j=0;
    //     for(;j<n && buff[j]!='\0';j++){
    //         s[i]=buff[j];
    //         i++;
    //     }

    //     while(j<n && buff[j]!='\0'){
    //         s[i]=buff[j];
    //         i++;
    //         j++
    //     }

    //     if(buff[j]!='\0')
    //         break;
    // }
    

    return 0;
}

void add(Nodo** root, int value){
    Nodo* el = (Nodo*)malloc(sizeof(Nodo));
    el->value = value;
    el->left=NULL;
    el->right=NULL;

    if(*root==NULL){
        *root=el;
    }
    else{
        Nodo* tmp = *root;

        // for(;;)
        while(1){
            int direzione = rand()%2;

            if(direzione==0){
                if(tmp->left==NULL){
                    tmp->left=el;
                    break;
                }
                else{
                    tmp=tmp->left;
                }
            }
            else{
                if(tmp->right==NULL){
                    tmp->right=el;
                    break;
                }
                else{
                    tmp=tmp->right;
                }
            }
        }
    }
}

void print(Nodo* root){
    if(root!=NULL){
        printf("%d\n", root->value);
        print(root->left);
        print(root->right);
    }
}


void print2(Nodo* root){
    if(root!=NULL){
        print2(root->left);
        printf("%d\n", root->value);
        print2(root->right);
    }
}