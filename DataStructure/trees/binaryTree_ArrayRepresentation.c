#include<stdio.h>
#include<stdlib.h>

int main(){
    int n=7;//here n is the size of the tree
    int *arr=(int *)malloc(n*sizeof(int));
    arr[0]=2;
    arr[1]=3;
    arr[2]=4;
    arr[3]=5;
    arr[4]=6;
    arr[5]=7;
    arr[6]=8;
    for (int i = 0; i < n; i++)
    {
       printf(" %d ",arr[i]);
    }
    printf("\n");
    return 0;
}