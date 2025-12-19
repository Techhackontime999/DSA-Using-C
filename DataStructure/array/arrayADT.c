#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
typedef struct Array
{
    int totalSize;
    int usedSize;
    int *ptr;
} Array;
void createArray(Array *arr, int size)
{
    // (*arr).totalSize = size;
    // (*arr).usedSize = 0;
    // (*arr).ptr = (int *)malloc(size * sizeof(int));

    arr->totalSize = size;

    arr->ptr = (int *)malloc(size * sizeof(int));
    return;
};
void setVal(Array *arr, int usedSize)
{
    for (int i = 0; i < usedSize; i++)
    {
        printf("Enter element at index %d : ", i);
        scanf("%d", &arr->ptr[i]);
    }
    return;
}
void set(Array *arr, int element, int idx)
{
    if (idx < arr->totalSize)
    {
        if (idx >= arr->usedSize)
        {
            if (idx == arr->usedSize)
            {
                arr->ptr[idx] = element;
                arr->usedSize++;
            }
            else
            {
                for (int i = arr->usedSize; i <= idx; i++)
                {

                    arr->usedSize++;
                }
                arr->ptr[idx] = element;
            }
        }
    }
    else
    {
        printf("Invalid index...\n");
    }
}
int get(Array *arr, int idx)
{
    if (idx < arr->totalSize)
    {
        return arr->ptr[idx];
    }
    else
    {
        printf("\nInvalid index...\n");
    }
}
void easyInsert(Array *arr, int element, int idx)
{
    // Insertion
    if (idx < arr->totalSize)
    {
        arr->ptr[arr->usedSize] = arr->ptr[idx];
        arr->ptr[idx] = element;
        arr->usedSize++;
    }
    else
    {
        printf("\nIndex out of range...\n");
    }
}
void hardInsert(Array *arr, int element, int idx)
{
    // Insertion
    // this insertion in array is computationally costly.

    if (idx < arr->totalSize)
    {
        for (int i = arr->usedSize - 1; i >= idx; i--)
        {
            arr->ptr[i + 1] = arr->ptr[i];
        }
        arr->ptr[idx] = element;
        arr->usedSize++;
    }
    else
    {
        printf("\nIndex out of range...\n");
    }
}
void easyDelete(Array *arr, int idx)
{
    // Deletion
    if (idx < arr->totalSize && idx >= 0)
    {
        arr->ptr[idx] = arr->ptr[arr->usedSize - 1];
        arr->usedSize--;
    }
    else
    {
        printf("\nIndex out of range...\n");
    }
}
void hardDelete(Array *arr, int idx)
{
    // Deletion
    // this deletion in array is computationally costly.
    if (idx < arr->totalSize && idx >= 0)
    {
        for (int i = idx; i < arr->usedSize - 1; i++)
        {
            arr->ptr[i] = arr->ptr[i + 1];
        }
        arr->usedSize--;
    }
    else
    {
        printf("\nIndex out of range...\n");
    }
}
void bubbleSort(Array *arr)
{
    // in bubble sort algorithm we compare one element with adjusent element.if adjusent element is less than first then swap it .
    //  exe:- 1,4,5,2,6
    //  no of element=5 then no of passes = 5-1 =4
    //  pass-1
    // i=0: 1,4,5,2,6
    // i=1: 1,4,5,2,6
    // i=2: 1,4,2,5,6
    // i=3: 1,4,2,5,6

    // pass-2
    // i=0: 1,4,2,5,6
    // i=1: 1,4,2,5,6
    // i=2: 1,2,4,5,6
    //  pass-3
    // i=0: 1,2,4,5,6
    // i=1: 1,2,4,5,6

    // pass-4
    // i=0: 1,2,4,5,6

    int noOfPasses = arr->usedSize - 1;
    for (int i = 1; i <= noOfPasses; i++)
    {
        for (int j = 0; j < arr->usedSize - i; j++)
        {
            if (arr->ptr[j + 1] < arr->ptr[j])
            {
                int temp;
                temp = arr->ptr[j];
                arr->ptr[j] = arr->ptr[j + 1];
                arr->ptr[j + 1] = temp;
            }
        }
    }
}
void bubbleSortEffective(Array *arr)
{
    // in bubble sort algorithm we compare one element with adjusent element.if adjusent element is less than first then swap it .
    //  exe:- 1,4,5,2,6
    //  no of element=5 then no of passes = 5-1 =4
    //  pass-1
    // i=0: 1,4,5,2,6
    // i=1: 1,4,5,2,6
    // i=2: 1,4,2,5,6
    // i=3: 1,4,2,5,6

    // pass-2
    // i=0: 1,4,2,5,6
    // i=1: 1,4,2,5,6
    // i=2: 1,2,4,5,6
    //  pass-3
    // i=0: 1,2,4,5,6
    // i=1: 1,2,4,5,6

    // pass-4
    // i=0: 1,2,4,5,6

    // in effective bubble sort if array is sorted by a pass then it not again do extra pass.

    int noOfPasses = arr->usedSize - 1;
    for (int i = 1; i <= noOfPasses; i++)
    {
        bool isSorted = true;
        for (int j = 0; j < arr->usedSize - i; j++)
        {
            if (arr->ptr[j + 1] < arr->ptr[j])
            {
                int temp;
                temp = arr->ptr[j];
                arr->ptr[j] = arr->ptr[j + 1];
                arr->ptr[j + 1] = temp;
                isSorted = false;
            }
        }
        if (isSorted)
        {
            break;
        }
    }
}
void selectionSort(Array *arr)
{
    int noOfPasses = arr->usedSize - 1;

    for (int i = 0; i < noOfPasses; i++)
    {
        int min = INT_MAX;
        int minidx = -1;
        for (int j = i; j < arr->usedSize; j++)
        {
            if (arr->ptr[j] < min)
            {
                min = arr->ptr[j];
                minidx = j;
            }
        }

        arr->ptr[minidx] = arr->ptr[i];
        arr->ptr[i] = min;
    }
    return;
}
void insertionSort(Array *arr)
{
    int temp;

    for (int i = 1; i < arr->usedSize; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr->ptr[j] > arr->ptr[j+1])
            {
                temp = arr->ptr[j+1];
                arr->ptr[j+1] = arr->ptr[j];
                arr->ptr[j] = temp;
            }
        }
    }
    return;
}

void quickSort()
{
}
void mergeSort()
{
}
void heapSort()
{
}

int linearSearch(Array *arr, int element)
{
    // searching in linear manner from sorted or unsorted array
    for (int i = 0; i < arr->usedSize; i++)
    {
        if (arr->ptr[i] == element)
        {
            return i;
        }
    }
    return -1;
}
int binarySearch(Array *arr, int element)
{
    // searching effectively from sorted array
    // here array must be sorted
    int low, mid, high;
    low = 0;
    high = arr->usedSize - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr->ptr[mid] == element)
        {
            return mid;
        }
        if (arr->ptr[mid] > element)
        {
            high = mid - 1;
        }
        if (arr->ptr[mid] < element)
        {
            low = mid + 1;
        }
    }
    return -1;
}

void display(Array *arr)
{
    // Traversal
    for (int i = 0; i < arr->usedSize; i++)
    {
        printf("%d ", arr->ptr[i]);
    }
    printf("\n");
    return;
}

int main()
{
    Array arr;
    int size;
    arr.usedSize = 0;
    int usedSize;
    printf("Enter size of Array: ");
    scanf("%d", &size);
    printf("Number of elements you want to add: ");
    scanf("%d", &usedSize);
    arr.usedSize = usedSize;
    createArray(&arr, size);

    setVal(&arr, usedSize);
    display(&arr);

    // easyInsert(&arr,10,4);
    // hardInsert(&arr,10,2);
    // easyDelete(&arr,2);
    // hardDelete(&arr,1);
    // int idx=linearSearch(&arr,2);
    // int idx = binarySearch(&arr, 2);

    // if (idx == -1)
    // {
    //     printf("\nelement %d is not present in the array..\n", 2);
    // }
    // else
    // {
    //     printf("\nelement %d is present in the array at index %d .\n", 2, idx);
    // }

    // display(&arr);
    // set(&arr, 1, 0);
    // set(&arr, 2, 1);
    // set(&arr, 3, 2);
    // set(&arr, 5, 4);
    // set(&arr, 7, 6);
    // set(&arr, 8, 7);

    // printf("used size %d\n", arr.usedSize);
    // printf("%d ",get(&arr,4));
    // printf("%d ",get(&arr,6));
    // printf("%d ",get(&arr,7));
    // bubbleSort(&arr);
    // bubbleSortEffective(&arr);
    insertionSort(&arr);
    display(&arr);

    return 0;
}