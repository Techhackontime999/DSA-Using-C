#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};

void traversal(struct Node *head)
{

  struct Node *ptr = head->next;
  // printf("%d ", ptr->data);
  // ptr = ptr->next;
  // while (ptr != head->next)
  // {
  //   printf("%d ", ptr->data);
  //   ptr = ptr->next;
  // }

  while (ptr->next != head->next)
  {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }

  printf("%d ", ptr->data);
  ptr = ptr->next;
  return;
}
void insertAfterNode(struct Node *head, struct Node *node, int data)
{
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  struct Node *p = node->next;
  ptr->data = data;
  // below is work for both if node->next != start or node->next=start
  node->next = ptr;
  ptr->next = p;
  return;
}
void insertAtIndex(struct Node *head, int data, int idx)
{
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  ptr->data = data;
  struct Node *p = head->next;
  struct Node *q = p->next;

  int i = 0;
  do
  {
    p = p->next;
    i++;
  } while (p->next != head->next);

  idx = idx % (i + 1);

  i = 0;
  if (idx != 0)
  {
    p = head->next;

    while (i != idx - 1)
    {
      p = p->next;
      q = q->next;
      i++;
    }
    p->next = ptr;
    ptr->next = q;

    return;
  }
  else
  {

    ptr->next = head->next;

    head->next = ptr;
    p->next = ptr;

    return;
  }
}
void deleteAtIndex(struct Node *head, int idx)
{
  struct Node *p = head->next;
  struct Node *q = p->next;

  int i = 0;
  do
  {
    p = p->next;
    i++;
  } while (p->next != head->next);

  idx = idx % (i + 1);

  if (idx != 0)
  {
    i = 0; // i is changed here
    p = head->next;
    while (i != idx - 1)
    {
      p = p->next;
      q = q->next;
      i++;
    }
    p->next = q->next;
    free(q);

    return;
  }
  else
  {
    // here we not change i because i is at maximum index after it they reach to first
    q = head->next;
    head->next = q->next;
    p->next = head->next;
    free(q);

    return;
  }
}
void deleteAfterNode(struct Node *head, struct Node *node)
{
  struct Node *p = node;
  struct Node *q = node->next;
  if (node->next != head->next)
  {
    p->next = q->next;
    free(q);
    return;
  }
  else
  {
    // we need to update next starting node because printing is start from starting node.
    p->next = q->next;
    head->next = p->next;
    free(q);
    return;
  }
}
void deleteNode(struct Node *head, struct Node *node)
{
  // this function delete that node and return new node in place of that.
  // here we assume node is my starting node
  struct Node *p = node;
  struct Node *q = node->next;
 
  do
  {
    p = p->next;
    q = q->next;
  } while (p->next != node);
  p->next = q->next;
  if (node == head->next)
  {
    head->next = q->next;
  }
  
  free(q);

  return;
}
int main()
{
  // here head is an empty node thats helps to enter in a circular linked list.
  struct Node *head, *second, *third, *fourth;
  head = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));
  fourth = (struct Node *)malloc(sizeof(struct Node));

  head->next = second;
  second->data = 2;
  second->next = third;
  third->data = 3;
  third->next = fourth;
  fourth->data = 4;
  fourth->next = second;
  // insertAfterNode(head,second,50);
  // insertAfterNode(head,third,50);
  // insertAfterNode(head,fourth,50);
  // insertAtIndex(head, 50, 0);
  // insertAtIndex(head, 50, 1);
  // insertAtIndex(head, 50, 5);
  // deleteAtIndex(head,0);
  // deleteAtIndex(head,1);
  // deleteAtIndex(head,2);
  // deleteAfterNode(head, second);
  // deleteAfterNode(head, third);
  // deleteAfterNode(head, fourth);
  // deleteNode(head, third);
  // deleteNode(head, fourth);
  // deleteNode(head, second);


  traversal(head);

  return 0;
}
