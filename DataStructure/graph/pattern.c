#include <stdio.h>
int main()
{
    // for (int i = 0; i < 4; i++)
    // {
    //    for (int j = 0; j < i; j++)
    //    {
    //     printf(" * ");
    //    }
    //    printf("\n");
    // }

    // for (int i = 4; i >= 0; i--)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         printf(" * ");
    //     }
    //      printf("\n");
    // }
    int k = 0;
    for (int i = 4; i >= 0; i--)
    {
        for (int j = 0; j < k; j++)
        {
            printf(" # ");
        }
        for (int j = 0; j < i; j++)
        {
            printf(" * ");
        }
        printf("\n");
        k++;
    }

    return 0;
}