#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
// method-3
// now we going to implement doublyTraversal with the help of function pointer.
// function pointer store name of the function which he points
// funtion pointer points a fuction and store function address which he start from executing line by line instruction.
// formal argument is the argument given with the function declration and actual argument is the argument passed during function call.
// formate:  return_type (*variable_name)(formal arguments of the pointed function)
// store address in the function pointer using below:
// 1.direct in one line using    return_type (*variable_name)(formal arguments of the pointed function) = funtion_name
// 2.declare first then assign.
// declaration: return_type (*variable_name)(formal arguments of the pointed function);
// asign: variable_name = funtion_name
int decide(struct Node *ptr)
{
    if (ptr->prev == NULL)
    {
        return 1;
    }
    else if (ptr->next == NULL)
    {
        return -1;
    }
    else if(ptr->next == NULL && ptr->prev == NULL)
    {
        return 1;
    }
}

void doublyTraversalByFunPointer(struct Node *ptr, int (*p)(struct Node *))
{

    if (p(ptr) == 1)
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);

            ptr = ptr->next;
        }
    }
    else if (p(ptr) == -1)
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);

            ptr = ptr->prev;
        }
    }

    printf("\n");
    return;
}

// method-2
//  now we implement a doubly linked list traversal function that work for both ascending and descending traversal.
//  logic is here if ptr->prev=NULL so traversel in increasing order and if ptr->next=NULL so traversal in decreasing order.

void doublyTraversal(struct Node *ptr)
{

    // below also handle cases when both prev and next points to NULL
    if (ptr->prev == NULL)
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
     if (ptr->next == NULL)
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->prev;
        }
    }
    printf("\n");
    return;
}
// method-1
//  below implementation of traversal of duubly linked list for both asceding and decending . seprate function for both.
void asscendingTraversal(struct Node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return;
}
void descendingTraversal(struct Node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
    return;
}
int main()
{
    struct Node *head, *second, *third;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // also handle cases if prev and next both are null i.e  doubly linked list with one element.
    //    head->data = 3;
    //  head->next = NULL;
    //  head->prev = NULL;

    // head->data = 3;
    // head->next = second;
    // head->prev = NULL;
    // second->data = 4;
    // second->next = third;
    // second->prev = head;
    // third->data = 5;
    // third->next = NULL;
    // third->prev = second;
    // method-1
    //  asscendingTraversal(head);
    //  descendingTraversal(third);
    // method-2
    //  for asscending order
    //  doublyTraversal(head);
    //  for descending order
    //  doublyTraversal(third);
    // method-3
    // doublyTraversalByFunPointer(head, decide);
    // doublyTraversalByFunPointer(third, decide);

    return 0;
}