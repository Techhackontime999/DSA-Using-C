#include <stdio.h>
#include "myfun.h"
#include<stdbool.h>
int main()
{
    // array creation start
    int size;
    printf("Enter size of Array: ");
    scanf("%d", &size);
    // 3,4,2,4,3,5
    int arr[size];
    createArr(arr, size);
    printf("\n");
    bool flag=false;
    // array creation end
    // now we need to find duplicates is present in the array or not
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
               flag=true;
               break;
            }
          
        }
    }

if (flag==true)
{
   printf("duplicate element is present in the array. \n");

}
else{
   printf("duplicate element is not present in the array. \n");

}

    return 0;
}