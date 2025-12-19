#include <stdio.h>
// printArr printing an Array
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return;
}
// arrInput taking Input inside array
void arrInput(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter %d element at index %d : ", i + 1, i);
        scanf("%d", &arr[i]);
    }
    return;
}
// createArr create,takeinput,print a full array after creation
void createArr(int arr[], int size)
{

    arrInput(arr, size);
    printf("Array is: ");
    printf("[ ");
    printArr(arr, size);
    printf("]");

    return;
}
