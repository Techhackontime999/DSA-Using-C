#include <stdio.h>
void reverse(int arr[], int si, int ei)
{
     int temp;
    for (int i = si, j = ei; i < j; i++,j--)
    {
        temp=arr[j];
        arr[j]=arr[i];
        arr[i]=temp;
        
    }
    return;
    
}
int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
   
    int si, ei;
    printf("enter si: ");
    scanf("%d", &si);
    printf("enter ei: ");
    scanf("%d", &ei);

    printf("Array Before: ");
    for (int i = 0; i < 6; i++)
    {
        /* code */
        printf("%d ", arr[i]);
    }
    reverse(arr, si, ei);
    printf("\n");
    printf("Array After: ");
    for (int i = 0; i < 6; i++)
    {
        /* code */
        printf("%d ", arr[i]);
    }
    return 0;
}