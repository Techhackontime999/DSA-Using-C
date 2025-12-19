#include<stdio.h>
#include<limits.h>
int main(){
    int arr[][3]={-1,-9,-3,-4,-5,-6};
    int max=INT_MIN;
    for (int i = 0; i < 2; i++)
    {
       for (int j = 0; j < 3; j++)
       {
        if (arr[i][j]>max)
        {
            max=arr[i][j];
           
        }
        
       }
       
    }
    printf(" %d is the maximum element. \n",max);

    return 0;
}