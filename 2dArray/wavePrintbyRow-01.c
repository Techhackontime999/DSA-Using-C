// 1 2 3 
// 4 5 6
// 7 8 9
// row-waveprint 1,2,3,6,5,4,7,8,9
#include <stdio.h>
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
    printf("Wave printing...\n");
    // swap of element or reverse in odd row start
    for (int i = 0; i < row; i++)
    {
        if (i % 2 != 0)
        {
            for (int j = 0, k = col - 1; j < k; j++, k--)
            {

                int temp;
                temp = arr[i][j];
                arr[i][j] = arr[i][k];
                arr[i][k] = temp;
            }
        }
    }
    // swap of element or reverse in odd row end
    printf("Elements in wave are: ");
    for (int i = 0; i < row; i++)
    {
        for (int k = 0; k < col; k++)
        {
            printf("%d ",arr[i][k]);

        }
        
    }
    
    return 0;
}