// matrix traverse in place means traverse the matrix without creating an extra array.here we can take only matrix of both n x n i.e a square matrix

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
    // traverse start
    for (int i = 0; i < n; i++)
    {
        // this loop ensure swap occur only at once time i.e 1,0 is swap with 0,1 then 0,1 not swap again with 1,0
        // for (int j = 0; j <= i; j++)
        for (int j = i; j < n; j++)//  here we can also use it

        {
            int temp;
            temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
    printf("Traverse Array is....\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    // traverse end

    return 0;
}