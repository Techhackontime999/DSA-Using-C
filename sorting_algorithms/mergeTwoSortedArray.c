#include <stdio.h>
#include <stdlib.h>
// in this problem we merge two sorted array with the help of third array and produce sorted merged array
int *mergeTwoSortedArray(int *arr1, int *arr2, int n1, int n2)
{
    int *arr = (int *)malloc((n1 + n2) * sizeof(int));
    int i = 0; // pointer for arr1
    int j = 0; // pointer for arr2
    int k = 0; // pointer for arr
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[k] = arr1[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = arr2[j];
        k++;
        j++;
    }
    return arr;
}
int main()
{
    int *arr1, *arr2, n1, n2;
    printf("Enter size of first array: ");
    scanf("%d", &n1);
    arr1 = (int *)malloc(n1 * sizeof(int));
    for (int i = 0; i < n1; i++)
    {
        printf("Enter element arr[%d] : ", i);
        scanf("%d", &arr1[i]);
    }
    printf("\n");
    printf("Enter size of second array: ");
    scanf("%d", &n2);
    arr2 = (int *)malloc(n2 * sizeof(int));
    for (int i = 0; i < n2; i++)
    {
        printf("Enter element arr[%d] : ", i);
        scanf("%d", &arr2[i]);
    }
    int *arr = mergeTwoSortedArray(arr1, arr2, n1, n2);
    printf("Merged Array is: ");
    for (int i = 0; i < (n1 + n2); i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
    free(arr1);
    free(arr2);
    free(arr);

    return 0;
}