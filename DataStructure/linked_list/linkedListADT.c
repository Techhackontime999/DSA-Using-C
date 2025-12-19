#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void linkedListTraversal(struct Node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return;
}
struct Node *insertAtBeginning(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}
struct Node *insertAtIndex(struct Node *head, int data, int idx)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *idxptr = head;

    int i = 0;
    if (idx != 0)
    {
        while (i != idx - 1)
        {
            idxptr = idxptr->next;
            i++;
        }

        ptr->next = idxptr->next;
        idxptr->next = ptr;
        return head;
    }
    else
    {
        ptr->next = idxptr;
        idxptr = ptr;
        return idxptr;
    }
    // while (idxptr != NULL)
    // {

    //     if (idx != 0)
    //     {
    //         if (i == idx - 1)
    //         {
    //             ptr->next = idxptr->next;
    //             idxptr->next = ptr;
    //             return head;
    //         }
    //     }
    //     else
    //     {
    //         ptr->next = idxptr;
    //         idxptr = ptr;
    //         return idxptr;
    //     }

    //     idxptr = idxptr->next;
    //     i++;
    // }
}
struct Node *insertAtEnd(struct Node *head, int data)
{
    // here vno need to return head
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->data = data;

    ptr->next = NULL;
    return head;
}

void insertAfterNode(struct Node *node, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = node->next;
    node->next = ptr;
    return;
}

struct Node *deleteAtBeginning(struct Node *head)
{
    struct Node *ptr;
    ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct Node *deleteAtIndex(struct Node *head, int idx)
{

    struct Node *p = head;
    struct Node *q = head->next;
    int i = 0;
    if (idx != 0)
    {
        while (i != idx - 1)
        {
            p = p->next;
            q = q->next;
            i++;
        }
        p->next = q->next;
        free(q);
    }
    else
    {
        head=q;
        free(p);
        return head;
    }
    

    return head;
}
// struct Node *deleteAtIndex(struct Node *head, int idx)
// {
//     struct Node *idxptr = head;
//     struct Node *track;

//     int i = 0;

//     while (idxptr != NULL)
//     {
//         if (idx != 0)
//         {
//             if (i == idx - 1)
//             {
//                 track = idxptr->next;
//                 idxptr->next = track->next;
//                 free(track);
//                 return head;
//             }
//         }
//         else
//         {
//             track = head;
//             head = head->next;
//             free(track);
//             return head;
//         }

//         idxptr = idxptr->next;
//         i++;
//     }
// }
struct Node *deleteAtEnd(struct Node *head)
{

    struct Node *p = head;
    struct Node *track;
    while (p->next != NULL)
    {
        track = p;
        p = p->next;
    }
    free(p);
    track->next = NULL;
    return head;
}

void deleteAfterNode(struct Node *node)
{
    struct Node *ptr;
    ptr = node->next;
    node->next = ptr->next;
    free(ptr);
    return;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 2;
    head->next = second;
    second->data = 3;
    second->next = third;
    third->data = 4;
    third->next = fourth;
    fourth->data = 5;
    fourth->next = NULL;
    // head = insertAtBeginning(head, 6);
    // head = insertAtBeginning(head, 7);
    // head = insertAtBeginning(head, 9);
    // // linkedListTraversal(head);

    // head = insertAtEnd(head, 90);
    // head = insertAtEnd(head, 900);

    // insertAfterNode(second,400);
    // insertAfterNode(head,400);

    // head = insertAtIndex(head, 14, 4);
    // head = insertAtIndex(head, 14, 0);

    // head=deleteAtBeginning(head);
    // head=deleteAtBeginning(head);
    // head = deleteAtEnd(head);
    // head = deleteAtEnd(head);
    // head = deleteAtEnd(head);
    // deleteAfterNode(third);
    // deleteAfterNode(head);
    // deleteAfterNode(second);
    // head = deleteAtIndex(head, 0);
    // head = deleteAtIndex(head, 0);

    // head = deleteAtIndex(head, 2);
    // head = deleteAtIndex(head, 0);

    linkedListTraversal(head);

    return 0;
}