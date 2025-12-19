#include <stdio.h>
int main()
{
    int a[2][3] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    // 1 2 3 
    // 4 5 6
    
    printf("row-col.........\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }
    // 1 4 
    // 2 5 
    // 3 6 
    return 0;
}