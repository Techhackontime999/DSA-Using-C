#include <stdio.h>
#include <stdlib.h>
int count=0;
int swapcount=0;
void merge(int *arr, int low, int mid, int high)
{
    count++;
    int *A = (int *)malloc((high+1) * sizeof(int));
    int i = low;     // i runs low to mid
    int j = mid + 1; // j runs mid+1 to high
    int k = low;       // k runs for array A
    while (i <= mid && j <= high)
    {
        count++;
        if (arr[i] <= arr[j])
        {
            A[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            A[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        count++;
        A[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        count++;
        A[k] = arr[j];
        k++;
        j++;
    }
    // now updating actual array arr with array A
    for (int i = low; i <= high; i++)
    {
        count++;
        arr[i] = A[i];
    }
    free(A);
    return;
}
void mergeSort(int *arr, int low, int high)
{
    count++;
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
    return;
}
int main()
{
    int *arr = (int *)malloc(10 * sizeof(int));
    arr[0] = 10;
    arr[1] = 13;
    arr[2] = 9;
    arr[3] = 11;
    arr[4] = 17;
    arr[5] = 4;
    arr[6] = 20;
    arr[7] = 21;
    arr[8] = 16;
    arr[9] = 7;
    // for (int i = 0; i < 10; i++)
    // {
    //     arr[i] = i + 1;
    // }
    // for (int i = 5; i < 10; i++)
    // {
    //     arr[i] = 20+i + 1;
    // }
    for (int i = 0; i < 10; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
    mergeSort(arr, 0, 9);
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