// in implementation of circular queue using array we use a linear array and consupe spaces in circular manner for avoiding loss of spaces.
// but in circular queue using linked list we use a actual circular linked list and perform enqueue and dequeue operation .
//int this circular queue when i enqueue th element then circular queue increament by 1 circularly.
//int this circular queue when i dequeue th element then circular queue decreament by 1 circularly.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Queue
{
    struct Node *front;
    struct Node *rear;
    int count;
};
struct Queue *queue;

void createCircularQueue()
{
    queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    queue->count=0;
}

bool isEmpty()
{
    if (queue->front == NULL || queue->count==0)
    {
        return true;
    }
    return false;
}
bool isFull()
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
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
        printf("\nQueue Overflow -> Queue is full .\n");
        return;
    }
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    printf("\nEnqueued element : %d\n", data);
    queue->count++;
    if (isEmpty())
    {
        queue->front = queue->rear = node;
    }
    else
    {
        node->next = queue->front;
        queue->rear->next = node;
        queue->rear = queue->rear->next;
    }
    return;
}
int dequeue()
{
    if (isEmpty())
    {
        printf("\nQueue Underflow -> Queue is now empty .\n");
        return -1;
    }
    struct Node *p=queue->front;
     printf("\nDequeued element : %d\n", p->data);
    int data = p->data;
    queue->front=queue->front->next;
    queue->rear->next=queue->front;
    queue->count--;
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
    struct Node *p = queue->front;
    do
    {
        printf(" %d ",p->data);
        p=p->next;
    }while(p != queue->front);

    printf("\n");
}
int main()
{
    createCircularQueue();

    for (int i = 0; i < 100; i++)
    {
           enqueue(i+1);

    }
    for (int i = 0; i < 50; i++)
    {
    dequeue();
       
    }
    
    dequeue();
    dequeue();
    // dequeue();
    // dequeue();

    
printQueue();


    
    return 0;
}