// rotate at 180 degree of a matrix is the transpose of a 90 deg rotated matrix
#include <stdio.h>
int main()
{
    // matrix creation start
    int n;
    printf("Enter number of row/column: ");
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter element at index (%d,%d) : ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Matrix is.........\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }
    // matrix creation end

    // rotate start
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
       for (int k = 0; k < n; k++)
       {
       int temp=arr[i][k];
       arr[i][k]=arr[j][k];
       arr[j][k]=temp;
       }
       
    }

    // rotate end

    printf("Matrix after rotation at 180 deg is....\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}