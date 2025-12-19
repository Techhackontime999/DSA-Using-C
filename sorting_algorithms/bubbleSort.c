#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// time complexity of this sorting algorithm is o(n*n) for both sorted and unsorted array input by default.
// but using check for already sorted we can check and return already sorted array in o(n)
//this sorting algorithm is stable because when two same value present then order not be change after sorting.

//  //without sorted check
//  void bubbleSort(int *arr,int size)
//  {
//      int count=0;
//      int swapcount=0;
//     int  noOfPasses=size-1;
//      for (int i = 0; i < size-1; i++)
//      {
//        for (int j = 0; j < size-i-1; j++)
//        {
//          count++;
//          if (arr[j]>arr[j+1])
//          {
//             swapcount++;
//             int temp=arr[j];
//             arr[j]=arr[j+1];
//             arr[j+1]=temp;
//          }

//       }

//     }
//      printf("\ntotal no of times to sort: %d \n", count);
//     printf("total no of swaps : %d \n", swapcount);
//     return;

// }

// with sorted check
void bubbleSort(int *arr, int size)
{
    int count = 0;
    int noOfPasses = size - 1;
    bool isSorted = true;
    int swapcount=0;
    for (int i = 0; i < size - 1; i++)
    {
        isSorted = true;
        for (int j = 0; j < size - i - 1; j++)
        {
            count++;
            if (arr[j] > arr[j + 1])
            {
                swapcount++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = false;
            }
        }
        if (isSorted)
        {
            break;
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
    //     arr[i] = 20+i + 1;
    // }
    for (int i = 0; i < 10; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
    bubbleSort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}