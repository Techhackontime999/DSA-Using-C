#include <stdio.h>
#include "myfun.h"
#include <stdbool.h>
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
    bool flag=true ;
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
        if (flag==true)
        {
            printf("unique element %d is present at index %d .\n",arr[i],i);
            
        }
        
    }

    return 0;
}