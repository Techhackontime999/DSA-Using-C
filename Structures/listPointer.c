#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// this below program work as a list
// which print word from a comma separated string
// here we use dynamc memory allocation to return a local array address from a function because dynamic memory allocation can return address of array when declare inside a function because memory is reserved inside heap not stack .
// when i declare normal array inside a function it aquire space inside the stack not heap.
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
int listlen(char str[])
{
    int len = numOfCommas(str) + 1;
    return len;
}
void addIndexOfCommaInCommaArr(char str[], int *commaArr)
{
    int start = 0;
    int commaArrSize = numOfCommas(str);

    int strSize = strlen(str);
    int *ptr = commaArr;

    for (int i = 0; i < commaArrSize; i++)
    {
        for (int j = start; j < strSize; j++)
        {
            if (str[j] == ',')
            {
                *ptr = j;
                ptr++;
                start = j + 1;
                break;
            }
        }
    }
}

int indexBasedOnChoice(char str[], int listidx, char choice)
{

    int idx;
    int commaArrSize = numOfCommas(str);
    int commaArr[commaArrSize];
    addIndexOfCommaInCommaArr(str, commaArr);
    int strSize = strlen(str);

    if (choice == 'f')
    {
        if (listidx == 0)
        {
            idx = 0;
            return idx;
        }
        else if (listidx == commaArrSize)
        {
            idx = commaArr[listidx - 1] + 1;
            return idx;
        }
        else if (listidx > 0 && listidx < commaArrSize)
        {
            idx = commaArr[listidx - 1] + 1;
            return idx;
        }
    }
    if (choice == 'l')
    {
        if (listidx == 0)
        {
            idx = commaArr[0] - 1;
            return idx;
        }
        else if (listidx == commaArrSize)
        {
            idx = strSize - 1;
            return idx;
        }
        else if (listidx > 0 && listidx < commaArrSize)
        {
            idx = commaArr[listidx] - 1;
            return idx;
        }
        else
        {
            return -1; // clearly handle errors
        }
    }
}

char *getList(char str[], int idx)
{
    int commaArrSize = numOfCommas(str);
    int commaArr[commaArrSize];
    addIndexOfCommaInCommaArr(str, commaArr);

    // int commaArrSize = numOfCommas(str);
    int strSize = strlen(str);

    int i;
    int count = 0;

    if (idx == 0)
    {
        int count = 0;

        for (i = indexBasedOnChoice(str, idx, 'f'); i <= indexBasedOnChoice(str, idx, 'l'); i++)
        {
            count++;
            // printf("%c", str[i]);
        }
        // char wordstr[count];
        char *wordstr = (char *)malloc((count + 1) * sizeof(char));
        char *ptr = wordstr;
        if (wordstr == NULL)
            return NULL; // always check for allocation failure

        for (i = indexBasedOnChoice(str, idx, 'f'); i <= indexBasedOnChoice(str, idx, 'l'); i++)
        {

            *ptr = str[i];
            ptr++;

            // printf("%c", str[i]);
        }
        *ptr = '\0';

        // its return the address of the items from a string
        return wordstr;
        // printf("\n");
    }
    else if (idx == commaArrSize)
    {
        for (int i = indexBasedOnChoice(str, idx, 'f'); i <= indexBasedOnChoice(str, idx, 'l'); i++)
        {
            count++;
        }
        // char wordstr[count];
        char *wordstr = (char *)malloc((count + 1) * sizeof(char));
        char *ptr = wordstr;

        if (wordstr == NULL)
            return NULL; // always check for allocation failure

        for (int i = indexBasedOnChoice(str, idx, 'f'); i <= indexBasedOnChoice(str, idx, 'l'); i++)
        {

            *ptr = str[i];
            ptr++;
        }
        *ptr = '\0';
        return wordstr;
    }
    else if (idx > 0 && idx < commaArrSize)
    {
        int count = 0;
        for (i = indexBasedOnChoice(str, idx, 'f'); i <= indexBasedOnChoice(str, idx, 'l'); i++)
        {
            count++;
        }
        // char wordstr[count];
        char *wordstr = (char *)malloc((count + 1) * sizeof(char));
        char *ptr = wordstr;

        if (wordstr == NULL)
            return NULL; // always check for allocation failure
        for (i = indexBasedOnChoice(str, idx, 'f'); i <= indexBasedOnChoice(str, idx, 'l'); i++)
        {
            *ptr = str[i];
            ptr++;
        }
        *ptr = '\0';
        return wordstr;
    }
    else
    {
        printf("Error: -> Given List Index Out Of its Range. \n");
        return NULL;
    }
    // return;
}
char *addList(char str[], char element[], int listidx)
{
    if (listidx == listlen(str))
    {
        int elementSize = strlen(element) + 1;
        char elementArr[elementSize + 1];

        strcpy(elementArr, ",");

        strcat(elementArr, element);
        int strSize = strlen(str) + elementSize;
        char *strArr = (char *)malloc((strSize) * sizeof(char));
        strcpy(strArr, str);
        strcat(strArr, elementArr);
        strArr[strSize - 1] = '\0';
        free(str);
        return strArr;
    }
    else if (listidx < listlen(str) && listidx >= 0)
    {

        int elementSize = strlen(element) + 1;

        char elementArr[elementSize + 1];

        strcpy(elementArr, ",");
        elementArr[elementSize - 1] = elementArr[elementSize - 2];

        strcat(elementArr, element);

        int strSize = strlen(str) + elementSize;
        char *strArr = (char *)malloc(strSize * sizeof(char));
        int firstidx = indexBasedOnChoice(str, listidx, 'f');
        int lastidx = indexBasedOnChoice(str, listidx, 'l');
        int step = strlen(element);

        strcpy(strArr, str);

        char *ptr = strArr + (strSize - 1);

        for (int i = strSize - 1; i >= firstidx - 1; i--)
        {

            *(ptr + step + 1) = *ptr;

            ptr--;
        }

        ptr = &strArr[firstidx - 1];
        for (int i = 0; i <= step; i++)
        {
            *ptr = elementArr[i];
            ptr++;
        }
        // strArr[strSize - 1] = '\0';
        free(str);

        return strArr; /* code */
    }
    else
    {
        printf("Error: ->Given List Index is not valid.\n");
        return NULL;
    }
}

int main()
{
    // work this function both type of list declration
    char *str = strdup("Amit,Suraj,Prakash,son,mon,rakesh,mayank,mohan");
    // char str[] = "Amit,Suraj,Prakash,son,mon,rakesh,mayank,mohan";

    //             0     1      2     3   4    5
    printf("%d\n", listlen(str));
    // char str[] = "Amit,Suraj,Prakash,son,mon,rakesh,mayank,mohan";
    // //             0     1      2     3   4    5
    // now we need to create a list pointer that points first item of the list initially
    // and we can also able to print list items with the help of list pointer

    // char *ptr=list(str,0);
    char *ptr;
    // while (*ptr != '\0')
    // {
    //     printf("%c", *ptr);
    //     ptr++;
    // }
    // printf("\n");

    // printf("%s\n", btr);

    // printing all element at once
    for (int i = 0; i < listlen(str); i++)
    {
        // get element from list
        ptr = getList(str, i);
        printf("%s\n", ptr);
        free(ptr);
    }
    printf("\n");
    // free(ptr);
    // from below print we now know when we pass array or array pointer to a function it may receive it as pointer or array
    // because both pass as reference i.e address is passed
    // printf("%d",numOfCommas(str));

    // add element in to the list
    // addList function return a newList after adding element
    // below updation is not possible
    // char str[]="Amit,kumar";
    // str[]="suraj kumar";
    // it is possible
    //  char *str="Amit,kumar";
    // str="suraj kumar";
    // so when user give list str to me either array or array pointer then always except or take inside function as a pointer and after update return also a pointer .
    //  ptr=addList(str,idx,"element")
    // if you want to only add element in list then you give any type of list declration either in array or Array pointer
    // if you want to add element and also print after updation then prefer to take string or array pointer rather than array and store returned list in that pointer
    // below add and update same string or store in other pointer variable
    // str = addList(str, "element01", 1);
    // printf("%d\n", listlen(str));

    // for (int i = 0; i < listlen(str); i++)
    // {
    //     // get element from list
    //     ptr = getList(str, i);
    //     printf("%s\n", ptr);
    //     free(ptr);
    // }
    // printf("\n");
    // free(str);

    //   str = addList(str, "element02", 8);
    // printf("%d\n", listlen(str));

    // for (int i = 0; i < listlen(str); i++)
    // {
    //     // get element from list
    //     ptr = getList(str, i);
    //     printf("%s\n", ptr);
    //     free(ptr);
    // }
    // printf("\n");
    // free(str);

    str = addList(str, "element03", 3);
    printf("%d\n", listlen(str));

    // for (int i = 0; i < listlen(str); i++)
    // {
    //     // get element from list
    //     ptr = getList(str, i);
    //     printf("%s\n", ptr);
    //     free(ptr);
    // }
    // printf("\n");
    // free(str);

    // below only add element and also able to print updated but in next line not same
    //  addList(str,"element",6);
    return 0;
}