#include <stdio.h>
#include "myfun.h"
#include <stdbool.h>

int countunique(int arr[], int size)
{
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
void elementAtIndex(int arr[], int size, int element)
{
    int idx;
    int idxArr[size - countunique(arr, size)];
int notinarr=-1;
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            idx = i;
            idxArr[j] = idx;
            j++;
            notinarr=0;
        }
      
        
    }
printf("Element %d is present at index: ",element);
    printArr(idxArr, j);
if (notinarr==-1)
{
   printf("%d ",notinarr);
}


    return;
}


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
    int num;
    printf("Enter number to find its index: ");
    scanf("%d",&num);
    elementAtIndex(arr, size, num);

    return 0;
}