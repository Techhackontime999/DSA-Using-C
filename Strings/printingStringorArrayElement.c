#include<stdio.h>
//ways of printing particular elementn from Array or String.
int main(){
int arr[5]={1,2,3,4,5};
// printf("%p",&arr[0]);
int *ptr=&arr[0];
//now ptr carried address of arr[0] and *ptr print element at that address
printf("%d ",*ptr);
// for (int i = 0; i < 5; i++)
// {
    //arr[i] means go at index i in arr and Acess element from that index
    // printf("%d ",arr[i]);
    //i[arr] means go in array and acess from i index.
    // printf("%d ",i[arr]);
    //arr is passed in a function as a reference i.e address is passed of first element that is the Address of the array.
    //arr+i means address of array or first element + index(i) thats change then go to the next element .here we creating a pointer thats points arr address+index .i.e &Arr[0]+i at starting i=0
    // printf("%d ",*(arr+i));
    //here same i+arr is index+&arr[0]
    // printf("%d ",*(i+arr));

// }

    return 0;
}