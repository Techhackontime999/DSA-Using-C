#include <stdio.h>
#include <stdlib.h>
// this is one of the fastest sortion algorithm which best and average time complexity is o(logn) and in worst case o(n*n) when array is already sorted.
// this sorting algorithm is stable because arr[i]==pivot then it dont care it and increase to next and when arr[j]<=pivot then arr[j] swap with pivot so if arr[j] and pivot both are same then it not swap but giving illusion of swap.
int count = 0;
int swapcount = 0;
int partion(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;
    // repeat below code untill j<i and swap a[j] with pivot .
    // here we use do while loop that runs at least one time when condition also not satisfy because we need to reach position j<i .so here in condition we use i<j then it work one extra for i==j or i!<j then final when j<i or i>j then condition false and loop break  and we reach to  the desire place where we set pivot that is the right pivot place
    do
    {
        count++;
        while (arr[i] <= pivot)
        {
            i++;
            count++;
        }
        while (arr[j] > pivot)
        {
            j--;
            count++;
        }
        // we here swap when i<j not when i==j then no need to swap both same element.
        if (i < j)
        {
            swapcount++;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }

    } while (i < j);
    // now we set pivot to the right position in a sorted array when j<i
    temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;
    return j;
}

void quickSort(int *arr, int low, int high)
{
    int partionIndex;
    // low<high means array is of atleast two element.
    // low==high means array is of only one element
    // low>high invalid index
    if (low < high)
    {
        count++;
        partionIndex = partion(arr, low, high);
        quickSort(arr, low, partionIndex - 1);
        quickSort(arr, partionIndex + 1, high);
    }
  
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
        arr[i] = i + 1;
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
    quickSort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
    free(arr);
      printf("\ntotal no of times to sort: %d \n", count);
    printf("total no of swaps : %d \n", swapcount);
    return 0;
}