// in Adjacency list representation of graph looks like below
//  Node       Connection-list
//  0     ->     4->2->1
//  1     ->     0->5
//  2     ->     0->4->3
//  3     ->     2->5
//  4     ->     0->2
//  5     ->     1->3

#include <stdio.h>
#include <stdlib.h>
#include "C:/Users/ADMIN/OneDrive/Desktop/code/DSA/DataStructure/queue/queueADTUsingArray02.h"
typedef struct ConnectList
{
    int data;
    struct ConnectList *next;
} ConnectList;
typedef struct Node
{
    int data;
    struct Node *next;
    ConnectList *connection_ptr;
} Node;

Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->connection_ptr = NULL;
    node->next = NULL;
    return node;
}
ConnectList *createConnectListNode(Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    ConnectList *n = (ConnectList *)malloc(sizeof(ConnectList));
    n->data = node->data;
    n->next = NULL;
    return n;
}

ConnectList *insertConnections(ConnectList *root, Node *node)
{
    if (node == NULL)
    {
        return root;
    }

    if (root == NULL)
    {
        return createConnectListNode(node);
    }
    ConnectList *n = createConnectListNode(node);
    ConnectList *ptr = root;
    while (ptr->next != NULL)
    {
        if (ptr->data == node->data)
        {
            return root;
        }
        ptr = ptr->next;
    }
    ptr->next = n;
    return root;
}
Node *insertNode(Node *root, int data)
{

    if (root == NULL)
    {
        return createNode(data);
    }
    Node *ptr = root;

    while (ptr->next != NULL)
    {
        if (ptr->data == data)
        {
            return root;
        }
        ptr = ptr->next;
    }
    Node *node = createNode(data);
    ptr->next = node;
    return root;
}
void linkedListTraversal(Node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return;
}
void connectionListTraversal(ConnectList *ptr)
{

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return;
}
Node *bestInsert(Node *root, int data, int *connectionArr, int size)
{

    if (root == NULL && connectionArr == NULL)
    {
        return createNode(data);
    }
    else if (root == NULL && connectionArr != NULL)
    {
        Node *n = createNode(data);
        Node *node = (Node *)malloc(sizeof(Node));
        ;
        for (int i = 0; i < size; i++)
        {
            node->data = connectionArr[i];
            n->connection_ptr = insertConnections(n->connection_ptr, node);
        }
        return n;
    }

    else if (root != NULL && connectionArr == NULL)
    {

        root = insertNode(root, data);
        return root;
    }
    else
    {
        Node *ptr = root;
        while (ptr->next != NULL)
        {
            if (ptr->data == data)
            {
                return root;
            }

            ptr = ptr->next;
        }
        Node *n = createNode(data);
        ptr->next = n;
        Node *node = (Node *)malloc(sizeof(Node));
        for (int i = 0; i < size; i++)
        {
            node->data = connectionArr[i];
            n->connection_ptr = insertConnections(n->connection_ptr, node);
        }

        return root;
    }
}
void adjacencyListTraversal(Node *root)
{
    Node *ptr = root;
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        printf(" --> ");
        ConnectList *p = ptr->connection_ptr;
        // here ptr->connectionptr also a node in connectionlist which is head node
        while (p != NULL)
        {
            printf(" %d ", p->data);
            p = p->next;
        }

        printf("\n");

        ptr = ptr->next;
    }

    return;
}
Queue *queue;
void BFSTraversal(Node *root)
{
    int numOfNode = 0;
    Node *p = root;
    int max = root->data;
    while (p != NULL)
    {
        numOfNode++;
        if (p->data > max)
        {
            max = p->data;
        }

        p = p->next;
    }
    createQueue(numOfNode);
    int visited[max + 1];
    // Node *b = root;
    for (int i = 0; i < max + 1; i++)
    {
        visited[i] = 0;
        // while (b != NULL)
        // {

        //     if (i != b->data)
        //     {
        //         visited[i] = 1;
        //     }

        //     b = b->next;
        // }
    }

    visited[root->data] = 1;
    enqueue(root->data);
    while (!isEmpty())
    {
         int currData = dequeue();
         
        printf(" %d ", currData);

        // Find actual node with currData
        Node *currNode = root;
        while (currNode !=NULL && currNode->data != currData)
            currNode = currNode->next;

        if (currNode == NULL) continue; // Defensive programming

        ConnectList *a = currNode->connection_ptr;
        

            while (a != NULL )
            {
                if (visited[a->data] == 0)
                {
                    visited[a->data] = 1;
                enqueue(a->data);
                }
                
                // printf(" %d ", a->data);
               
                a = a->next;
            }
    }
    return;
}
int main()
{
    // Node *n0, *n1, *n2, *n3, *n4, *n5;
    // n0 = createNode(0);
    // n1 = createNode(1);
    // n2 = createNode(2);
    // n3 = createNode(3);
    // n4 = createNode(4);
    // n5 = createNode(5);

    // n0->connection_ptr = insertConnections(n0->connection_ptr, n4);
    // n0->connection_ptr = insertConnections(n0->connection_ptr, n1);
    // n0->connection_ptr = insertConnections(n0->connection_ptr, n2);

    // n1->connection_ptr = insertConnections(n1->connection_ptr, n0);
    // n1->connection_ptr = insertConnections(n1->connection_ptr, n5);

    // n2->connection_ptr = insertConnections(n2->connection_ptr, n0);
    // n2->connection_ptr = insertConnections(n2->connection_ptr, n4);
    // n2->connection_ptr = insertConnections(n2->connection_ptr, n3);

    // n3->connection_ptr = insertConnections(n3->connection_ptr, n2);
    // n3->connection_ptr = insertConnections(n3->connection_ptr, n5);

    // n4->connection_ptr = insertConnections(n4->connection_ptr, n0);
    // n4->connection_ptr = insertConnections(n4->connection_ptr, n2);

    // n5->connection_ptr = insertConnections(n5->connection_ptr, n1);
    // n5->connection_ptr = insertConnections(n5->connection_ptr, n3);

    // n0->next = n1;
    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;
    // n4->next = n5;
    // linkedListTraversal(n0);
    // printf("\n");
    // connectionListTraversal(n0->connection_ptr);
    // printf("\n");
    // connectionListTraversal(n1->connection_ptr);
    // printf("\n");
    // connectionListTraversal(n2->connection_ptr);
    // printf("\n");
    // connectionListTraversal(n3->connection_ptr);
    // printf("\n");
    // connectionListTraversal(n4->connection_ptr);
    // printf("\n");
    // connectionListTraversal(n5->connection_ptr);
    // printf("\n");

    // Node *root = NULL;
    // root = insertNode(root, 0);
    // root = insertNode(root, 1);
    // root = insertNode(root, 2);
    // root = insertNode(root, 3);
    // root = insertNode(root, 4);
    // root = insertNode(root, 5);
    // linkedListTraversal(root);
    // printf("\n");

    //     Node *root=NULL;
    //     int *arr=(int *)malloc(2*sizeof(int));
    //     arr[0]=1;
    //     arr[1]=2;
    //     root=bestInsert(root,0,arr,2);
    //     linkedListTraversal(root);
    //     printf("\n");
    //     connectionListTraversal(root->connection_ptr);
    // printf("\n");
    //    Node *root1=NULL;
    //     root1=bestInsert(root1,1,arr,2);
    //     linkedListTraversal(root1);
    //     printf("\n");
    //     connectionListTraversal(root1->connection_ptr);

    Node *root = NULL;
    int num, node, size;
    int *arr;
    printf("Enter no of Node: ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {

        printf("Enter node %d : ", i + 1);
        scanf("%d", &node);
        printf("Enter connectionList size: ");
        scanf("%d", &size);
        arr = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++)
        {
            printf("Enter connection node %d : ", j + 1);
            scanf("%d", &arr[j]);
        }
        root = bestInsert(root, node, arr, size);
    }

    // linkedListTraversal(root);
    // printf("\n");
    // connectionListTraversal(root->connection_ptr);
    printf("\nAdjacency list is...\n");
    adjacencyListTraversal(root);
    printf("\n");
    BFSTraversal(root);

    // checking work queue
    //     createQueue(10);
    //     enqueue(2);
    //     enqueue(3);
    //     enqueue(2);
    //     enqueue(4);
    //     enqueue(6);

    //   dequeue();
    //   dequeue();

    //     printQueue();
    return 0;
}