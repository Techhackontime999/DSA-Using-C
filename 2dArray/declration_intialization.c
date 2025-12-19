#include<stdio.h>
int main(){
    // declaration
    // int arr[2][3];


    // declaration & initialization
//   int arr[2][3]={1,2,3,4,5,6};
//   int arr[][3]={1,2,3,4,5,6};
int arr[][3]={{1,2,3},{4,5,6}};

  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 3 ; j++)
  {    
    printf(" Arr[%d][%d] ---> %d \n",i,j,arr[i][j]);
  }
  
  }
  
  return 0;
}