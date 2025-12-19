// Radix Sort is a non-comparison-based sorting algorithm that sorts numbers by processing individual digits. It processes digits from the least significant to the most significant (LSD) or vice versa (MSD).
// in 451 , 1 is the least significant digit and 4 is the most significant digit.
// Example:
// Consider the list [170, 45, 75, 90, 802, 24, 2, 66].

// Sort by least significant digit (LSD): [170, 90, 802, 2, 24, 45, 75, 66].

// Sort by next digit: [802, 2, 24, 45, 66, 170, 75, 90].

// Sort by most significant digit: [2, 24, 45, 66, 75, 90, 170, 802].

// Use Cases:
// Efficient for sorting large lists of numbers.

// Commonly used in card sorting algorithms and other applications with fixed digit lengths.

// in this problem we need to sort the array by least significant digit to most significant digit.
// in this sort we need to sort by digit in each pass and we know digit go from 0 to 9 for fast working of this algorithm we can use here count sort.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
int noOfDigit(int num)
{
    int count = 0;
    while (num != 0)
    {
        num = num / 10;
        count++;
    }

    return count;
}

int *SortDigitArray(int *arr, int size)
{
    int *brr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        brr[i] = arr[i];
    }
    int maxNum = INT_MIN;
    int *indexarr = (int *)malloc(size * (sizeof(int)));
    for (int i = 0; i < size; i++)
    {
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
        count[i] = 0;
        // printf(" %d ",count[i]);
    }

    for (int i = 0; i < size; i++)
    {
        count[arr[i]] = count[arr[i]] + 1;
        // here i help me to decide element in arr index in the beginning.

        // printf(" %d ",count[arr[i]]);
    }

    int k = 0, i = 0;
    while (i <= maxNum)
    {
        if (count[i] > 0)
        {
            arr[k] = i;
            // here i is the actual element of arr

            // here k is the index of sorted array
            k++;

            count[i] = count[i] - 1;
        }
        else
        {
            i++;
        }
    }

    free(count);
    // here we checking sorted arr
    //  printf("\n");

    // for (int i = 0; i < size; i++)
    // {
    //     printf(" %d ", arr[i]);
    // }
    // printf("\n");
    // now we finding and assigning index of sorted element in indexarr
    bool *check = (bool *)malloc(size * sizeof(bool));
    for (int i = 0; i < size; i++)
    {
        check[i] = false;
    }
    for (int i = 0; i < size; i++)
    {

        for (int j = 0; j < size; j++)
        {
            if (brr[i] == arr[j] && check[j] == false)
            {
                indexarr[i] = j;
                check[j] = true;

                break;
            }
        }
    }
    // below loop checking indexarr
    // for (int i = 0; i < size; i++)
    // {
    //     printf(" %d ", indexarr[i]);
    // }
    // printf("\n");

    // below is for testing
    //  int l = size - 1;
    //  for (int i = 0; i < size; i++)
    //  {
    //      indexarr[i] = l;
    //      l--;
    //  }
    //  for (int i = 0; i < size; i++)
    //  {
    //    indexarr[i]=i;
    //  }

    return indexarr;
}
int maxcount = 0;
int maxNoOfDigit = 2;

void radixSort(int *arr, int size)
{

    int *brr = (int *)malloc(size * sizeof(int));
    // this brr array helps me to create indexArr
    // int maxNoOfDigit = 0;
    int *indexArr;
    // below loop copy the arr in brr and find maxNoofdigit in brr
    for (int i = 0; i < size; i++)
    {
        brr[i] = arr[i];
        // if (noOfDigit(arr[i]) > maxNoOfDigit)
        // {
        //     maxNoOfDigit = noOfDigit(arr[i]);
        // }
    }

    int *digitarr = (int *)malloc(size * (sizeof(int)));
    // for (int i = 0; i < maxNoOfDigit; i++)
    // {
    if (maxcount < maxNoOfDigit)
    {
        for (int i = 0; i < size; i++)
        {
            digitarr[i] = brr[i] % 10;

            brr[i] = brr[i] / 10;
        }

    }
    // digitarr change after each maxNoofDigit traversal
    //  printf("\n");

    // for (int i = 0; i < size; i++)
    // {
    //     printf(" %d ",digitarr[i]);
    // }
    // printf("\n");

    // below loop helps me to deside number of times maxNoofDigit run
    //  printf("\n");
    //  for (int i = 0; i < size; i++)
    //  {
    //      printf(" %d ", brr[i]);
    //  }
    //  printf("\n");
    //  here we pass digitarray in each maxNoofdigit present in brr or arr
    indexArr = SortDigitArray(digitarr, size);
    // below loop verfiy indexArr
    // printf("\n");
    // for (int i = 0; i < size; i++)
    // {
    //     printf(" %d ", indexArr[i]);
    // }
    // printf("\n");
    //  below sort the arr based on indexArr index that is the least significant digit index.
    int temp;
    bool *check = (bool *)malloc(size * sizeof(bool));
    for (int i = 0; i < size; i++)
    {
        check[i] = false;
    }

    for (int i = 0; i < size; i++)
    {
        if (check[i] == false)
        {
            check[indexArr[i]] = true;
            check[i] = true;
            temp = arr[indexArr[i]];
            arr[indexArr[i]] = arr[i];
            arr[i] = temp;
        }
    }
    // below loop helps me to check arr is uppdating after sorting by least significant bit or not.
    // printf("\n");

    // for (int i = 0; i < size; i++)
    // {
    //     printf(" %d ", arr[i]);
    // }
    // printf("\n");

    // }
    if (maxcount < maxNoOfDigit)
    {
        radixSort(arr, size);
        maxcount++;
    }

    return;
}
int main()
{
    int *arr = (int *)malloc(10 * sizeof(int));
    arr[0] = 10;
    arr[1] = 13;
    arr[2] = 9;
    arr[3] = 11;
    arr[4] = 17;
    arr[5] = 4;
    arr[6] = 20;
    arr[7] = 21;
    arr[8] = 16;
    arr[9] = 7;
    // int k=9;
    // for (int i = 0; i < 10; i++)
    // {
    //     arr[i] = k;
    //     k--;
    // }
    //    for (int i = 0; i < 10; i++)
    // {
    //     arr[i] = i;
    // }
    // for (int i = 5; i < 10; i++)
    // {
    //     arr[i] = 20+i + 1;
    // }
    for (int i = 0; i < 10; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
    radixSort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        printf(" %d ", arr[i]);
    }
    // printf("\n");
    free(arr);

    // printf("%d\n",noOfDigit(123));
    return 0;
}