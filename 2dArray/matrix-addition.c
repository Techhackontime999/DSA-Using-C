#include<stdio.h>

void displayMatrix(int arr[3][3],int row,int col){
     for (int i = 0; i < row; i++)
 {
   for (int j = 0; j < col; j++)
   {
   
    printf("%d ",arr[i][j]);
   }
    printf("\n");
   
 }
    return;
}
void createMatrix(int arr[3][3],int row,int col){
 
 for (int i = 0; i < row; i++)
 {
   for (int j = 0; j < col; j++)
   {
    printf("Enter element at Arr[%d][%d] : ",i,j);
    scanf("%d",&arr[i][j]);
    printf("\n");
   }
   
 }
displayMatrix(arr,row,col);
    return;
}

void matrixSum(int firstarr[3][3],int secarr[3][3],int row,int col){
    int arr[row][col];
    for (int i = 0; i < row; i++)
    {
       for (int j = 0; j < col; j++)
       {
       arr[i][j]=firstarr[i][j]+secarr[i][j];
       }
       
    }
    displayMatrix(arr,row,col);
    
    return ;
}
int main(){
    int row,col;
    printf("Enter number of row: ");
    scanf("%d",&row);
     printf("Enter number of column: ");
    scanf("%d",&col);
    int firstarr[row][col];
    int secarr[row][col];
   printf("-----------Add element in first array---------\n");
    createMatrix(firstarr,row,col);
     printf("-----------Add element in second array---------\n");
    createMatrix(secarr,row,col);
    printf("Sum of both matrix is : \n");
    displayMatrix(firstarr,row,col);
    printf("\n");
    printf(" ");
    printf(" ");
    printf(" + ");
    printf(" ");
    printf(" ");
    printf(" ");

    printf("\n");
    displayMatrix(secarr,row,col);
    printf("\n");
   printf(" ");
    printf(" ");
    
    printf(" = ");
    printf(" ");

    printf(" ");
    printf(" ");
     printf("\n");
    matrixSum(firstarr,secarr,row,col);

    return 0;
}