/* list.c -- functions supporting list operations  */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* local function prototype  */
static void CopyToNode(Item item, Node * pnode);

/* interface functions  */
/* set the list to empty  */
void InitializeList(List * plist )
{
    plist->items = 0;
}

/* returns true if list is empty  */
bool ListIsEmpty(const List * plist)
{
    if (plist->items == 0)
        return true;
    else 
        return false;
}

/* returns true if list is full  */
bool ListIsFull(const List * plist)
{
    return (plist->items == MAXSIZE);
}

/* returns number of nodes  */
unsigned int ListItemCount(const List * plist)
{
   return plist->items;
}

/* creates node to hold item and adds it to the end of */
/* the list pointed to by plist (slow implementation )*/
bool AddItem(Item item, List * plist)
{
    if (plist->items >= MAXSIZE)
    {
        return false;
    }
    else 
    {
        plist->entries[plist->items] = item;
        plist->items++;
        return true;
    }
}

/* visit each node and execute function pointed to by pfun  */
void Traverse(const List * plist, void (*pfun)(Item item))
{
    for (int i = 0; i < plist->items; i++)
    {
        (*pfun)(plist->entries[i]);
    }
}

/* free memory allocated by malloc() */
/* set list pointer to NULL   */
void EmptyTheList(List * plist)
{
    plist->items = 0;
}

/* local funciton definition  */
/* copies an item into a node  */
static void CopyToNode(Item item, Node * pnode )
{
    pnode->item = item;  /* structure copy  */
}