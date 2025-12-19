#include <stdio.h>
#include "myfun.h"
int occurence(int arr[], int size, int element)
{
    int count = 0;

    for (int j = 0; j < size; j++)
    {
        if (element == arr[j])
        {
            count++;
        }
    }

    return count;
}

int main(int argc, char const *argv[])
{
    // array creation start
    int size;
    printf("Enter size of Array: ");
    scanf("%d", &size);
    // 3,4,2,4,3,5
    int arr[size];
    createArr(arr, size);
    printf("\n");
    int element;
    printf("Enter element to check count: ");
    scanf("%d", &element);
    int count = occurence(arr, size, element);
    printf("Occurence of %d in the Array is: %d \n", element, count);

    return 0;
}
