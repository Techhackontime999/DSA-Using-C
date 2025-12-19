#include <stdio.h>
int main()
{
    // char str[]="Amit Kumar";
    // int i=0;
    // while (str[i] != '\0')
    // {
    //     printf("%c",str[i]);
    //     i++;
    // }
    // char* ptr=str;//here we use charecter pointer because it consider 1 byte of address so next address should be to next 1 byte.
    // char *ptr="Amit Kumar"; //it store address of string i.e first charecter in the string.

    // modifying string froma pointer initialization.
    // char *ptr="Amit Kumar";
    // ptr[0]='M';//this modification not possible //it is readonly
    // *ptr[0]='M';//this modification not possible //it is readonly
    // ptr="suraj kumar";//this modification correct because now pointer points to new string.
    // while (*ptr != '\0')
    //     {
    //         printf("%c",*ptr);
    //         ptr++;
    //     }
    // after modification
    // char str[40];
    // str="Amit kumar sahu";
    // this type of declration not allowed .
    // printf("%s",str);
    // only allowed below declration
    // char str[40]="Amit Kumar Sahu";
    // printf("%s",str);
    // char str[] = "Amit kumar sahu";
    // char *ptr = str;
    // ptr="sohan";
    // ptr now points to a new strings but not change the existing string.
    // printf("%s",ptr);
    //  char *ptr ="Amit Kumar Sahu.";
    // char *x = ptr;
    // x="sohan";
    // printf("%s", ptr);
// char *ptr="Physics wallah";
// shallow copy
// shallow copy means actual change in other string when changing other one  
// char s2[]="physics wallah";
// char* s1=s2;
// s2[0]='M';
// printf("%s",s1);
//in upper example when we change individual charecter in s2 then s1 also get change.
// deep copy
//here ptr and s1 now points different different strings.
// char *s1=ptr;
// s1="college wallah";
// printf("%s",ptr);
// while (*ptr != '\0')
// {
//    printf("%c",*ptr);
//    ptr++;
// }
// below initialization can not modified all character in a string at a time like below but modify it character by character

// char str[]="Physics wallah";
// str="college wallah";//its give the error
// below intialization can modified all charecter in a sstring at a time but can not change individual character.
// char *ptr="physics wallah";
// ptr="college wallah";//its correct its change the original string
// ptr[0]='0';//this give error
// *ptr='0';//this also give error
// printf("%s",ptr);


// below example gives the error
// char str1[]="physics wallah";
// char str2[]=str1; // or str1[16]=str1; //here we need to assign each charecter one by one not at once
// printf("%s",str2);

// but in pointer i can do it 
char* str1="physics wallah";
char* str2=str1;
printf("%s",str2);
    return 0;
}

