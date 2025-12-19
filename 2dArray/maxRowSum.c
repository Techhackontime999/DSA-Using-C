#include <stdio.h>
#include <limits.h>
int main()
{
    int row, col;
    int max = INT_MIN;
    int sum = 0;
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
    int idx;
    printf("Your Array is.........\n");
    for (int i = 0; i < row; i++)
    {
        sum = 0;

        for (int j = 0; j < col; j++)
        {
            sum = sum + arr[i][j];
            printf("%d ", arr[i][j]);
        }
        if (max < sum)
        {
            max = sum;
            idx = i;
        }

        printf("\n");
    }
    printf("Row index %d is the row with maximum sum in the array is....\n", idx);
    for (int j = 0; j < col; j++)
    {
        printf("%d ", arr[idx][j]);
    }
    printf("\nsum of this max row is: %d ", max);

    return 0;
}