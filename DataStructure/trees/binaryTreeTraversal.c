#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;
Node *createnode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return node;
}
void preOrder(Node *node)
{
    if (node != NULL)
    {
        printf(" %d ", node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
    return;
}
void postOrder(Node *node)
{
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        printf(" %d ", node->data);
    }
    return;
}
void inOrder(Node *node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        printf(" %d ", node->data);
        inOrder(node->right);
    }
    return;
}
int main()
{

    //  creating the root node
    Node *head = createnode(2);
    Node *a1 = createnode(3);
    Node *a2 = createnode(4);
    Node *b1 = createnode(5);
    Node *b2 = createnode(6);
    Node *c1 = createnode(7);
    Node *c2 = createnode(8);
    head->left = a1;
    head->right = a2;
    a1->left = b1;
    a1->right = b2;
    a2->left = c1;
    a2->right = c2;
    preOrder(head);
    printf("\n");
    postOrder(head);
    printf("\n");
    inOrder(head);
    printf("\n");
    return 0;
}