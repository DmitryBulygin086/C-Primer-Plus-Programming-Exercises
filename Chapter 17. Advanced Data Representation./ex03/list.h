/* list.h -- header file for a simple list type  */
#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>    /* C99 feature  */
#define MAXSIZE 100

/*  program-specific declarations  */

#define TSIZE  45   /* size of array to hold title  */
struct film 
{
    char title[TSIZE];
    int rating;
};

/* general type definitions  */

typedef struct film Item;

typedef struct node 
{
    Item item;
    struct node * next;
} Node;

// Old ver
// typedef Node * List;

// New ver
typedef struct list
{
    Item entries[MAXSIZE];
    int items;
} List;

/* function prototypes  */

/* operation:        initialize a list  */
/* preconditions:     plist points to a list  */
/* postconditions:    the list is initialized to empty  */
void InitializeList(List * plist);

/* operation:        determine if list is empty   */
/*                   plist points to an initialized list  */
/* postconditions;  function returns True if list
 */
bool ListIsEmpty(const List * plist);

/* operation:     determine if list is full  */
/*                plist points to an initialized list  */
/* postconditions:  function return True if list is full  */
/*                   and returns False otherwise  */
bool ListIsFull(const List *plist);

/* operation:      determine number of items in list  */
/*                 plist points to an initialized list  */
/* postconditions:  function rturn number of items in list  */
unsigned int ListItemCount(const List * plist);

/* operation:      add item to end of list   */
/* preconditions:   item is an item to be added to list  */
/*                   plist points to an initialized  list  */
/* postconditions;   if possible, function adds item to end  */
/*                    of list and  returns True; otherwise the  */
/*                  function return False   */
bool AddItem(Item item, List * plist);

/* operation:      apply a fun
t and has no return valuue  */
/* postcondition: the function pointed to by pfun is  */
/*               executed once for each item in the list  */
void Traverse(const List *plist, void (*pfun)(Item item));

/* operation:       free allocated meemory, if any   */
/*                  plist points to an initialized list   */
/* postconditions:  any memory allocated for the list is freed  */
/*                  and the list is set to empty   */
void EmptyTheList(List * plist );

#endif

