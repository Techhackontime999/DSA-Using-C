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
            break;
        }
        
    }

    if (flag == true)
    {
        printf("unique element is present in the array. \n");
    }
    else if(flag==false)
    {
        printf("unique element is not present in the array. \n");
    }

    return 0;
}

















// best program to find all numbers present in the array without duplication

// #include <stdio.h>
// #include "myfun.h"
// #include<stdbool.h>
// int main(void)
// {
//     // array creation start
//     int size;
//     printf("Enter size of Array: ");
//     scanf("%d", &size);
//     // 3,4,2,4,3,5
//     int arr[size];
//     // 1,1,2,2,4
//     createArr(arr, size);
//     printf("\n");
//     bool check[size];
//     for (int i = 0; i < size; i++)
//     {
//      check[i]=false;
//     }
// printf("Numbers present in the array are: ");
//     for (int i = 0; i < size; i++)
//     {
//        if (check[i]==false)
//        {
//         printf("%d ",arr[i]);
//         check[i]=true;
//        }
//        for (int j = 0; j < size; j++)
//        {
//         if (arr[i]==arr[j] && i != j )
//         {   
//             check[j]=true;
//         }
        
//        }
       
       
//     }
    
    
//     return 0;
// }