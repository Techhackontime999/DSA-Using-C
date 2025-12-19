#include <stdio.h>

int main()
{
    int row1, col1, row2, col2;
    printf("Enter (row,col) of first matrix: \n");
    scanf("%d %d", &row1, &col1);
    printf("Enter (row,col) of second matrix: \n");
    scanf("%d %d", &row2, &col2);
    int arr[row1][col1], brr[row2][col2], mularr[row1][col2];
    int row_col = col1;
    if (col1 == row2)
    {
        // matrix creation start
        printf("Enter element in first matrix...\n");

        for (int i = 0; i < row1; i++)
        {

            for (int j = 0; j < col1; j++)
            {
                printf("Arr[%d][%d] --> ", i, j);

                scanf("%d", &arr[i][j]);
            }
        }
        printf("Matrix-1 is.........\n");
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col1; j++)
            {
                printf("%d ", arr[i][j]);
            }

            printf("\n");
        }

        printf("Enter element in second matrix...\n");

        for (int i = 0; i < row2; i++)
        {

            for (int j = 0; j < col2; j++)
            {
                printf("Arr[%d][%d] --> ", i, j);

                scanf("%d", &brr[i][j]);
            }
        }
        printf("Matrix-2 is.........\n");
        for (int i = 0; i < row2; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                printf("%d ", brr[i][j]);
            }

            printf("\n");
        }
        printf("Multilication of both Matrix is.........\n");

        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                mularr[i][j]=0;
                for (int k = 0; k < row_col; k++)
                {
                    mularr[i][j] += arr[i][k] * brr[k][j];
                }
            }
        }
        for (int i = 0; i < row1; i++)
        {
           for (int j = 0; j < col2; j++)
           {
           
            printf("%d ",mularr[i][j]);
           }
           printf("\n");
        }
        

        //    multiplication end
    }
    else
    {
        printf("Please enter column in the first matrix is equal to row in the second matrix...\n");
    }

    return 0;
}