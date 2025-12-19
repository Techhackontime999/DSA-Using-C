#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Stack
{
    int size;
    int top;
    void **arr;
} Stack;

Stack *stack;

void createStack(Stack *stack, int size)
{
    stack->size = size;
    stack->top = -1;
    stack->arr = (void *)malloc(size * sizeof(void));
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
void push(void (*data)())
{
    if (isFull())
    {
        printf("\nStack Overflow -> Stack is Full..\n");
        return;
    }

    stack->top++;
    stack->arr[stack->top] = data;

    return;
}
void pop()
{
    if (isEmpty() == false)
    {

        void (*a)() = stack->arr[stack->top];
        a();
        stack->top--;

        return;
    }
    printf("\nStack Underflow -> Stack is now Empty..\n");
    return;
}
void peek(int position)
{
    // peek return element from the position starting from top to bottom.
    if ((stack->top - position + 1) < stack->size && (stack->top - position + 1) >= 0)
    {
        void (*p)() = stack->arr[stack->top - position + 1];
        p();
        return;
    }
    else
    {
        printf("\nInvalid -> element at position %d is not present ...\n", position);
        return;
    }
}
void execfun(void (*data)())
{
    push(data);
    pop();
}

void fun5()
{
    printf("Hello dear amit 2222.\n");

    return;
}
void fun4()
{
    printf("Hello dear amit 1.\n");

    return;
}
void fun3()
{
    printf("we are fun3.\n");

    return;
}
void fun2()
{
    push(fun3);
    pop();
    printf("we are fun2.\n");

    return;
}
void fun1()
{
    push(fun2);
    pop();
    printf("we are fun1.\n");
    return;
}

int main()
{
    // we can also pass directly pass a pointer which store the address of structure stack.
    stack = (struct Stack *)malloc(sizeof(struct Stack));
    createStack(stack, 3);
    // push(fun1);//push put function inside the stack
    // pop();//pop execute function present in the  stack
    // push(fun4);
    // push(fun5);
    peek(1);
    execfun(fun1);
    execfun(fun4);//execfun function execute a particular function
    execfun(fun2);
    return 0;
}