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
void printTree(Node *node)
{
    if (node != NULL)
    {
        printf("  %d  ", node->data);
        printTree(node->left);
        printTree(node->right);
    }
}

// void link(Node *node, Node *child, int flag)
// {
//     if (flag == 0)
//     {
//         // left link
//         node->left = child;
//     }
//     else if (flag == 1)
//     {
//         // right link
//         node->right = child;
//     }
//     return;
// }
void link(Node *node, Node *leftchild, Node *rightchild)
{
    // left link
    node->left = leftchild;
    // right link
    node->right = rightchild;
    return;
}
int main()
{
    // method 1
    //  // creating the root node
    //  Node *head = (Node *)malloc(sizeof(Node));
    //  head->left = NULL;
    //  head->right = NULL;
    //  head->data = 2;
    //  // creating the first childen
    //  Node *a1 = (Node *)malloc(sizeof(Node));
    //  a1->left = NULL;
    //  a1->right = NULL;
    //  a1->data = 4;
    //  // creating the second childen
    //  Node *a2 = (Node *)malloc(sizeof(Node));
    //  a2->left = NULL;
    //  a2->right = NULL;
    //  a2->data = 5;
    // method 2
    //  creating the root node
    Node *head = createnode(2);
    Node *a1 = createnode(3);
    Node *a2 = createnode(4);
    Node *b1 = createnode(5);
    Node *b2 = createnode(6);
    Node *c1 = createnode(7);
    Node *c2 = createnode(8);
    // linking both children with his parent(root) node

    // head->left = a1;
    // head->right = a2;
    // a1->left = b1;
    // a1->right = b2;
    // a2->left = c1;
    // a2->right = c2;
    // link(head, a1, 0);
    // link(head, a2, 1);
    // link(a1, b1, 0);
    // link(a1, b2, 1);
    // link(a2, c1, 0);
    // link(a2, c2, 1);
    // link(head, a1, a2);
    // link(a1, b1, b2);
    // link(a2, c1, c2);
    link(head, a1, a2);
    link(a1, b1, b2);
    link(a2, NULL, NULL);
    // printing the data
    // printf("      %d    \n", head->data);
    // printf("    /  \\   \n");
    // printf("   %d    %d    \n", head->left->data, head->right->data);
    printTree(head);
    return 0;
}