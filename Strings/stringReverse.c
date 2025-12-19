#include<stdio.h>
int main(){
    char str[50];
    puts("Enter your string: ");
    gets(str);
    puts("String is: ");
    puts(str);
    int strlength=0;
    while (str[strlength] != '\0')
    {
       strlength++;
    }
    printf("Length of string: %d\n",strlength);
for (int i = 0,j=strlength-1; i < j; i++,j--)
{
   char temp;
   temp=str[i];
   str[i]=str[j];
   str[j]=temp;
}
    printf("Reverse of string: %s\n",str);



    return 0;
}