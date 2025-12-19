#include<stdio.h>
// rotate the array by k where k is a positive integer
// 1,2,3,4,5
// k=0  1,2,3,4,5
// k=1  5,1,2,3,4
// k=2  4,5,1,2,3
// k=3  3,4,5,1,2
// k=4  2,3,4,5,1
// k=5  1,2,3,4,5
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
void rotate(int arr[],int k){
    // array if 1,2,3,4,5,6,7,8 and k=4
    // after k rotation array is 5,6,7,8,1,2,3,4
reverse(arr,0,5);//reverse the full array   here array get reverse    8,7,6,5,4,3,2,1
reverse(arr,0,k-1);//reverse the reversed array 0 to (k)rotation-1   here array get reverse of reverse means correct till k-1 from 0             5,6,7,8,4,3,2,1 
reverse(arr,k,5);//correct the other part of reverse from k to last    8,7,6,5,1,2,3,4
return;
}
int main(){
  
    int arr[]={1,2,3,4,5,6};
    int k;
    printf("enter number of rotation : ");
    scanf("%d",&k);
    k=k%6;
    printf("Before arr: ");
    for (int i = 0; i <= 5; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    rotate(arr,k);
       printf("After arr: ");
    for (int i = 0; i <= 5; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;

}