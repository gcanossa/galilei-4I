#include <stdio.h>

int lunghezza(char* s);

int main(int argc, char** argv)
{

    int i,j;
    for(i=0;i<argc;i++)
    {
        j=0;
        while(*(*(argv+i)+j) != '\0') //argv[i][j]
        {
            printf("%c", *(*(argv+i)+j));
            j++;
        }
        printf("\n");
    }

    printf("\n");

    char* p;
    for(i=0;i<argc;i++)
    {
        j=0;
        p = *(argv+i); //argv[i]
        while(*(p+j) != '\0') //p[j]
        {
            printf("%c", *(p+j));
            j++;
        }
        printf("\n");
    }

    printf("\n");

    for(i=0;i<argc;i++)
    {
        printf("%s  -> lunga: %d\n", argv[i], lunghezza(argv[i]));
    }

    return 0;
}

int lunghezza(char* s)
{
    if(*s=='\0')
        return 0;
    else
        return 1 + lunghezza(s+1);
}