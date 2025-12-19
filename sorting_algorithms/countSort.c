#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void countSort(int *arr, int size)
{
    int maxNum = INT_MIN;
    int noOfCount=0;
    int swapcount=0;
    for (int i = 0; i < size; i++)
    {
        noOfCount++;
        if (arr[i] > maxNum)
        {
            maxNum = arr[i];
        }
    }
    // printf("\nMaximum num is:  %d \n",maxNum);

    int *count = (int *)malloc((maxNum + 1) * sizeof(int));
    for (int i = 0; i <= maxNum; i++)
    {
        // printf("\nMaximum num is:  %d \n",maxNum);
noOfCount++;
        count[i] = 0;
        // printf(" %d ",count[i]);
    }

    for (int i = 0; i < size; i++)
    {
        noOfCount++;
        count[arr[i]] = count[arr[i]] + 1;
        // printf(" %d ",count[arr[i]]);
    }
  
    int k = 0, i = 0;
    while (i <= maxNum)
    {
        noOfCount++;
        if (count[i] > 0)
        {
            arr[k] = i;
            k++;
            count[i] = count[i] - 1;
        }
        else
        {
            i++;
        }
    }

    free(count);
      printf("\ntotal no of times to sort: %d \n", noOfCount);
    printf("total no of swaps : %d \n", swapcount);
    return;
}
int main()
{
    int *arr = (int *)malloc(10 * sizeof(int));
    arr[0] = 10;
    arr[1] = 10;
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
    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");

    countSort(arr, 10);
    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}