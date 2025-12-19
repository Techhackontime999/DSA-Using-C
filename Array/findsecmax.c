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
    int max = INT_MIN;
    int secmax = INT_MIN;
// 1,2,3,2,4,5

// 
    int secidx=INT_MIN;
    int maxidx=INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i] )
        {
            secmax = max;
            secidx=maxidx;
            max = arr[i];
            maxidx=i;
        }
        else if (secmax<arr[i] && max != arr[i] )
        {
           secmax=arr[i];
           secidx=i;
        }
        
    
    }

    printf("Second Maximum Element %d is Present at index %d . ", secmax,secidx);
    return 0;
}
