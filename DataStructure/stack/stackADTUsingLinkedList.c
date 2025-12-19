#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Stack
{
    struct Node *top;
    int count;
};

void createStack(struct Stack *stack)
{
    stack->top = NULL;
    stack->count = 0;
    return;
}
bool isEmpty(struct Stack *stack)
{
    if (stack->top == NULL)
    {
        return true;
    }
    return false;
}
bool isFull(struct Stack *stack)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL)
    {
        free(node);
        return true;
    }
    free(node);
    return false;
}
void push(struct Stack *stack, int data)
{
    if (isFull(stack))
    {
        printf("\nStack Overflow ->Allocation faliure : stack is now full.\n");
        return;
    }

    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    // printf("\nElement %d is pushed in the stack Succesfuly !\n", node->data);

    printf("\nElement %d is pushed in the stack Succesfuly !\n", stack->top->data);
    stack->count++;
    return;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("\nStack Underflow -> stack is now empty.\n");
        return -1;
    }

    int element = stack->top->data;
    printf("\nElement %d popped out from the stack.\n", element);
    struct Node *p = stack->top;
    stack->top = stack->top->next;
    free(p);
    stack->count--;
    return element;
}

int peek(struct Stack *stack, int position)
{
    // peek return element from the position starting from top to bottom.
    if ((stack->count - position) >= 0)
    {
        struct Node *p = stack->top;

        int i = stack->count - 1;
        while (i != (stack->count - position))
        {
            p = p->next;
            i--;
        }

        int element = p->data;
        printf("\nElement at %d position in the stack is %d\n", position, element);

        return element;
    }
    else
    {
        printf("\nInvalid -> element at position %d is not present ...\n", position);
        return -1;
    }
}
int stackTop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("\nStack Underflow -> stack is empty.\n");
        return -1;
    }
    int element = stack->top->data;
    printf("\nTopmost Element in the stack is : %d \n", element);
    return element;
}
int stackBottom(struct Stack *stack)
{
    if (isEmpty(stack))
    {
         printf("\nStack Underflow -> stack is empty.\n");
        return -1;
    }
    int i=stack->count-1;
    struct Node *ptr=stack->top;
    while (i !=0 )
    {
        ptr=ptr->next;
        i--;
    }
    
    int element = ptr->data;
    printf("\nBottommost Element in the stack is : %d \n", element);
    return element;
}
void stackTraversal(struct Node *ptr){
    printf("\nElement in the stack are: ");
     while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
    return;
}
int main()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    createStack(stack);
    push(stack, 15);
    push(stack, 16);
    push(stack, 17);
    push(stack, 18);
        push(stack, 19);
    push(stack, 20);
    pop(stack);
    pop(stack);
    // pop(stack);
    // pop(stack);
    // pop(stack);
    // pop(stack);
    // peek(stack, 1);
    // peek(stack, 2);
    // peek(stack, 3);
    // stackTop(stack);
    // stackBottom(stack);
    stackTraversal(stack->top);

    return 0;
}