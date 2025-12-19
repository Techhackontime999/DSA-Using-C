#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// time complexity of this sorting algorithm is also o(n*n) for both sorted and unsorted array input.
// this sorting algorithm is unstable because when two same value present then order may change after sorting.
//  void selectionSort(int *arr, int size)
//  {
//      int count=0;
//      int swapcount=0;

//     for (int i = 0; i < size - 1; i++)
//     {
//         int min = INT_MAX;
//         int minIdx = INT_MAX;
//         for (int j = i; j < size ; j++)
//         {
//             count++;
//             if (arr[j] < min)
//             {
//                 min = arr[j];
//                 minIdx = j;
//             }
//         }
//         swapcount++;
//         int temp = arr[i];
//         arr[i] = min;
//         arr[minIdx] = temp;
//     }
//     printf("\ntotal no of times to sort: %d \n", count);
//     printf("total no of swaps : %d \n", swapcount);

//     return;
// }
void selectionSort(int *arr, int size)
{
    int count = 0;
    int swapcount = 0;

    for (int i = 0; i < size - 1; i++)
    {
        int min = arr[i];
        int minIdx = i;
        for (int j = i + 1; j < size; j++)
        {
            count++;
            if (arr[j] < min)
            {
                min = arr[j];
                minIdx = j;
            }
        }
        if (min != arr[i])
        {
            swapcount++;
            int temp = arr[i];
            arr[i] = min;
            arr[minIdx] = temp;
        }
        
    }
    printf("\ntotal no of times to sort: %d \n", count);
    printf("total no of swaps : %d \n", swapcount);

    return;
}
int main()
{
    int *arr = (int *)malloc(10 * sizeof(int));
    // arr[0] = 10;
    // arr[1] = 13;
    // arr[2] = 9;
    // arr[3] = 11;
    // arr[4] = 17;
    // arr[5] = 4;
    // arr[6] = 20;
    // arr[7] = 21;
    // arr[8] = 16;
    // arr[9] = 7;
    for (int i = 0; i < 10; i++)
    {
        arr[i]=i+1;
    }
    // for (int i = 5; i < 10; i++)
    // {
    //     arr[i] = 20 + i + 1;
    // }
    for (int i = 0; i < 10; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
    selectionSort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}