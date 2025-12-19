#include <stdio.h>
#include <stdlib.h>
// it is one of the sorting algorithm which time complexity is o(n*n).
// it is also stable. i.e not change order either if element is same
void insertionSort(int *arr, int size)
{
    int swapcount = 0, count = 0;

    for (int i = 1; i < size; i++)
    {
        count++;
        int j = i;
        while (arr[j] < arr[j - 1] && j >= 1)
        {
            count++;
            swapcount++;
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
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
        arr[i] = i + 1;
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
    insertionSort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}