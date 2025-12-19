// 1 2 3
// 4 5 6
// 7 8 9
// col-waveprint 1,4,7,8,5,2,3,6,9
// for doing this first we need to create a matrix that print element column wise rather than row wise then
// we reverse the odd row of that new matrix then i getting a final matrix that prints element row-wise but element in the this matrix is column wavePrint form
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
    printf("Wave printing by col...\n");
    // row to column transformation start
    // traverse start
    int brr[col][row];
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            brr[i][j] = arr[j][i];
        }
    }

    // traverse end

    // row to column transformation end

    // swap of element or reverse in odd row start
    for (int i = 0; i < col; i++)

    {
        if (i % 2 != 0)
        {
            for (int j = 0, k = row - 1; j < k; j++, k--)
            {

                int temp;
                temp = brr[i][j];
                brr[i][j] = brr[i][k];
                brr[i][k] = temp;
            }
        }
    }

    // swap of element or reverse in odd row end
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf("%d ", brr[i][j]);
        }
    }

    return 0;
}