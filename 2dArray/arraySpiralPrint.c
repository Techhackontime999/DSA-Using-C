// we need to create a spiral matrix .in which i can easily print its element in a spiral manner using spiral matrix
#include <stdio.h>
#include <stdbool.h>
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
    // spiral matrix creation start
    int tne = row * col;
    int minr = 0;
    int maxr = row - 1;
    int maxcol = col - 1;
    int mincol = 0;
    int count = 0;
    printf("Spiral element is: ");
    while (count < tne)
    {
        // printing minimum row
        for (int j = mincol; j <= maxcol; j++)
        {
            printf("%d ", arr[minr][j]);
            count++;
        }
        minr++;
        // printing maximum column
        for (int i = minr; i <= maxr; i++)
        {
            printf("%d ", arr[i][maxcol]);

            count++;
        }
        maxcol--;
        // printing maximum row
        for (int j = maxcol; j >= mincol; j--)
        {
            printf("%d ", arr[maxr][j]);

            count++;
        }
        maxr--;
        // printing minimum column
        for (int i = maxr; i >= minr; i--)
        {
            printf("%d ", arr[i][mincol]);

            count++;
        }
        mincol++;
    }

    // spiral matrix creationend

    return 0;
}