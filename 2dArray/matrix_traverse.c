// matrix traverse in place means traverse the matrix without creating an extra array.
// but in this problem we do traverse using an extra array here we can take matrix of both n x m and n x n
#include <stdio.h>
#include <limits.h>
int main()
{
    // matrix creation start
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
    printf("Matrix is.........\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }
    // matrix creation end
    // traverse start
    int brr[col][row];
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            brr[i][j] = arr[j][i];
        }
    }
printf("Traverse Array is....\n");
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf("%d ", brr[i][j]);
        }
        printf("\n");
    }

    // traverse end

    return 0;
}