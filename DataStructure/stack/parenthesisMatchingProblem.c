#include <stdio.h>
#include <stdlib.h>
#include<string.h>
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
int push()
{
    if (isFull())
    {
        printf("\nStack Overflow -> Stack is full during Parenthesis check..\n");
        return 0;
    }
    stack->top++;
    stack->arr[stack->top] = '(';
    return 1;
}
int pop()
{
    if (isEmpty())
    {
        printf("Expression is Unbalanced.\n");
        return 0;
    }
    stack->top--;
    return 1;
}
void evaluate(char *str)
{
    int strSize = strlen(str) ;
    int i = 0;
    while (i < strSize)
    {
        if (str[i] == '(')
        {
            push();
        }
        if (str[i] == ')')
        {
            int check=pop();
            if (check==0)
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
    char *str="4-(6+3)(";
    int stackSize = strlen(str)+1;
    createStack(stackSize);
    // char str[]="4-(6+7(6/3-(7)-4()))";
    // char *str;
    // printf("Enter Exp: ");
    // scanf("%[^\n]s",str);//this not working here
    printf("Result of Expression below -\n");
    printf("\n");
    evaluate(str);
    return 0;
}
