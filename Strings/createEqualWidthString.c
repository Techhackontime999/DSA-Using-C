// in this program we need to create string with equal width i.e adjust string in the between by using efficient use of spaces
#include <stdio.h>
#include <string.h>
int betidx(char str[], int size)
{
    int idx;
    int len = size;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ')
        {
            idx = i;
            return idx;
            break;
        }
    }
}
void insertSpaceAtIdx(char str[], int size)
{
    int len = size;
    for (int i = len; i > betidx(str, len) + 1; i--)
    {
        str[i] = str[i - 1];
    }
    str[betidx(str, len) + 1] = ' ';

    return;
}
void addHalfSpaceAtBothEnd(char str[], int size, int halfspace)
{
    int len = size;
    for (int i = len; i >= 0; i--)
    {
        str[i + halfspace] = str[i];
    }
    for (int i = 0; i < halfspace; i++)
    {
        str[i] = ' ';
    }

    return;
}
void inBetweenString(char str[], int size, int strsize)
{
    // str[strsize - 1] = str[len]; // first shift null character at end
    int len = size;
    int spaceempty = strsize - len - 1;
    int halfspace = spaceempty / 2;
    if (spaceempty % 2 == 0)
    {
        addHalfSpaceAtBothEnd(str, len, halfspace);
        // this below line add spaces at end
        for (int i = strsize - 2; i >= strsize - 1 - halfspace; i--)
        {
            str[i] = ' ';
        }
    }
    else
    {
        insertSpaceAtIdx(str, len);
        addHalfSpaceAtBothEnd(str, len, halfspace);
        // this below line add spaces at end
        for (int i = strsize - 2; i >= strsize - 1 - halfspace; i--)
        {
            str[i] = ' ';
        }
    }
    return;
}
int main()
{
    char str[21] = "Amiti kumar";
    printf("Before string: %s\n", str);

    int strsize = 21;
    int len = strlen(str); // store this len for further reference
    printf("string length: %d\n", len);

    inBetweenString(str, len, strsize);
    printf("After string: %s\n", str);
    len = strlen(str);
    printf("string length: %d\n", len);

    return 0;
}