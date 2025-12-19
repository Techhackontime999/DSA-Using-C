#include <stdio.h>
#include "myfun.h"
#include <limits.h>
int main()
{
    int size;
    printf("Enter size of Array: ");
    scanf("%d", &size);
    int arr[size];
    createArr(arr, size);
    printf("\n");
    int min=INT_MAX;
    int idx;
    for (int i = 0; i < size; i++)
    {
        if (min>arr[i])
        {
            min=arr[i];
            idx=i;
        }
        
    }
    printf("Minimum Element %d is Present at Index %d ",min,idx);
    return 0;
}
