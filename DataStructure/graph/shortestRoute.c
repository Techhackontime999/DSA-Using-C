// in Adjacency matrix representation of graph looks like below
// 0,1,2,3,4,5 is the node or vertex and value based on linked between two node represent connection
// when connection between two node is available then write its connection cost otherwise -1
//      0   1   2   3   4   5  <-- Node
//  0  00  13  -1  -1   04 -1
//  1  11  04  -1  08  -1  02
//  2  03  -1  00  13  -1  01
//  3  -1  19  -1  22  30  -1
//  4  03  16  -1  -1  03  00
//  5  -1  03  08  -1  -1  06
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
#include <limits.h>

void sortestRoute(int i, int j)
{
    int numOfNode, max;
    printf("Number of node: ");
    scanf("%d", &numOfNode);
    int *brr = (int *)malloc(numOfNode * sizeof(int));
    for (int k = 0; k < numOfNode; k++)
    {
        printf("Enter node: ");
        scanf("%d", &brr[k]);
    }
    bool verification = false;
    for (int l = 0; l < numOfNode; l++)
    {
        if (i == brr[l])
        {
            for (int l = 0; l < numOfNode; l++)
            {
                if (j == brr[l])
                {
                    verification = true;
                }
            }
        }
    }

    if (verification)
    {

        // max
        max = brr[0];
        for (int k = 1; k < numOfNode; k++)
        {
            if (brr[k] > max)
            {
                max = brr[k];
            }
        }

        int **arr = (int **)calloc(max + 1, sizeof(int *));
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
                    arr[i][j] = -1;
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
                    arr[j][i] = -1;
                }
            }
        }
        printf(" give Answer in 0 or 1\n");

        // loop for connction marking
        for (int i = 0; i < max + 1; i++)
        {
            for (int j = i; j < max + 1; j++)
            {
                if (arr[i][j] == 0)
                {
                    int ch;
                    printf(" %d is connected to %d or not: ", i, j);
                    scanf("%d", &ch);
                    if (ch == 1)
                    {
                        int n;
                        printf("Enter connection cost: ");
                        scanf("%d", &n);
                        arr[i][j] = n;
                        arr[j][i] = n;
                    }
                    else
                    {
                        arr[i][j] = -1;
                    }
                }
            }
        }

        // now find sortest route start
        printf(" %d -> ", i);
        int numOfConnection = 0;

        for (int k = 0; k < max + 1; k++)
        {
            if (arr[i][k] != -1)
            {
                numOfConnection++;
            }

        }
        Queue **q=(Queue **)malloc(numOfConnection*sizeof(Queue*));
        for (int i = 0; i < numOfConnection; i++)
        {
         q[i]=createQueue(max);
        }
        


        // find sortest route end
    }

    else
    {
        printf(" %d is not a node which you passed in function.\n", i);
    }
    return;
}
int main()
{

    int i, j;
    printf("Enter Your location : ");
    scanf("%d", &i);
    printf("Enter destination location : ");
    scanf("%d", &j);
    shortestRoute(i, j);

    return 0;
}
