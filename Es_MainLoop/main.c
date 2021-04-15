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

int main(){

    int screen_size = 20;

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

    for(int i=0;i<position;i++){
        printf(" ");
    }
    printf("o");
}

void updateScene(Scene* s){
    if(dir==0)
        position++;
    else if(dir==1)
        position--;

    if(position==screen_size)
        dir=1;
    if(position==0)
        dir=0;
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