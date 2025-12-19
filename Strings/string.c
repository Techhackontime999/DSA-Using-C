#include <stdio.h>
int main()
{
    // below is the wrong initialization because size of string in below declaration is no of elements + 1 for null character included.
    // char str[5]="hello";
    // printf("%s",str);
    // declration in the right way is without writing size of str in thisintialization
    //  char str[]="hello";
    // printf("%s",str);
    // modifying individual character start
    //char str[] = "Physics Wallah";
    // str[0]='M';
    // printing Mhysics Wallah
    //str[1] = 97; //it is same as str[1]='a'
    // printing Paysics Wallah because 97 typecasting automatically to character which is a.
    // printf("%s", str);
    // modifying individual character end
    return 0;
}