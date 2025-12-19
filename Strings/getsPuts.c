#include <stdio.h>
int main()
{
    //gets never stop the user when size of string is less than input string and can't give the error.
    // char str[5];
    // printf("Enter your strings: ");
    // puts("Enter your strings: ");//puts add a new line by default

    // gets(str);
    // printf("String is: ");
    // puts("String is: ");//puts add a new line by default
    // puts(str);

     //scanf input in below form also never stop the user when size of string is less than input string and can't give the error.
    // char str[5];
    //this below declaration help to initialize or declare a empty string string without intialization or size consideration during creation.
    char str[]={};

    printf("Enter your string: ");
    scanf("%[^\n]s",str);
    printf("String is: %s",str);
    //below also but print only one word
    //so must use error handling or use input as a charecter
    // printf("Enter your string: ");
    // scanf("%s",str);
    // printf("String is: %s",str);

    // input string character by charecter and below takes input only equal to size of string
    // printf("Enter your string: ");
    // for (int i = 0; i < 5; i++)
    // {
    //     scanf("%c",&str[i]);
    // }

    // printf("Your string is: ");
    //   for (int i = 0; i < 5; i++)
    // {
    //     printf("%c",str[i]);
    // }
    return 0;
}