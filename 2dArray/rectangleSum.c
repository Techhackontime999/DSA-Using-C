#include <stdio.h>

int main()
{
    int row, col;
    printf("Enter number of row: ");
    scanf("%d", &row);
    printf("Enter number of column: ");
    scanf("%d", &col);
    int arr[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter element at index (%d,%d) : ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Your Array is.........\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf(".........\n");

    int i1, j1, i2, j2;
    printf("Enter upper or starting co-ordinate of rectangle (i1,j1): \n");
    scanf("%d %d", &i1, &j1);
    printf("Enter lower or ending co-ordinate (i2,j2): \n");
    scanf("%d %d", &i2, &j2);
if (i1,i2<row && j1,j2 < col && i1,i2,j1,j2 >= 0)
{
    printf("Your Rectangle array is.......\n");
    int sum=0;

    for (int i = i1; i <= i2; i++)
    {
       for (int j = j1; j <= j2; j++)
       {
        sum=sum+arr[i][j];
        printf("%d ",arr[i][j]);
       }
       printf("\n");
    }
    printf(".............................\n");
   
    
    printf("Sum of your rectangle array is: %d \n",sum);

}
else
{
    printf("Invalid Input co-ordinate or not in array range...\n");
}


    return 0;
}