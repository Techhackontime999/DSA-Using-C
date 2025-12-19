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

void dfsTraversal(Node *root, Node *s_node)
{

    static int count = 0;
    static int *visited;
    static int max;
    if (count == 0)
    {

        max = root->data;
        Node *ptr = root;
        while (ptr != NULL)
        {

            if (max < ptr->data)
            {
                max = ptr->data;
            }
            ptr = ptr->next;
        }

        // end max
        // created a visited array
        visited = (int *)calloc((max + 1), (max + 1) * sizeof(int));
        // marking not present node as visited by default

        for (int i = 0; i < max + 1; i++)
        {
            bool flag = false;
            ptr = root;
            while (ptr != NULL)
            {
                if (ptr->data == i)
                {
                    flag = true;
                    break;
                }

                ptr = ptr->next;
            }
            if (!flag)
            {
                visited[i] = 1;
            }
        }

        // end
        printf("Dfs Traversal is: ");
        count++;
    }

    int i = s_node->data;
    printf(" %d ", i);
    visited[i] = 1;
    ConnectList *p = s_node->connection_ptr;
    Node *new_s_node;

    while (p != NULL)
    {
        if (!visited[p->data])
        {
            Node *q = root;
            while (q != NULL)
            {
                if (q->data == p->data)
                {
                    new_s_node = q;
                    break;
                }

                q = q->next;
            }
            dfsTraversal(root, new_s_node);
        }
        p = p->next;
    }

    return;
}
void bfsTraversal(Node *root, Node *s_node)
{
    static int *visited;
    static int max;
    // finding max
    max = root->data;
    Node *ptr = root;
    while (ptr != NULL)
    {

        if (max < ptr->data)
        {
            max = ptr->data;
        }
        ptr = ptr->next;
    }

    // end max
    // created a visited array
    visited = (int *)calloc((max + 1), (max + 1) * sizeof(int));
    // marking not present node as visited by default

    for (int i = 0; i < max + 1; i++)
    {
        bool flag = false;
        ptr = root;
        while (ptr != NULL)
        {
            if (ptr->data == i)
            {
                flag = true;
                break;
            }

            ptr = ptr->next;
        }
        if (!flag)
        {
            visited[i] = 1;
        }
    }

    // end
    Queue *queue;

    queue = createQueue(20);
    int i = s_node->data;
    printf("Bfs Traversal is: %d ", i);
    visited[i] = 1;
    enqueue(queue, i);
    Node *prev;
    Node *q;
    while (!isEmpty(queue))
    {
        // we can not do q=node for all the node because q may be non-root node
        q = root; // here logical error when i passing n4,n3,n5 or any instead of root node n0 its not able to traverse each node by this its skipping the previous connected node .
        int data = dequeue(queue);
        // printf("\ndata: %d\n",data);
        while (q != NULL)
        {
            if (q->data == data)
            {
                prev = q;
                break;
            }

            q = q->next;
        }

        ConnectList *p = prev->connection_ptr;
        // printf("\ndata: %d\n", prev->data);

        while (p != NULL)
        {
            if (!visited[p->data])
            {
                printf(" %d ", p->data);
                visited[p->data] = 1;
                enqueue(queue, p->data);
            }

            p = p->next;
        }
    }
}
void printQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("\nQueue is empty.\n");
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
    // method=01
    Node *n0, *n1, *n2, *n3, *n4, *n5;
    n0 = createNode(0);
    n1 = createNode(1);
    n2 = createNode(2);
    n3 = createNode(3);
    n4 = createNode(4);
    n5 = createNode(6);

    n0->connection_ptr = insertConnections(n0->connection_ptr, n4);
    n0->connection_ptr = insertConnections(n0->connection_ptr, n1);
    n0->connection_ptr = insertConnections(n0->connection_ptr, n2);

    n1->connection_ptr = insertConnections(n1->connection_ptr, n0);
    n1->connection_ptr = insertConnections(n1->connection_ptr, n5);

    n2->connection_ptr = insertConnections(n2->connection_ptr, n0);
    n2->connection_ptr = insertConnections(n2->connection_ptr, n4);
    n2->connection_ptr = insertConnections(n2->connection_ptr, n3);

    n3->connection_ptr = insertConnections(n3->connection_ptr, n2);
    n3->connection_ptr = insertConnections(n3->connection_ptr, n5);

    n4->connection_ptr = insertConnections(n4->connection_ptr, n0);
    n4->connection_ptr = insertConnections(n4->connection_ptr, n2);

    n5->connection_ptr = insertConnections(n5->connection_ptr, n1);
    n5->connection_ptr = insertConnections(n5->connection_ptr, n3);

    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    adjacencyListTraversal(n0);
    printf("\n");
    // end
    //  method-02
    //  Node *root = NULL;
    //  root = insertNode(root, 0);
    //  root = insertNode(root, 1);
    //  root = insertNode(root, 2);
    //  root = insertNode(root, 3);
    //  root = insertNode(root, 4);
    //  root = insertNode(root, 5);
    //  adjacencyListTraversal(root);
    // end

    //  travesal bfs or dfs start
    // bfsTraversal(n0, n3);
    // printf("\n");
    // bfsTraversal(n0, n1);
    // printf("\n");
    // bfsTraversal(n0, n0);
    // bfsTraversal(n0, n0);
    // printf("\n");

    dfsTraversal(n0, n2);
    printf("\n");

    bfsTraversal(n0, n3);
    printf("\n");

    // dfsTraversal(n0, n0);
    // printf("\n");
    // printQueue(queue);
//PROBLEM: HERE WE CAN CALL AT A TIME ONLY ONE DFS TRAVERSAL BECAUSE WE HAVE ONLY ONE STACK WHICH IS SHARED FOR FUNCTION EXECUTION I USING THAT BY DEFAULT . NEED TO USE AND IMPLEMENT HIS OWN STACK.FOR MULTIPLE CALL. 
    return 0;
}