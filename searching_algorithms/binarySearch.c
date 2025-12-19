#include <stdio.h>
#include <stdlib.h>
// binary search is work only for sorted array.
// it is one of the best searching algorithm that search element in o(logn) time complexity in both best average and worst case.
int main()
{
    int *arr = (int *)malloc(20 * sizeof(int));
    for (int i = 0; i < 20; i++)
    {
        arr[i] = i + 1;
    }
    int element = 21;
    int count = 0;
    int low = 0;
    int high = 19;
    int mid;
    int idx = -1;
    while (low < high)
    {
        count++;
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            idx = mid;
            break;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else if (arr[mid] > element)

        {
            high = mid - 1;
        }
    }
    free(arr);
    printf("\nElement %d is found at index: %d\n", element, idx);
    printf("\nNo of comparison to search : %d \n", count);
    return 0;
}