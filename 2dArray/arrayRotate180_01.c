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
    // traverse start
    int temp;

    for (int i = 0; i < n; i++)
    {
        // this loop ensure swap occur only at once time i.e 1,0 is swap with 0,1 then 0,1 not swap again with 1,0
        // for (int j = 0; j <= i; j++)
        for (int j = i; j < n; j++) //  here we can also use it

        {
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
        // reverse each row close

           for (int j = 0, k = n-1; j < k; j++, k--)
            {
                temp = arr[i][j];
                arr[i][j] = arr[i][k];
                arr[i][k] = temp;
            }
     // reverse each row start


    }
  
   
    for (int i = 0; i < n; i++)
    {
          //  again traverse start
     for (int j = i; j < n; j++) //  here we can also use it

        {
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
        // again traverse end
    }
    

    printf("Matrix after rotation at 180 deg is....\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // traverse end

    return 0;
}