#include <stdio.h>
#include <stdlib.h>
// in this problem we merge two sorted part of array present in a array using this only single array.
void merge(int *arr, int low, int mid, int high)
{
    int *A = (int *)malloc(high * sizeof(int));
    int i = low, j = mid, k = low;
    while (i < mid && j < high)
    {
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
    while (i < mid)
    {
        A[k] = arr[i];
        k++;
        i++;
    }
    while (j < high)
    {
        A[k] = arr[j];
        k++;
        j++;
    }

    for (int i = 0; i < high; i++)
    {
        arr[i] = A[i];
    }
    free(A);
    return;
}
int main()
{
    int *arr, n2, n1;
    printf("Enter size of first part of sorted array: ");
    scanf("%d", &n1);
    printf("Enter size of second part of sorted array: ");
    scanf("%d", &n2);
    arr = (int *)malloc((n1 + n2) * sizeof(int));
    printf("\nFirst part of sorted array...\n");

    for (int i = 0; i < n1; i++)
    {
        printf("Enter element arr[%d] : ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n");
    printf("\nSecond part of sorted array...\n");

    for (int i = n1; i < n1 + n2; i++)
    {
        printf("Enter element arr[%d] : ", i);
        scanf("%d", &arr[i]);
    }
    int low = 0, mid = n1, high = n1 + n2;
    merge(arr, low, mid, high);
    printf("\nMerged sorted array is: ");
    for (int i = 0; i < n1 + n2; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
    free(arr);

    return 0;
}