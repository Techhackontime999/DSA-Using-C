// first we implement queue using only one pointer called back or rare end.
// in below queue insertion is done in O(1) time complexity but deletion in done in O(n) time complexity.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Queue
{
    int size;
    int back;
    int *arr;
    int count;
};
struct Queue *queue;
void createQueue(int qsize)
{
    queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->arr = (int *)malloc(qsize * sizeof(int));
    queue->size = qsize;
    queue->back = -1;
    queue->count = 0;
    return;
}
bool isFull()
{
    if (queue->back + 1 == queue->size)
    {
        return true;
    }
    return false;
}
bool isEmpty()
{
    if (queue->back == -1)
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
    queue->back++;
    queue->arr[queue->back] = data;
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
    int data = queue->arr[0];
    int i = 0;
    // while (i < queue->size - 1)
    // {
    //     queue->arr[i] = queue->arr[i + 1];
    //     i++;
    // }
    // efficient method below
    while (i < queue->count)
    {
        queue->arr[i] = queue->arr[i + 1];
        i++;
    }
    queue->back--;
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
    
    printf("\nElements in the queue are: ");
    // for (int i = 0; i < queue->size; i++)
    // {
    //     printf(" %d ", queue->arr[i]);
    // }
    // efficient method below
    for (int i = 0; i < queue->count; i++)
    {
        printf(" %d ", queue->arr[i]);
    }
    printf("\n");
    return;
}
int main()
{
    createQueue(10);
    enqueue(10);
    enqueue(11);
    enqueue(12);
    enqueue(13);
    printQueue();
    dequeue();
    dequeue();
    dequeue();
    printQueue();

    dequeue();
    dequeue();
    printQueue();

    return 0;
}