#include <stdio.h>
#include "myfun.h"
#include <stdbool.h>
int main(void)
{
    // array creation start
    int size;
    printf("Enter size of Array: ");
    scanf("%d", &size);
    // 3,4,2,4,3,5
    int arr[size];
    // 1,1,2,2,4
    createArr(arr, size);
    printf("\n");
    bool check[size];
    for (int i = 0; i < size; i++)
    {
        check[i] = false;
    }
    printf("Duplicate element in the array are: ");
    for (int i = 0; i < size; i++)
    {
        if (check[i] == false)
        {

            check[i] = true;
        }
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                check[j] = true;
            }
        }

        //    here we meet a final check array which help to determine element is a duplicate or not
        for (int k = 0; k < size; k++)
        {
            if (check[i] == check[k] && i != k)
            {

            printf("%d ",arr[i]);

                break;
            }
        }
        for (int i = 0; i < size; i++)
        {
            check[i] = false;
        }
    }
        return 0;
    }