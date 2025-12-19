#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *postfixToInfix(char *postfix)
{
    char *infix = (char *)malloc((strlen(postfix) + 1) * sizeof(char));
    int i = 0;
    char *first;
    char *second;
    int fStart;
    int fEnd;
    int sStart;
    int sEnd;
    while (postfix[i] != 0)
    {
        if (isOperator(postfix[i]))
        {
            if (i == 0)
            {
                fStart = i - 2;
                fEnd = i - 2;
                sStart = i - 1;
                sEnd = i - 1;
            }
        }
        else
        {
            /* code */
        }
    }
}
int main()
{

    return 0;
}