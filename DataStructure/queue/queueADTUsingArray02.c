// in this implementation we implement queue using two pointe r first front or fourth end and second back or rare end.
// in below queue insertion is done in O(1) time complexity and deletion also done in O(1) time complexity.
// but in this implementation may occur wastege of spaces when increment front by 1 linearly.
//one disadvantage of this method is when queue size is 4 , 4 element enqueue in the queue and 4 element dequeue from the queue then rare+1 == size of queue  and giving queue overflow but spaces present in the queue before the front end idx.because we increase the front by one when dequeue. 
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
    if (queue->rare + 1 == queue->size)
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
    queue->rare++;
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
    queue->front++;
    int data = queue->arr[queue->front];
    queue->count--;
    printf("\nElement %d Out from the queue.\n", data);
       //queue->arr update after dequeue
//    for (int i = 0; i < queue->size; i++)
//    {
//     queue->arr[i]=queue->arr[i+1];
//    }
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

    printQueue();
    dequeue();

    return 0;
}