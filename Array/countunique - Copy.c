#include <stdio.h>
#include "myfun.h"
#include <stdbool.h>
int countunique(int arr[],int size){
 bool flag = true;
    int count = 0;
    // array creation end
    // now we need to find unique element is present in the array or not
    for (int i = 0; i < size; i++)
    {

        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j] && i != j)
            {
                flag = false;
                break;
            }
            else if (arr[i] != arr[j] && i != j)
            {
                flag = true;
            }
        }
        if (flag == true)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    // array creation start
    int size;
    printf("Enter size of Array: ");
    scanf("%d", &size);
    // 3,4,2,4,3,5
    int arr[size];
    // 1,1,2,2,4
    createArr(arr, size);
    printf("\n");
    int count=countunique(arr,size);
    printf("The number of unique elements in the array is : %d \n",count);

    return 0;
}