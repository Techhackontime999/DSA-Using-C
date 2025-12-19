#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Stack
{
    int size;
    int top;
    char *arr;
} Stack;
Stack *stack;
void createStack(int size)
{
    stack = (Stack *)malloc(sizeof(Stack));
    stack->arr = (char *)malloc(size * sizeof(char));
    stack->size = size;
    stack->top = -1;
}
int isEmpty()
{
    if (stack->top == -1)
    {
        return 1;
    }
    return 0;
}
int isFull()
{
    if (stack->top == stack->size - 1)
    {
        return 1;
    }
    return 0;
}
int push(char ch)
{
    if (isFull())
    {
        printf("\nStack Overflow -> Stack is full during Parenthesis check..\n");
        return 0;
    }
    stack->top++;
    stack->arr[stack->top] = ch;
    return 1;
}
int pop(char ch)
{
    if (isEmpty() || ch != stack->arr[stack->top] )
    {
        printf("Expression is Unbalanced.\n");
        return 0;
    }
    if (ch == stack->arr[stack->top])
    {
        stack->top--;
        return 1;
    }
}
void evaluate(char *str)
{
    int strSize = strlen(str);
    int i = 0;
    while (i < strSize)
    {
        if (str[i] == '(')
        {
            push('(');
        }
        else if (str[i] == '{')
        {
            push('{');
        }
        else if (str[i] == '[')
        {
            push('[');
        }

        if (str[i] == ')')
        {
            int check = pop('(');
            if (check == 0)
            {
                return;
            }
        }
        else if (str[i] == '}')
        {
            int check = pop('{');
            if (check == 0)
            {
                return;
            }
        }
        else if (str[i] == ']')
        {
            int check = pop('[');
            if (check == 0)
            {
                return;
            }
        }
        i++;
    }
    if (stack->top == -1)
    {
        printf("Expression is balanced.\n");
    }
    else
    {
        printf("Expression is Unbalanced.\n");
    }

    return;
}
int main()
{
    char *str = "[{4-(6)+{3}-4}]";
    int stackSize = strlen(str) + 1;
    createStack(stackSize);
    // char str[]="4-(6+7(6/3-(7)-4()))";
    // char *str;
    // printf("Enter Exp: ");
    //below scanf not work because needs to allocate memory for str first then scan full line string
    // scanf("%[^\n]s",str);//this not working here
    printf("Result of Expression below -\n");
    printf("\n");
    evaluate(str);
    printf("%d",stack->top);
    return 0;
}
