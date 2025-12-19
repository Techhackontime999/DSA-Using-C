#include <stdio.h>
#include <limits.h>
int main()
{
    int row, col;
    int checkpoint = -1;
    // array creation start
    printf("Enter number of row: ");
    scanf("%d", &row);
    printf("Enter number of column: ");
    scanf("%d", &col);
    int arr[row][col];
    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {
            printf("Enter element at index (%d,%d) either 0 or 1: ", i, j);
            scanf("%d", &arr[i][j]);
        }
        for (int j = 0; j < col; j++)
        {

            // comment out when wants to work checkpoint
            // if (arr[i][j] != 0 || arr[i][j] != 1) // we can write condition here (arr[i][j] !=0,1 )  directly
            // {
            //     printf("Please enter the valid input binary...\n");
            //     checkpoint = 1;
            //     break;
            // }
        }
        if (checkpoint == 1)
        {
            break;
        }
    }

    if (checkpoint == -1)
    {
        /* code */

        printf("Your Array of Binary is.........\n");

        for (int i = 0; i < row; i++)
        {

            for (int j = 0; j < col; j++)
            {
                printf("%d ", arr[i][j]);
            }

            printf("\n");
        }
    }

// array creation close 
//now we need to find max no of 1's in which row.
int rowcount=0;
int maxcount=INT_MIN;
int idx;
for (int i = 0; i < row; i++)
{
    rowcount=0;
    for (int j = 0; j < col; j++)
    {
        if (arr[i][j]==1)
        {
           rowcount++;
        }
        if (maxcount<rowcount)
        {
            maxcount=rowcount;
            idx=i;
        }     
        
    }
    
}
printf("Row index which contain max no of 1's is: %d .\n",idx);


    return 0;
}