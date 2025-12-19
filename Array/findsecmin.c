#include <stdio.h>
#include "myfun.h"
#include <limits.h>
int main()
{
    // // method-01
    // int size;
    // printf("Enter size of Array: ");
    // scanf("%d", &size);
    // int arr[size];
    // createArr(arr, size);
    // printf("\n");
    // int max=INT_MIN;
    // int secmax=INT_MIN;

    // int idx;
    // for (int i = 0; i < size; i++)
    // {
    //     if (max<arr[i])
    //     {
    //         max=arr[i];
    //     }

    // }
    //    for (int i = 0; i < size; i++)
    // {
    //     if (secmax<arr[i] && arr[i] != max)
    //     {
    //         secmax=arr[i];
    //         idx=i;
    //     }

    // }

    // method-02 using one loop
    int size;
    printf("Enter size of Array: ");
    scanf("%d", &size);
    int arr[size];
    createArr(arr, size);
    printf("\n");
    int min = INT_MAX;
    int secmin = INT_MAX;
// 1,2,3,2,4,5

// 
    int secidx=INT_MIN;
    int minidx=INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (min > arr[i] )
        {
            secmin = min;
            secidx=minidx;
            min = arr[i];
            minidx=i;
        }
        else if (secmin>arr[i] && min != arr[i] )
        {
           secmin=arr[i];
           secidx=i;
        }
        
    
    }

    printf("Second Minimum Element %d is Present at index %d . ", secmin,secidx);
    return 0;
}
