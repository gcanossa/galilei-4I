#include <stdio.h>

int binarySearch(int n, int arr[], int begin, int end);

int main(){
    int prova[16] = {1,3,5,7,9,10,13,23,24,33,34,56,77,88,91,92};

    int n;
    do{
        scanf("%d",&n);
        fflush(stdin);

        printf("\n%d\n", binarySearch(n, prova, 0, 15));

    }
    while (n>0);
      

    return 0;
}


int binarySearch(int n, int arr[], int begin, int end){
    if(end<begin){
        return -1;
    }
    printf("*");

    int idx = (end-begin)/2 + begin;

    if(arr[idx] == n){
        return idx;
    }
    else if(arr[idx]<n){
        return binarySearch(n, arr, idx+1, end);
    }
    else{
        return binarySearch(n, arr, begin, idx-1);
    }
}