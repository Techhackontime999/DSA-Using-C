#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Queue
{
    int size;
    int front;
    int rare;
    int *arr;
    int count;
} Queue;

Queue *queue;
void createQueue(int qsize)
{
    queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (int *)malloc(qsize * sizeof(int));
    queue->size = qsize;
    queue->front = queue->rare = -1;
    queue->count = 0;
    return;
}
bool isFull()
{
    if (queue->rare + 1 == queue->front)
    {
        return true;
    }
    return false;
}
bool isEmpty()
{
    if (queue->front == queue->rare)
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
//below is the circular increament

    queue->rare = (queue->rare + 1) % queue->size;
    queue->arr[queue->rare] = data;
    queue->count++;

    printf("\nElement %d added in the queue.\n", data);
    return;
}
int dequeue()
{
    if (isEmpty())
    {
        printf("\nQueue Underflow -> Queue is now empty .\n");
        return -1;
    }
//below is the circular increament
    queue->front = (queue->front + 1) % queue->size;
    int data = queue->arr[queue->front];
    queue->count--;
    printf("\nElement %d Out from the queue.\n", data);
    return data;
}
void printQueue()
{
    if (isEmpty())
    {
        return;
    }

    printf("\nElements present in the queue are: ");

    for (int i = 0; i < queue->count; i++)
    {
        printf(" %d ", queue->arr[i]);
    }
    printf("\n");
    return;
}
int main()
{
    createQueue(4);
    enqueue(10);
    enqueue(11);
    enqueue(12);
    enqueue(13);

    printQueue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    enqueue(14);
    enqueue(15);
    enqueue(16);
    enqueue(17);
    enqueue(18);

    printQueue();
    dequeue();
    dequeue();
    dequeue();
    enqueue(14);
    enqueue(15);
    enqueue(16);
    enqueue(17);
       dequeue();
    dequeue();
    dequeue();
    printf("%d\n", queue->count);
     enqueue(18);
    enqueue(19);
    enqueue(20);
       dequeue();
    dequeue();
    dequeue();
    printf("%d\n", queue->count);
    return 0;
}