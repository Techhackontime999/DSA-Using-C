// in graph using edge set representation store the pairs of node/vertices connected with an edge exe: {(0,1) , (0,4) , (1,4)}
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "C:/Users/ADMIN/OneDrive/Desktop/code/DSA/DataStructure/queue/queueADTUsingArray02.h"

typedef struct Edge
{
    int starting_vertex;
    int ending_vertex;

} Edge;
typedef struct Node
{
    Edge *edge;
    struct Node *next;
} Node;
Node *root; // edge set array
int max;    // finding max for visited arr creation

Node *createEdge(int start, int end)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->edge = (Edge *)malloc(sizeof(Edge));
    node->edge->ending_vertex = end;
    node->edge->starting_vertex = start;
    node->next = NULL;
}
void edgeSetTraversal(Node *ptr)
{
    printf("[ ");
    while (ptr != NULL)
    {
        printf("(%d , %d) ", ptr->edge->starting_vertex, ptr->edge->ending_vertex);
        ptr = ptr->next;
    }
    printf("]\n");

    return;
}
Node *insertEdge(int starting_node, int ending_node)
{
    if (root == NULL)
    {
        Node *node = createEdge(starting_node, ending_node);
        return node;
    }
    Node *ptr = root;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    Node *node = createEdge(starting_node, ending_node);
    ptr->next = node;
    return root;
}
int *visited;
bool checkVertexInEdgeSet(int i)
{
    Node *ptr = root;
    if (ptr == NULL)
    {
        return false;
    }

    while (ptr != NULL)
    {
        if (ptr->edge->starting_vertex == i || ptr->edge->ending_vertex == i)
        {
            return true;
        }

        ptr = ptr->next;
    }
}
void bfsTraversal(int i)
{
    if (checkVertexInEdgeSet(i))
    {

        // max start
        Node *ptr = root;
        max = INT_MIN;
        while (ptr != NULL)
        {
            if (max < ptr->edge->ending_vertex)
            {
                max = ptr->edge->ending_vertex;
                if (max < ptr->edge->starting_vertex)
                {
                    max = ptr->edge->starting_vertex;
                }
            }
            ptr = ptr->next;
        }
        // max end
        // visited array creation start
        visited = (int *)calloc(max + 1, (max + 1) * sizeof(int));
        // mark node default as visited 1 in visted arr which is not the node in edge set

        for (int i = 0; i < max + 1; i++)
        {
            ptr = root;
            bool flag = false;
            while (ptr != NULL)
            {
                if (i == ptr->edge->starting_vertex || i == ptr->edge->ending_vertex)
                {
                    flag = true;
                }

                ptr = ptr->next;
            }
            if (!flag)
            {
                visited[i] = 1;
            }
        }
        // end
        Queue *queue = createQueue(20);
        printf("Bfs traversal is: %d ", i);
        visited[i] = 1;
        enqueue(queue, i);
        while (!isEmpty(queue))
        {
            int data = dequeue(queue);
            Node *ptr = root;
            while (ptr != NULL)
            {
                if (ptr->edge->starting_vertex == data && !visited[ptr->edge->ending_vertex])
                {

                    visited[ptr->edge->ending_vertex] = 1;
                    printf(" %d ", ptr->edge->ending_vertex);
                    enqueue(queue, ptr->edge->ending_vertex);
                }

                ptr = ptr->next;
            }
        }
    }
    else
    {
        printf("Entered starting Node %d not in your edge set.", i);
    }
    return;
}
void dfsTraversal(int node)
{
    static int count = 0;
    if (count == 0)
    {
        // max start
        Node *ptr = root;
        max = INT_MIN;
        while (ptr != NULL)
        {
            if (max < ptr->edge->ending_vertex)
            {
                max = ptr->edge->ending_vertex;
                if (max < ptr->edge->starting_vertex)
                {
                    max = ptr->edge->starting_vertex;
                }
            }
            ptr = ptr->next;
        }
        // max end
        // visited array creation start
        visited = (int *)calloc(max + 1, (max + 1) * sizeof(int));
        // mark node default as visited 1 in visted arr which is not the node in edge set

        for (int i = 0; i < max + 1; i++)
        {
            ptr = root;
            bool flag = false;
            while (ptr != NULL)
            {
                if (i == ptr->edge->starting_vertex || i == ptr->edge->ending_vertex)
                {
                    flag = true;
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
    else
    {
        visited[node] = 1;
        printf(" %d ", node);
        Node *p = root;
        while (p != NULL)
        {
            if (p->edge->starting_vertex == node)
            {
                if (!visited[p->edge->ending_vertex])
                {
                    dfsTraversal(p->edge->ending_vertex);
                }
            }

            p = p->next;
        }
    }
}
int main()
{

    // method-01

    // Node *first = createEdge(0, 1);
    // Node *sec = createEdge(1, 2);
    // Node *third = createEdge(0, 4);
    // first->next = sec;
    // sec->next = third;
    // edgeSetTraversal(first);

    // method-02

    // root = NULL;
    // root = insertEdge(0, 1);
    // root = insertEdge(0, 4);
    // root = insertEdge(0, 5);
    // root = insertEdge(1, 2);
    // root = insertEdge(1, 5);
    // root = insertEdge(5, 4);
    // edgeSetTraversal(root);

    // printing visited for check
    // for (int i = 0; i < max+1; i++)
    // {
    //     printf("%d ",visited[i]);
    // }
    // printf("\n");
    // end
    // visited array creation end
    // traversal using bfs dfs
    // bfsTraversal(1);
    // printf("\n");
    // bfsTraversal(0);
    // printf("\n");
    while (true)
    {

        // input from user
        printf("Enter edges starting and ending vertex.\n");
        root = NULL;
        int noOfEdge;
        printf("Number of connections you want to enter: ");
        scanf("%d", &noOfEdge);
        int start, end;
        for (int i = 0; i < noOfEdge; i++)
        {
            printf("Enter edge[%d] starting vertex: ", i);
            scanf("%d", &start);
            printf("Enter edge[%d] ending vertex: ", i);
            scanf("%d", &end);
            root = insertEdge(start, end);
        }

        // end
        int i;
        printf("Enter starting node: ");
        scanf("%d", &i);
        int choice;
        printf("Enter 0[BFS Traversal] & 1[DFS Traversal]: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            bfsTraversal(i);
            printf("\n");
            break;
        case 1:
            dfsTraversal(i);
            printf("\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
        printf("\n");
    }

    return 0;
}
