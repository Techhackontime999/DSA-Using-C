#include <stdio.h>
#include <stdlib.h>
// in this searching algorithm best case time complexity is o(1) and worst and average case time complexity is o(n)
// this search is work for both sorted and unsorted array
int main()
{
    int *arr = (int *)malloc(15 * sizeof(int));
    for (int i = 0; i < 15; i++)
    {
        arr[i] = i + 1;
    }

    int element = 85;
    int count = 0;
    int idx = -1;
    for (int i = 0; i < 15; i++)
    {
        count++;

        if (element == arr[i])
        {
            idx = i;

            break;
        }
    }
    free(arr);
    printf("\nElement %d is found at index: %d\n", element, idx);
    printf("\nNo of comparison to search : %d \n", count);
    return 0;
}