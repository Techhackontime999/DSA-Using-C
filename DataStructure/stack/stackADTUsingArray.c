#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Stack
{
    int size;
    int top;
    int *arr;
} Stack;
void createStack(Stack *stack, int size)
{
    stack->size = size;
    stack->top = -1;
    stack->arr = (int *)malloc(size * sizeof(int));
}
bool isEmpty(Stack *stack)
{
    if (stack->top == -1)
    {
        return true;
    }

    return false;
}
bool isFull(Stack *stack)
{
    if (stack->top == stack->size - 1)
    {
        return true;
    }

    return false;
}
void push(Stack *stack, int data)
{
    if (isFull(stack))
    {
        printf("\nStack Overflow -> Stack is Full..\n");
        
    }

    else if (isEmpty(stack) == false && isFull(stack) == false)
    {
        stack->top++;
        stack->arr[stack->top] = data;
        printf("\nElement %d pushed in the stack Successfully !\n", data);
    }
    else if (isEmpty(stack))
    {
        stack->top++;
        stack->arr[stack->top] = data;
        printf("\nElement %d pushed in the stack. Successfully !\n", data);
    }

    return;
}
int pop(Stack *stack)
{
    if (isEmpty(stack) == false)
    {
        int element = stack->arr[stack->top];
        stack->top--;
        printf("\nElement %d  is popped from the stack successfully !\n", element);

        return element;
    }
     printf("\nStack Underflow -> Stack is now Empty..\n");
    return -1;
}
int peek(Stack *stack, int position)
{
    // peek return element from the position starting from top to bottom.
    if ((stack->top - position + 1) < stack->size && (stack->top - position + 1) >= 0)
    {
        int element = stack->arr[stack->top - position + 1];
        printf("\nElement at %d position in the stack is %d\n", position, element);

        return element;
    }
    else
    {
        printf("\nInvalid -> element at position %d is not present ...\n", position);
        return -1;
    }
}
int stackTop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("\nStack is Empty.\n");
        return -1;
    }
    int element = stack->arr[stack->top];
    printf("\nTopmost Element in the stack is : %d \n", element);
    return element;
}
int stackBottom(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("\nStack is Empty.\n");
        return -1;
    }
    int element = stack->arr[0];
    printf("\nBottommost Element in the stack is : %d \n", element);
    return element;
}
int main()
{
    // Stack stack;
    // createStack(&stack, 3);
    // push(&stack,15);
    // push(&stack,12);
    // push(&stack,13);
    // push(&stack,14);

    // push(&stack,14);
    // pop(&stack);
    // pop(&stack);
    // pop(&stack);
    // pop(&stack);
    // peek(&stack,1);
    // peek(&stack,2);
    // peek(&stack,3);
    // peek(&stack,4);
    // peek(&stack,5);

    //    stackTop(&stack);
    //    stackBottom(&stack);

    // we can also pass directly pass a pointer which store the address of structure stack.
    Stack *stack;
    createStack(stack, 4);
    push(stack, 15);
    push(stack, 12);
    push(stack, 16);
    push(stack, 17);

    pop(stack);
    pop(stack);
  pop(stack);
    pop(stack);
    pop(stack);

    // peek(stack, 1);
    // peek(stack, 2);

    // stackTop(stack);
    // stackBottom(stack);
    return 0;
}