#include <stdio.h>
void arrWithMissing(int missing, int arrsize, int arr[])
{

    if (missing <= arrsize + 1)
    {

        for (int i = 0; i < arrsize + 1; i++)
        // i= 0,99 100 element 1-100
        // o,98 99 element 1-100 except missing element
        {
            if (i < missing && i != arrsize)
            {
                arr[i] = i + 1;
            }

            if (i + 1 == missing && i != arrsize)
            // this if statement check element at index(77)+1==missing
            // this check equal when i=77
            {
                arr[i] = missing + 1;
                missing++;
            }

            if (i >= missing && i != arrsize)
            // if index(78) >= missing(78)       element at index 78 is 79 after this if execution
            // this check equal when i=78
            {

                arr[i] = missing + 1;
                missing++;
            }
        }
        printf("Your Array with missing element is : [ ");
        for (int i = 0; i < arrsize; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("]\n");
    }
    else
    {
        printf("Missing element %d not in your Array range [ %d - %d ] \n", missing, 1, arrsize + 1);
    }

    return;
}
int sumMissingElement(int arr[], int size)
{

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }

    return sum;
}

int main()
{
    int missing = 1;
    int size = 9;
    int arr[size];
    arrWithMissing(missing, size, arr);
    int missingsum = sumMissingElement(arr, size);
    int sum = 0;
    int j;
    for (int i = 0; i < size + 1; i++)
    {
        j = i + 1;
        sum = sum + j;
    }
    if (missing <= size + 1)
    {
        /* code */

        printf("sum without missing is: %d \n", sum);

        printf("sum with missing is: %d \n", missingsum);
        int finalmissing;
        printf("Missing Element in your Array is : %d ", sum - missingsum);
    }

    return 0;
}