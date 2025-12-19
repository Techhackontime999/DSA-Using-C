#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct Stack
{
    int top;
    int size;
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
bool isEmpty()
{
    if (stack->top == -1)
    {
        return true;
    }
    return false;
}
bool isFull()
{
    if (stack->top == stack->size - 1)
    {
        return true;
    }
    return false;
}
bool isOperator(char ch)
{
    if (ch == '/' || ch == '*' || ch == '+' || ch == '-' || ch == '%')
    {
        return true;
    }
    return false;
}
int precedence(char ch)
{
    if (ch == '%')
    {
        return 3;
    }
    else if (ch == '/' || ch == '*')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    return -1;
}
void push(char ch)
{
    if (isFull())
    {
        return;
    }
    stack->top++;

    stack->arr[stack->top] = ch;
    return;
}
char pop()
{
    if (isEmpty())
    {
        return '\0';
    }
    char ch = stack->arr[stack->top];
    stack->top--;
    return ch;
}
char *infixToPostfix(char *infix)
{
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {

        if (isOperator(infix[i]))
        {
            if (isEmpty())
            {
                push(infix[i]);
                i++;

            }
            else
            {
                if (precedence(stack->arr[stack->top]) < precedence(infix[i]))
                {

                    push(infix[i]);
                    i++;
                }
                else
                {


                    // while (precedence(stack->arr[stack->top]) < precedence(infix[i]))
                    // {
                    //not need to use again while because here i is not we update only j update then at next time i again check if precedence of stacktop < precedence of infix[i] then push infix[i]
                        postfix[j] = pop();
                        j++;
                    // }
                    // push(infix[i]);
                    // i++;
                }
            }
        }
    
    else
    {
        postfix[j] = infix[i];
        j++;
        i++;
    }
}
while (isEmpty() == false)
{
    postfix[j] = pop();
    j++;
}
postfix[j] = '\0';

return postfix;
}
int main()
{
    char *infix = "3+9*7/4-6*2/1";
    int stackSize = strlen(infix);
    createStack(stackSize);
    char *postfix = infixToPostfix(infix);
    printf("%s\n", postfix);
    return 0;
}