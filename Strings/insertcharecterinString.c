#include <stdio.h>
#include <string.h>
int main()
{
    char str[50];
    //   char *str;//best way of declaring string without size

    printf("Enter string: ");
    scanf("%[^\n]s", str);
    printf("Before insertion............................\n");
    printf("String is: %s\n", str);
    int len = strlen(str);
    printf("Size of string is: %d\n", len);
    // insertion start
    char ch='a' ;
    int idx=1;
    // printf("Enter character and index : ");
    // scanf("%c %d", &ch, &idx);
    int k = len ;

    while (k >= idx)
    {
        str[k + 1] = str[k];
        k--;
    }
    str[idx]=ch;

    // insertion end
    printf("\nAfter insertion of character............................\n");
    printf("String is: %s\n", str);
     len = strlen(str);
    printf("Size of string is: %d\n", len);

    return 0;
}