#include <string.h>
#include <stdio.h>
// this below program work as a list 
//which print word from a comma separated string
int numOfCommas(char str[])
{
    int i = 0;
    int number = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ',')
        {
            number++;
        }
        i++;
    }

    return number;
}
void addIndexOfCommaInCommaArr(char str[], int commaArr[])
{
    int start = 0;
    int commaArrSize = numOfCommas(str);
    int strSize = strlen(str);

    for (int i = 0; i < commaArrSize; i++)
    {
        for (int j = start; j < strSize; j++)
        {
            if (str[j] == ',')
            {
                commaArr[i] = j;
                start = j + 1;
                break;
            }
        }
    }
}

void list(char str[], int commaArr[], int idx)
{
    int commaArrSize = numOfCommas(str);
    int strSize = strlen(str);

    int i;
    if (idx == 0)
    {
        for (i = 0; i < commaArr[0]; i++)
        {
            printf("%c", str[i]);
        }
        printf("\n");
    }
    else if (idx == commaArrSize)
    {
        for (int i = commaArr[idx - 1] + 1; i < strSize; i++)
        {
            printf("%c", str[i]);
        }
        printf("\n");
    }
    else if (idx > 0 && idx < commaArrSize)
    {
        for (i = commaArr[idx - 1] + 1; i < commaArr[idx]; i++)
        {
            printf("%c", str[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Error: -> Given List Index Out Of its Range. \n");
    }

    return;
}
int main()
{
    char str[] = "Amit,Suraj,Prakash,son,mon,rakesh";
    int strSize = strlen(str);
    int commaArrSize = numOfCommas(str);
    int commaArr[commaArrSize];
    addIndexOfCommaInCommaArr(str, commaArr);
    //printing the word from a list of comma separeted string
    list(str, commaArr, 5);
    list(str, commaArr, 5);
    list(str, commaArr, 5);
    list(str, commaArr, 5);

// below line print element of commaArr
    // for (int i = 0; i < commaArrSize; i++)
    // {
    //     printf("%d ", commaArr[i]);
    // }

    return 0;
}