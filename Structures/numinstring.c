#include <stdio.h>
#include <stdlib.h>
char convertintegertochar(int a)
{
    int askii[10];
    int k = 48;
    for (int i = 0; i < 10; i++)
    {
        askii[i] = k;
        k++;
    }

    return (char)askii[a];
}
int numOfDigits(int num)
{
    int count = 0;
    // num%10;//last digit
    while (num > 0)
    {
        num = num/10;
        count++;
    }

    return count;
}
char *numInChar(int num, int count)
{
    char *numchar = (char *)malloc((count + 1) * sizeof(char));
    for (int i = count-1; i >=0; i--)
    {
        int digit = num % 10;
        numchar[i] = convertintegertochar(digit);
        num = num - num % 10;
        num = num / 10;
    }
    numchar[count] = '\0';
    return numchar;
}
int main()
{
    int num = 903;
    char *numstr = numInChar(num, numOfDigits(num));
    // char *ptr = numstr;
    // while (*ptr != '\0')
    // {
    //     printf("%c", *ptr);
    //     ptr++;
    // }
    printf("%s",numstr);
    free(numstr);
    return 0;
}
