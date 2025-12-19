#include <stdio.h>
#include <stdlib.h>
int *fun2dArr()
{
    // int arr[] = {1, 2, 3, 4, 5};
    // we use here dynamic memory allocation to return local variable arr from an function
    int *arr = (int *)malloc(5 * sizeof(int));
    int i = 0;
    int *ptr = arr;
    while (i < 5)
    {
        *ptr = i + 1;
        ptr++;
        i++;
    }
    return arr;
}
int *fun1dArr()
{
    // int arr[] = {1, 2, 3, 4, 5};
    // we use here dynamic memory allocation to return local variable arr from an function
    int *arr = (int *)malloc(5 * sizeof(int));
    int i = 0;
    int *ptr = arr;
    while (i < 5)
    {
        *ptr = i + 1;
        ptr++;
        i++;
//when i do ptr++ then it automaticaly understand to go to the next element .it automatically understand element of which type and do ptr+=4 for integer and ptr+=1 for char etc        i++;
    }
    return arr;
}
int main()
{
    int *ptr = fun1dArr();
    printf("%d ", *ptr);
    ptr++;
    printf("%d ", *ptr);
    ptr++;
    printf("%d ", *ptr);
    ptr++;
       printf("%d ", *ptr);
    ptr++;
       printf("%d ", *ptr);
    ptr++;
    
    return 0;
}