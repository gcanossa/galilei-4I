#include <conio.h>
#include <stdio.h>

typedef struct
{
    int position;
    int dir;
} Scene;

void render(Scene s, int frameRate);
void updateScene(Scene* s);
void manageCommand(Scene* s);

#define SCREEN_SIZE 20

int main(){

    Scene status = {0, 0};

    while(1){
        
        manageCommand(&status);

        updateScene(&status);

        render(status);
    }
}


void render(Scene s, int frameRate){

    Sleep(1000/frameRate);
    
    system("cls");

    for(int i=0;i<s->position;i++){
        printf(" ");
    }
    printf("o");
}

void updateScene(Scene* s){
    if(s->dir==0)
        s->position++;
    else if(s->dir==1)
        s->position--;

    if(s->position==SCREEN_SIZE)
        s->dir=1;
    if(s->position==0)
        s->dir=0;
}

void manageCommand(Scene* s){
    if(kbhit()){
        char command = getch();
        if(command=='s')
            s->dir=2;
        else if(command=='a')
            s->dir=1;
        else if(command=='d')
            s->dir=0;            
    }
}