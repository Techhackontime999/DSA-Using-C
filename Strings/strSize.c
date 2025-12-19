#include <stdio.h>
int main(){
    char str[]="Amit is a good boy";
    int i=0;
    while (str[i] != '\0')
    {
       printf("%c",str[i]);
       i++;
    }
    printf("\nSize of str without null character is: %d ",i);
    printf("\nSize of str with null character is: %d ",i+1);

    return 0;
}