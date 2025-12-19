#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void circularLinkedListTraversal(struct Node *start)
{
    struct Node *p = start;
    // method-1
    while (p->next != start)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("%d ", p->data);
    printf("\n");
}
int main()
{
    // list with empty element

    // empty singly linked list
    //  struct Node *emptysinglylist=(struct Node *)malloc(sizeof(struct Node));
    //  emptysinglylist->next=NULL;
    // circular empty linked list
    //  struct Node *head=(struct Node *)malloc(sizeof(struct Node));
    //  head->next=head;
    // in empty circular list it next pointer points to own node.

    // list with single element
    // singly linked list with one element.
    // struct Node *head=(struct Node *)malloc(sizeof(struct Node));
    // head->data=4;
    // head->next=NULL;
    // circular linked list with one element.
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 4;
    head->next = head;
    circularLinkedListTraversal(head);
    

    return 0;
}