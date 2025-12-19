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
    int max=INT_MIN;
    int idx;
    for (int i = 0; i < size; i++)
    {
        if (max<arr[i])
        {
            max=arr[i];
            idx=i;
        }
        
    }
    printf("Maximum Element %d is Present at Index %d ",max,idx);
    return 0;
}
