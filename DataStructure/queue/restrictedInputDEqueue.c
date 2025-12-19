//int double ended queue called DEqueue we not folllow fifo . but we can use it as fifo. when only insertion from front and deletion from rear. then it follow fifo 
//when only insertion from rear and deletion from front then it also follow fifo
//i.e this type of queue implementation we use when we require the access of both end but follow fifo .


//restricted input DEqueue is the variation of double ended queue in which we avoid insertion from the front end.
//i.e insertion from front not allowed in restrictd input DEqueue.but we can use both end for deletion.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;
typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

Queue *queue;
void createQueue()
{
    queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
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
void rearEnqueue(int data)
{
    if (isFull())
    {
        printf("\nQueue Overflow -> queue is full.\n");
        return;
    }
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    printf("\nEnqueued element from rear is: %d\n", data);
    if (isEmpty())
    {

        queue->rear = node;
        queue->front = node;
    }
    else
    {
        queue->rear->next = node;
        node->prev = queue->rear;
        queue->rear = queue->rear->next;
    }
    return;
}

int rearDequeue()
{
    if (isEmpty())
    {
        printf("\nQueue Underflow -> queue is empty.\n");

        return -1;
    }
    Node *p = queue->rear;
    printf("\nDequeued element from rear is: %d\n", p->data);
    int data = p->data;
    queue->rear = queue->rear->prev;
    queue->rear->next=NULL;
    free(p);
    return data;
}
int frontDequeue()
{
    if (isEmpty())
    {
        printf("\nQueue Underflow -> queue is empty.\n");

        return -1;
    }
    Node *p = queue->front;
    printf("\nDequeued element from front is: %d\n", p->data);
    int data = p->data;
    queue->front = queue->front->next;
    queue->front->prev=NULL;
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
    rearEnqueue(18);
    rearEnqueue(19);
     rearEnqueue(20);
    rearEnqueue(21);
    printQueue();
   rearDequeue();
   frontDequeue();
    printQueue();

    return 0;
}