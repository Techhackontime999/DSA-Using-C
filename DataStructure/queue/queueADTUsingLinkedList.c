// in this type of implementation of queue both enqueue and dequeue is done in o(1) time complexity when using two pointer called back & fourth or front or rare.
// when using only one pointer rare or back pointer then enqueue operation done in o(n) time complexity.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
typedef struct Queue
{
    int count;
    Node *front;
    Node *rare;
} Queue;

Queue *queue;
void createQueue()
{
    queue = (Queue *)malloc(sizeof(Queue));
    queue->count = 0;
    queue->front = queue->rare = NULL;
}
bool isEmpty()
{
    if (queue->front == NULL)
    {
        return true;
    }
    return false;
}
bool isFull()
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        return true;
    }
    return false;
}
void enqueue(int data)
{
    if (isFull())
    {
        printf("\nQueue Overflow -> queue is full.\n");
        return;
    }
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    printf("\nEnqueued element is: %d\n", data);
    queue->count++;
    if (isEmpty())
    {
        queue->rare = node;
        queue->front = node;
    }
    else
    {
        queue->rare->next = node;
        queue->rare = queue->rare->next;
    }
    return;
}
int dequeue()
{
    if (isEmpty())
    {
        printf("\nQueue Underflow -> queue is empty.\n");

        return -1;
    }
    Node *p = queue->front;
    printf("\nDequeued element is: %d\n", p->data);
    int data = p->data;
    queue->count--;
    queue->front = queue->front->next;
    free(p);
    return data;
}
void printQueue()
{
    if (isEmpty())
    {
        return;
    }
    printf("\nElements in the queue are: ");
    Node *p = queue->front;
    while (p != NULL)
    {
        printf(" %d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main()
{
    createQueue();
    enqueue(15);
    enqueue(16);
    enqueue(17);
    enqueue(18);
    printQueue();
    dequeue();
    dequeue();

    dequeue();
    printQueue();

    dequeue();
    dequeue();
    enqueue(77);
    dequeue();
printQueue();
    // printf("%d\n", queue->count);
    return 0;
}