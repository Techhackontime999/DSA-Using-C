#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Listitem
{
    char *item;

} Listitem;
typedef struct List
{
    Listitem *items;
    int size;
} List;
typedef struct ListArray
{
    List *list;
    int size;
} ListArray;
int listlen(List *list)
{
    int len = list->size;

    return len;
}
List *listCreate(int size)
{
    List *list = (List *)malloc(sizeof(List));
    // (*list).item=(Listitem *) malloc(size * sizeof(Listitem));
    list->items = (Listitem *)malloc(size * sizeof(Listitem));
    // (*list).size = size;
    // list->items[0].item = "sumit";
    list->size = size;
    return list;
}
ListArray* listArrayCreate(int size)
{
    ListArray *listarr = (ListArray *)malloc(sizeof(ListArray));
    listarr->list = (List *) malloc(size * sizeof(List));
    for (int i = 0; i < size; i++)
    {
        listarr->list[i].items = NULL;
        listarr->list[i].size = 0;
    }
    // listarr->list->items = (Listitem *)malloc(listlen(listarr->list) * sizeof(Listitem));
    listarr->size = size;

    return listarr;
}
void printList(List *list)
{
    int size = list->size;
    for (int i = 0; i < size; i++)
    {
        printf("%s\n", list->items[i].item);
    }

    return;
}
Listitem listget(List *list, int idx)
{
    return list->items[idx];
}
void listappend(List *list, char *element)
{

    int size = list->size;
    Listitem *tmp = (Listitem *)realloc(list->items, (size + 1) * sizeof(Listitem));
    if (list->items != NULL)
    {

        list->items = tmp;
        list->items[size].item = element;

        list->size = size + 1;
    }
    else
    {
        // Handle realloc failure, do not update list->items
        printf("Allocation faliure...\n");
    }
    free(tmp);

    return;
}
void listDelete(List *list, int idx)
{

    Listitem *tmp = (Listitem *)realloc(list->items, (list->size - 1) * sizeof(Listitem));
    if (list->items != NULL)
    {
        for (int i = idx; i < list->size - 1; i++)
        {
            list->items[i] = list->items[i + 1];
        }
        list->items = tmp;
        list->size = list->size - 1;
    }
    else
    {
        // Handle realloc failure, do not update list->items
        printf("Allocation faliure...\n");
    }
    free(tmp);
    return;
}
void listInsert(List *list, int idx, char *element)
{
    Listitem *tmp = (Listitem *)realloc(list->items, (list->size + 1) * sizeof(Listitem));

    if (list->items != NULL)
    {
        list->size = list->size + 1;

        list->items = tmp;
        for (int i = list->size - 1; i >= idx; i--)
        {
            list->items[i + 1] = list->items[i];
        }
        list->items[idx].item = element;
    }
    else
    {
        // Handle realloc failure, do not update list->items
        printf("Allocation faliure...\n");
    }
    free(tmp);
    return;
}
List *merge2List(List *firstlist, List *seclist)
{
    int firstSize = listlen(firstlist);
    int secSize = listlen(seclist);
    List *newList = listCreate(firstSize + secSize);
    newList->size = 0;
    int i;
    for (i = 0; i < firstSize; i++)
    {
        newList->items[i] = firstlist->items[i];
    }
    int j;
    for (j = 0; j < secSize; j++, i++)
    {
        newList->items[i] = seclist->items[j];
    }
    newList->size = listlen(firstlist) + listlen(seclist);

    return newList;
}
// merge twolist as callback.
//  List *mergeList(List *firstlist, List *seclist)
//  {
//      List *(*ptr)(List *, List *);
//      ptr = merge2List;
//      ptr(firstlist, seclist);
//  }

// merge all list
List *mergeAllList(ListArray *arr, int size)
{
    List *newList = arr[0].list;
    newList->size = listlen(newList);

    for (int i = 1; i < size; i++)
    {
        newList = merge2List(newList, arr[i].list);
        newList->size = newList->size + arr[i].size;
    }

    return newList;
}
int main()
{

    // List *ptr = listCreate(4);

    // ptr->items[0].item = "sohan1";
    // ptr->items[1].item = "rakesh1";
    // ptr->items[2].item = "sohan";
    // ptr->items[3].item = "rakesh";
    // printf("length of list: %d\n", listlen(ptr));

    // listappend(ptr, "mukesh");
    // listappend(ptr, "suresh");

    // listappend(ptr, "chanchal");
    // listappend(ptr, "AMIT");

    // printf("length of list: %d\n", listlen(ptr));

    // printf("%s\n", listget(ptr, 0));
    // printf("%s\n", listget(ptr, 1));
    // printf("%s\n", listget(ptr, 2));
    // printf("%s\n", listget(ptr, 3));
    // printList(ptr);
    // listDelete(ptr, 1);
    // printf("\n");
    // printList(ptr);
    // printf("length of list: %d\n", listlen(ptr));
    // listInsert(ptr, 1, "mohan lal");

    // printList(ptr);
    // printf("length of list: %d\n", listlen(ptr));

    // printList(ptr,10);
    // printf("%s", listget(ptr, 1));
    // free(ptr);

    // add two list
    List *firstlist = listCreate(4);
    List *seclist = listCreate(4);
    List *thirdlist = listCreate(4);

    firstlist->items[0].item = "prince";
    firstlist->items[1].item = "rakesh";
    firstlist->items[2].item = "suraj";
    firstlist->items[3].item = "pankaj";
    seclist->items[0].item = "raman";
    seclist->items[1].item = "rajesh";
    seclist->items[2].item = "ramesh";
    seclist->items[3].item = "mohan";
    thirdlist->items[0].item = "yash";
    thirdlist->items[1].item = "nayan";
    thirdlist->items[2].item = "ramesh01";
    thirdlist->items[3].item = "atul";
    // printf("list1...\n");
    // printList(firstlist);
    // printf("list2...\n");

    // printList(seclist);
    // printf("Merged 2 list...\n");
    // List *newlist = merge2List(firstlist, seclist);
    // printList(newlist);
    int size = 3;
    ListArray *arr = listArrayCreate(size);
    arr[0].list = firstlist;
    arr[1].list = seclist;
    arr[2].list = thirdlist;
    //   printf("Merged 2 list...\n");
    // List *newlist = merge2List(firstlist, seclist);
    // List *newlist = mergeAllList(arr, size);
    // printf("Merged All list...\n");
    // printf("\n");
    // printf("length of list: %d\n", listlen(newlist));

    //  listappend(newlist,"mohanlal");
    //  listappend(newlist,"mohanlal");
    //  listappend(newlist,"mohanlal");

    // printf("length of list: %d\n", listlen(newlist));
    // printList(newlist);

    // listDelete(newlist, 5);
    // printList(newlist);
    // printf("\n");
    printList(firstlist);

    listappend(firstlist,"suraj");
    printList(firstlist);
    free(firstlist);
    free(seclist);
    // free(newlist);
     free(firstlist->items);
    free(seclist->items);
    // free(newlist->items);

    return 0;
}