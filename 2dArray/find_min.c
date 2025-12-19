#include<stdio.h>
#include<limits.h>
int main(){
    int arr[][3]={1,-50,-30,-4,-50,-6};
    int min=INT_MAX;
    for (int i = 0; i < 2; i++)
    {
       for (int j = 0; j < 3; j++)
       {
        if (arr[i][j]<min)
        {
            min=arr[i][j];
           
        }
        
       }
       
    }
    printf(" %d is the minimum element. \n",min);

    return 0;
}