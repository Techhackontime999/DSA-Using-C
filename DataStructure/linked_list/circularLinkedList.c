#include <stdio.h>
#include <stdlib.h>
// now we going to create circular linked list in which last node of liked list not points to NULL as normal linked list.
// in circular liked list last node is again points to the first list or head;

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

    // method-2
    // in this loop condition is checked after the printing data.
    // do
    // {
    //     printf("%d ", p->data);
    //     p = p->next;
    // } while (p != start);
    printf("\n");
    return;
}
struct Node *insertAfterNode(struct Node *start, struct Node *node, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = node->next;
    ptr->data = data;
    // below is work for both if node->next != start or node->next=start
    node->next = ptr;
    ptr->next = p;
    return start;
}
struct Node *insertAtIndex(struct Node *start, int data, int idx)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = start;
    struct Node *q = start->next;

    int i = 0;
    do
    {
        p = p->next;
        i++;
    } while (p->next != start);
    p = start;
    idx = idx % (i + 1);

    i = 0;
    if (idx != 0)
    {
        while (i != idx - 1)
        {
            p = p->next;
            q = q->next;
            i++;
        }
        p->next = ptr;
        ptr->next = q;

        return start;
    }
    else
    {
        ptr->next = p;
        p = ptr;
        q = p->next;
        while (q->next != start)
        {
            q = q->next;
        }
        q->next = p;

        return p;
    }
}
struct Node *deleteAtIndex(struct Node *start, int idx)
{
    struct Node *p = start;
    struct Node *q = start->next;

    int i = 0;
    do
    {
        p = p->next;
        i++;
    } while (p->next != start);

    idx = idx % (i + 1);

    if (idx != 0)
    {
        i = 0; // i is changed here
        p = start;
        while (i != idx - 1)
        {
            p = p->next;
            q = q->next;
            i++;
        }
        p->next = q->next;
        free(q);

        return start;
    }
    else
    {
        // here we not change i because i is at maximum index after it they reach to first
        q = start;
        p->next = q->next;
        start = p->next;
        free(q);
        return start;
    }
}
struct Node *deleteAfterNode(struct Node *start, struct Node *node)
{
    struct Node *p = node;
    struct Node *q = node->next;
    if (node->next != start)
    {
        p->next = q->next;
        free(q);
        return start;
    }
    else
    {
        // we need to update next starting node because printing is start from starting node.
        p->next = q->next;
        start = p->next;
        free(q);
        return start;
    }
}
struct Node *deleteNode(struct Node *node)
{
    // this function delete that node and return new node in place of that.
    // here we assume node is my starting node
    struct Node *p = node;
    struct Node *q = node->next;
    do
    {
        p = p->next;
        q = q->next;
    } while (p->next != node);
    p->next = q->next;
    node = p->next;
    free(q);
    return node;
}
int main()
{
    // without typedef
    struct Node *head, *second, *third;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 3;
    head->next = second;
    second->data = 4;
    second->next = third;
    third->data = 5;
    third->next = head;
    // insert at index function assumes passed start node is at 0 index.
    // head=insertAtIndex(head, 24, 1);
    // circularLinkedListTraversal(head);
    // second=insertAtIndex(second, 24, 0);
    // circularLinkedListTraversal(second);
    // third=insertAtIndex(third, 24, 1);
    // circularLinkedListTraversal(third);
    // head=insertAtIndex(head, 24, 1);
    // circularLinkedListTraversal(head);
    // head = insertAtIndex(head, 24, 0);
    // circularLinkedListTraversal(head);
    // head = insertAfterNode(head, third, 23);
    // circularLinkedListTraversal(head);
    // head = insertAfterNode(head, third, 23);
    // circularLinkedListTraversal(head);
    // second = insertAfterNode(second, third, 23);
    // circularLinkedListTraversal(second);
    //     third = insertAfterNode(third, third, 23);
    // circularLinkedListTraversal(third);
    // printf("Before deletion..\n");
    // circularLinkedListTraversal(head);
    // head = deleteAtIndex(head, 0);
    // printf("After deletion..\n");
    // circularLinkedListTraversal(head);
    // printf("Before deletion..\n");
    // circularLinkedListTraversal(second);
    // second = deleteAtIndex(second, 3);
    // printf("After deletion..\n");
    // circularLinkedListTraversal(second);
    //  printf("Before deletion..\n");
    // circularLinkedListTraversal(second);
    // second = deleteAtIndex(second, 0);
    // printf("After deletion..\n");
    // circularLinkedListTraversal(second);

    // head = deleteAfterNode(head, second);
    // circularLinkedListTraversal(head);
    //   head = deleteAfterNode(head, third);
    // circularLinkedListTraversal(head);
    // second = deleteAfterNode(second, second);
    // circularLinkedListTraversal(second);
    //  third = deleteAfterNode(third, second);
    // circularLinkedListTraversal(third);

    // printf("Before deletion..\n");
    // circularLinkedListTraversal(head);
    // head=deleteNode(head);
    // printf("After deletion..\n");
    // circularLinkedListTraversal(head);

    //  printf("Before deletion..\n");
    // circularLinkedListTraversal(second);
    // head=deleteNode(head);
    // printf("After deletion..\n");
    // circularLinkedListTraversal(second);

    //  printf("Before deletion..\n");
    // circularLinkedListTraversal(head);
    // second=deleteNode(second);
    // printf("After deletion..\n");
    // circularLinkedListTraversal(head);

    //  printf("Before deletion..\n");
    // circularLinkedListTraversal(head);
    // third=deleteNode(third);
    // printf("After deletion..\n");
    // circularLinkedListTraversal(head);

    return 0;
}