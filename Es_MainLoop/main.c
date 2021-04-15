#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>

int kbhit()
{
    struct termios term;
    tcgetattr(0, &term);

    struct termios term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);

    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);

    tcsetattr(0, TCSANOW, &term);

    return byteswaiting > 0;
}

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

        render(status, 30);
    }
}


void render(Scene s, int frameRate){

    usleep(1000*1000/frameRate);
    
    system("clear");

    for(int i=0;i<s.position;i++){
        printf(" ");
    }
    printf("o");
    fflush(stdout);
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
        char command = getchar();
        fflush(stdin);
        if(command=='s')
            s->dir=2;
        else if(command=='a')
            s->dir=1;
        else if(command=='d')
            s->dir=0;            
    }
}