#include<stdio.h>
#include<strings.h>
int main(){
//     char str[20];
//   printf("Enter your name: ");
//   //taking user input first word
//   scanf("%s",str);
//  printf("%s is your name. welcome babu.\n",str);

    // char str[20];
//   printf("Enter your name: ");
//   //taking user input first word
//   scanf("%[^\n]s",str);
//  printf("%s is your name. welcome babu.\n",str);


// int arr[]={1,2,3,4,5,6,'\0'};
// int i=0;
//here \0==0 so you can't write 0 in this array because if you write 0 then compiter understand its a null character when comparing with null character and stops printing after it.
// while (arr[i] != '\0')
// {
//     printf("%d ",arr[i]);
//     i++;
// }


// when writing this then gcc take the actual array size and not consider null character when not writing size and creating string in this way
// char ch[]={'a','b','c','d','e'};
// in below way size of this character array included with the null character
// char ch[]="abcde";
// char ch[6]={'a','b','c','d','e'};
char ch[]={'a','b','c','d','e','\0'};

// int i=0;
// while (ch[i] != '\0')
// {
//     printf("%c ",ch[i]);
//     i++;
// }
printf("%s",ch);

    return 0;
}