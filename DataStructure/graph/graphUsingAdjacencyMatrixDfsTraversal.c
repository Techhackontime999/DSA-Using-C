// in Adjacency matrix representation of graph looks like below
// 0,1,2,3,4,5 is the node or vertex and value based on linked between two node represent connection
// when connection between two node is available then represented by 1 otherwise 0
//     0  1  2  3  4  5  <-- Node
//  0  0  1  1  0  0  1
//  1  1  0  0  0  0  1
//  2  0  0  0  1  1  0
//  3  1  0  1  0  0  0
//  4  0  1  1  1  0  0
//  5  1  0  0  0  1  1
//  ^
//  |

// N
// o
// d
// e

#include <stdio.h>
#include <stdlib.h>
#include "C:/Users/ADMIN/OneDrive/Desktop/code/DSA/DataStructure/queue/queueADTUsingArray02.h"
#include <stdbool.h>
Queue *queue;
int numOfNode, max;
int *brr;
int *visited;
int **arr;
void BfsTraversal(int i)
{
    bool verify = false;
    for (int l = 0; l < numOfNode; l++)
    {
        if (i == brr[l])
        {
            verify = true;
        }
    }
    if (verify)
    {

        printf("Bfs Traversal is: %d ", i);
        visited[i] = 1;
        enqueue(queue, i);
        while (!isEmpty(queue))
        {
            int data = dequeue(queue);
            for (int j = 0; j < max + 1; j++)
            {
                if (arr[data][j] == 1 && visited[j] == 0)
                {
                    printf(" %d ", j);
                    visited[j] = 1;
                    enqueue(queue, j);
                }
            }
        }
    }
    else
    {
        printf(" %d is not a node which you passed in bfs function can't able to traverse.\n", i);
    }
    return;
}

void dfsTraversal(int i)
{
    static int count = 1;
    static bool verify = false;
    if (count == 1)
    {
        for (int l = 0; l < numOfNode; l++)
        {
            if (i == brr[l])
            {
                verify = true;
            }
        }
        if (verify)
        {
            printf("Dfs Traversal is: ");
        }
        else
        {
            printf(" '%d' is not a node which you passed in dfs function can't able to traverse.\n", i);
        }

        count++;
    }

    if (verify)
    {
        visited[i] = 1;

        printf(" %d ", i);
        for (int j = 0; j < max + 1; j++)
        {
            if (arr[i][j] == 1 && !visited[j])
            {
                dfsTraversal(j);
            }
        }
    }

    return;
}
int main()
{
    queue = createQueue(20);

    // adjacency matrix created
    // int visited[6] = {0, 0, 0, 0, 0, 0};
    // int arr[6][6] = {
    //     {0, 1, 1, 0, 0, 1},
    //     {1, 0, 0, 0, 0, 1},
    //     {0, 0, 0, 1, 1, 0},
    //     {1, 0, 1, 0, 0, 0},
    //     {0, 1, 1, 1, 0, 0},
    //     {1, 0, 0, 0, 1, 1}};

    printf("Number of node: ");
    scanf("%d", &numOfNode);
    brr = (int *)malloc(numOfNode * sizeof(int));
    for (int k = 0; k < numOfNode; k++)
    {
        printf("Enter node: ");
        scanf("%d", &brr[k]);
    }
    // max
    max = brr[0];
    for (int k = 1; k < numOfNode; k++)
    {
        if (brr[k] > max)
        {
            max = brr[k];
        }
    }
    visited = (int *)calloc(max + 1, sizeof(int));

    arr = (int **)calloc(max + 1, sizeof(int *));
    for (int i = 0; i < max + 1; i++)
    {
        arr[i] = (int *)calloc(max + 1, sizeof(int));
    }
    // array creation end
    // loop for row iteration
    for (int i = 0; i < max + 1; i++)
    {
        for (int j = 0; j < max + 1; j++)
        {
            bool found = false;
            for (int k = 0; k < numOfNode; k++)
            {
                if (i == brr[k])
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                arr[i][j] = 1;
                visited[i] = 1;
            }
        }
    }

    // loop for column iteration
    for (int i = 0; i < max + 1; i++)
    {

        for (int j = 0; j < max + 1; j++)
        {
            bool found = false;

            for (int k = 0; k < numOfNode; k++)
            {
                if (i == brr[k])
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                arr[j][i] = 1;
            }
        }
    }
    printf(" give Answer in 0 or 1\n");

    // loop for connction marking
    for (int i = 0; i < max + 1; i++)
    {
        for (int j = 0; j < max + 1; j++)
        {
            if (arr[i][j] == 0)
            {
                int ch;
                printf(" %d is connected to %d or not: ", i, j);
                scanf("%d", &ch);
                arr[i][j] = ch;
            }
        }
    }

    // // array printing
    // for (int i = 0; i < max + 1; i++)
    // {
    //     for (int j = 0; j < max + 1; j++)
    //     {
    //         printf(" %d ", arr[i][j]);
    //     }
    //     printf("\n");
    // }
    // bfs start

    int i;
    printf("Enter starting node: ");

    scanf("%d", &i);
    // BfsTraversal(i);
    dfsTraversal(i);
    // dfsTraversal(i-1);


    return 0;
}
