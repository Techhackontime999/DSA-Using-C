#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main()
{
    // copy one string to anothr string

    // char str[] = "Amit kumar";
    // // char str1[]={};
    // char str1[11];
    // strcpy(str1,str);
    // // printf("%s",str1);
    // int i=0;
    // while (str[i]!='\0')
    // {
    //     printf("%c",str[i]);
    //     i++;
    // }
    // printf("\n%d",i);

    // printing the length of the string

    // char *s="amit babu";
    // int length=strlen(s);
    // int length=strlen(str);
    // printf("%d", length);

    // concat two strings in to one using strcat
    // this function concate second string in to first string and store it in the first string after concat
    //   char str[17]="Amit kumar";
    // //   char str[]="Amit kumar";
    //   char str2[]=" Sahu. ";
    //   strcat(str,str2);//it concate str2 in to str
    //   printf("%s",str);

    // compare two strings using strcmp
    // this function compare the two string and return boolean value like true for different and false for same
    // char str1[] = "Amit";
    // char str2[] = "Amit";
    // bool result = strcmp(str1, str2);
    // if (result)
    // {
    //     printf("both are not same.");
    // }
    // else
    // {
    //     printf("both are same.");
    // }

    //
    // strncpy
    char str1[] = "Amit";
    char str2[] = "Amit";
    int len=strlen(str1);
    strncpy(str1,str2,len);

    return 0;
}