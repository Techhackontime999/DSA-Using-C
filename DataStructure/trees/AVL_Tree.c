// AVL Tree is the height balanced binary search tree.
// in Binary tree or Binary search tree most of the time child of tree is skewed in left or right side take the shape of a linear data structure like linked list which cause operation on tree done in O(n) time complexity instead of O(logn) which cause the problem in the real life senario.
// so we use AVL tree which is a height balanced binary search tree and perform operation in O(logn) time .
// to guarantee an upperbound of O(log n) we use AVL tree.

// for a tree to be balanced balance factor(BF) of each node in the tree must be 0, 1 ,or -1 i.e |BF|<=1
// Balance factor = height of right subtree - height of left subtree.
// no of edges from deapest leaf to root is height of a tree.
// no of edges from deapest leaf to a given node is height of that node in a tree.
// for balancing the balance factor we do rotation in Binary search tree which make an AVL tree.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf(" %d ", root->data);
        inOrder(root->right);
    }
    return;
}
void preOrder(Node *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
    return;
}
Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int getHeight(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

int getBalanceFactor(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

Node *rightRotate(Node *a)
{
    Node *b = a->left;
    Node *temp = b->right;
    b->right = a;
    a->left = temp;

    a->height = max(getHeight(a->left), getHeight(a->right)) + 1;
    b->height = max(getHeight(b->left), getHeight(b->right)) + 1;
    return b;
}
Node *leftRotate(Node *b)
{
    Node *a = b->right;
    Node *temp = a->left;

    a->left = b;
    b->right = temp;

    b->height = max(getHeight(b->left), getHeight(b->right)) + 1;
    a->height = max(getHeight(a->left), getHeight(a->right)) + 1;
    return a;
}
bool isLeaf(Node *node)
{
    if (node->left == NULL && node->right == NULL)
    {
        return true;
    }
    return false;
}
Node *inOrderPredecessor(Node *node)
{
    node = node->left;
    while (node->right != NULL)
    {
        node = node->right;
    }
    return node;
}
Node *inOrderSuccessor(Node *node)
{
    node = node->right;
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}
// when i perform insertion in AVL tree then it sometimes growing tree in one direction only and | balance factor | >= 1 .we use below insertion with rotation to manage its balance factor

Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
        // return root;
    }

    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
        // return root;
    }
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBalanceFactor(root);
    if (bf > 1 && data < root->left->data)
    {
        // L-L Rotation
        return rightRotate(root);
    }
    else if (bf < -1 && data > root->right->data)
    {
        // R-R Rotation
        return leftRotate(root);
    }
    else if (bf > 1 && data > root->left->data)
    {
        // L-R Rotation
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    else if (bf < -1 && data < root->right->data)
    {
        // R-L Rotation
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
// when i perform deletion in AVL tree then it sometimes reach | balance factor | >= 1 .we use below deletion with rotation to manage its balance factor.
Node *deleteNode(Node *root, int data)
{
    // BASE FOR RECURSION START
    if (root == NULL)
    {
        // node is empty or null
        return NULL;
    }
    if (root->left == NULL && data == root->data)
    {
        // data at non-leaf node & only one right child
        Node *temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL && data == root->data)
    {
        // data at non-leaf node & only one left child

        Node *temp = root->left;
        free(root);
        return temp;
    }
    else if (root->left == NULL && root->right == NULL && data == root->data)
    {
        // data at leaf node
        free(root);
        return NULL;
    }
    // BASE FOR RECURSION END
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        // this case work only and only when node to be deleted have two child
        Node *ipre, *ipost;
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
    // BF checking start
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBalanceFactor(root);
    if (bf > 1 && data < root->left->data)
    {
        // L-L Rotation
        return rightRotate(root);
    }
    else if (bf < -1 && data > root->right->data)
    {
        // R-R Rotation
        return leftRotate(root);
    }
    else if (bf > 1 && data > root->left->data)
    {
        // L-R Rotation
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    else if (bf < -1 && data < root->right->data)
    {
        // R-L Rotation
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
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
    return createNode(-1);
}
int main()
{
    Node *root = NULL;

    // insertion in AVL

    // root = insertNode(root, 1);
    // root = insertNode(root, 2);
    // root = insertNode(root, 3);
    // root = insertNode(root, 4);
    // root = insertNode(root, 6);
   for (int i = 0; i < 15; i++)
   {
       root = insertNode(root, i);

   }
   
    // deletion in AVL
    // root=deleteNode(root,1);
    // root=deleteNode(root,4);
    // root=deleteNode(root,1);
    Node *node=recursiveSearch(root,6);
    printf("Searching Result: %d\n",node->data);
    printf("preOrder traversal: ");
    preOrder(root);
    printf("\n");
    printf("inOrder traversal: ");
    inOrder(root);
    printf("\n");
    return 0;
}
