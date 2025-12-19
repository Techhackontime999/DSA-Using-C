#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
// below isBST function follow inorder traversel principal to check isBST.
int isBST(Node *root)
{
    static Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        // below statement check isBST in ascending order or not
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

// state the search
//  int recursiveSearch(Node *root, int data)
//  {
//      if (root != NULL)
//      {
//          if (root->data == data)
//          {
//              return 1;
//          }
//          else if (root->data > data)
//          {
//              return recursiveSearch(root->left,data);
//          }
//          else
//          {
//              return recursiveSearch(root->right,data);
//          }

//         // if (recursiveSearch(root->left, data))
//         // {
//         //     return 1;
//         // }
//         // return recursiveSearch(root->right, data);

//     }
//     return 0;
// }
// returning meeted node when search
Node *recursiveSearch(Node *root, int data)
{
    if (root != NULL)
    {
        if (root->data == data)
        {
            return root;
        }
        else if (root->data > data)
        {
            return recursiveSearch(root->left, data);
        }
        else
        {
            return recursiveSearch(root->right, data);
        }
    }
    return NULL;
}
Node *iterativeSearch(Node *root, int data)
{
    Node *ptr = root;

    while (ptr != NULL)
    {
        if (ptr->data == data)
        {
            return ptr;
        }
        else if (ptr->data > data)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }
}
// below insert not insert when BST is Empty.
void insert(Node *root, int data)
{
    Node *prev = NULL;
    Node *node = createnode(data);

    while (root != NULL)
    {
        prev = root;

        if (root->data == data)
        {
            printf("Cannot insert %d > Already in BST.\n", data);
            return;
        }
        else if (root->data > data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    if (prev->data > data)
    {
        prev->left = node;
        return;
    }
    if (prev->data < data)
    {
        prev->right = node;
        return;
    }
}
// below insert function also work when BST is empty.
Node *bestInsert(Node *root, int data)
{
    Node *prev = NULL;
    Node *node = createnode(data);
    Node *head = root;
    if (head == NULL)
    {
        head = node;
        return head;
    }
    while (root != NULL)

    {
        prev = root;

        if (root->data == data)
        {
            printf("Cannot insert %d > Already in BST.\n", data);
            return head;
        }
        else if (root->data > data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    if (prev->data > data)
    {
        prev->left = node;
        return head;
    }
    if (prev->data < data)
    {
        prev->right = node;
        return head;
    }
}
// deleton in BST : search + delete operation
// case-0: when data not present in BST.
// case-1: when data is at leaf node.
// case-2: when data is at non-leaf node and inOrderPre and inOrderPost is at leaf node.
// case-3: when data is at root node.

// inOrder traversal of BST looks like below
// 1,2,3,4,5,6,7,8
// here inOrderpre of 4 is 3 and inOrderPost is 5.
// inorderpre means predecessor of inorder traversal of that node.
// inorderpost means postcessor of inorder traversal of that node.

// case-1:soln-> search for data if present then delete either give error msg.
// void deleteLeaf(Node *root, int data)
// {
//     // below provide node after search where data is present
//     Node *prev = NULL;
//     // search start
//     Node *ptr = root;
//     Node *node = NULL;
//     while (ptr != NULL)
//     {
//         prev = ptr;
//         if (ptr->data == data)
//         {
//             node = ptr;
//             break;
//         }
//         if (ptr->data > data)
//         {
//             ptr = ptr->left;
//         }
//         else
//         {
//             ptr = ptr->right;
//         }
//     }
//     // search end
//     if (node == NULL)
//     {
//         printf("Cannot delete %d >   Not in BST.\n", data);
//         return;
//     }
//     if (prev->left == node)
//     {
//         prev->left = NULL;
//         free(node);
//         return;
//     }
//     else
//     {
//         prev->right = NULL;
//         free(node);
//         return;
//     }
// }
bool isLeaf(Node *node)
{
    if (node->left == NULL && node->right == NULL)
    {
        return true;
    }
    return false;
}
Node *inOrderPredecessor(Node *root)
{

    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
Node *inOrderSuccessor(Node *root)
{

    root = root->right;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
// delete node function delete node where data is present and return value NULL or replace through ipre or ipost after deletion iinstead of data i.e return NULL or child subtree from tree
Node *deleteNode(Node *root, int data)
{
    Node *ipre, *ipost;
    // base condition for recursion
    if (root == NULL)
    {
        return NULL;
    }

     if (root->left == NULL && root->right == NULL && root->data == data)
    {
        //data at leaf node
        free(root);
        return NULL;
    }
    //below case is for only one child node i.e ipre or ipost any of one is NULL
    else if (root->left == NULL && root->data == data)
    {
        //data is present at non-leaf node where node have only one right child
        // in this case root is automatically swap with temp
        Node *temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL && root->data == data)
    {
        //data is present at non-leaf node where node have only one left child
        // in this case root is automatically swap with temp
        Node *temp = root->left;
        free(root);
        return temp;
    }

    // search for the node to be deleted
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    // now delete the node
    else
    {
        //this case work only and only when node to be deleted have two child
        ipre = inOrderPredecessor(root);
        ipost = inOrderSuccessor(root);
        // Case: Node to be deleted found
        if (isLeaf(ipre))
        {
            root->data = ipre->data;
            root->left = deleteNode(root->left, ipre->data);
        }
        else if (isLeaf(ipost))
        {
            root->data = ipost->data;
            root->right = deleteNode(root->right, ipost->data);
        }
        else
        {

            root->data = ipre->data;
            root->left = deleteNode(root->left, ipre->data);
        }
    }
    return root;
}
int main()
{

    //  below tree inorder traversal not giving an ascending sorted array so it not BST.
    //   Node *head = createnode(2);
    // Node *a1 = createnode(3);
    // Node *a2 = createnode(4);
    // Node *b1 = createnode(5);
    // Node *b2 = createnode(6);
    // Node *c1 = createnode(7);
    // Node *c2 = createnode(8);
    // below tree inorder traversal ging an ascending sorted arrayn so it called BST.
    Node *head = createnode(4);
    Node *a1 = createnode(2);
    Node *a2 = createnode(6);
    Node *b1 = createnode(1);
    Node *b2 = createnode(3);
    Node *c1 = createnode(5);
    Node *c2 = createnode(7);
    Node *d1 = createnode(9);
    Node *e1 = createnode(8);
    head->left = a1;
    head->right = a2;
    a1->left = b1;
    a1->right = b2;
    a2->left = c1;
    a2->right = c2;
    c2->right = d1;
    d1->left = e1;

    // inorder traversal of a binary search tree gives an ascending sorted array.
    // inOrder(head);
    // printf("\n");
    // this insert function not handle data when BST is empty.
    // insertion
    // insert(head, 15);
    // insert(head, 0);
    // insert(head, 10);
    // insert(head, 12);
    // insert(head, 14);
    // insert(head, 11);
    // insert(head, 10); // no duplicate allowed
    // below BST also insert when BST is empty.
    // head = NULL;
    inOrder(head);
    printf("\n");
    // insertion
    // head = bestInsert(head, 1);
    // head = bestInsert(head, 2);
    // head = bestInsert(head, 16);
    // head = bestInsert(head, 0);
    // head = bestInsert(head, 13);
    // head = bestInsert(head, 16);
    // deletion
    // head = deleteNode(head, 8);
    // head = deleteNode(head, 9);
    // head = deleteNode(head, 3);
    head = deleteNode(head, 4);


    inOrder(head);
    printf("\n");
    // int data = 9;
    // printf("This Binary tree is BST or not ? : %d\n",isBST(head));
    // state after search
    // printf("Element %d is present in BST or not ? : %d\n", data, recursiveSearch(head, data));
    // return node after search
    // Node *result = recursiveSearch(head, data);
    // if (result != NULL)
    // {
    //     printf("Element %d is present in BST.\n", data);
    // }
    // else
    // {
    //     printf("Element %d is not present in BST.\n", data);
    // }
    // iterative search
    // Node *result = iterativeSearch(head, data);
    // if (result != NULL)
    // {
    //     printf("Element %d is present in BST.\n", data);
    // }
    // else
    // {
    //     printf("Element %d is not present in BST.\n", data);
    // }

    return 0;
}
