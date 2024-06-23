// Suppose list.h (Listing 17.3) uses the following definition of a list:
// #define MAXSIZE 100
// typedef struct list
// {
// Item entries[MAXSIZE];
// int items;
// } List;
// /* array of items
// */
// /* number of items in list */
// Rewrite the list.c (Listing 17.5) functions to fit this definition and test the resulting
// code with the films3.c (Listing 17.4) program.

/* films3.c -- using an ADT-style linked list  */
/* compile with list.c */
#include <stdio.h>
#include <stdlib.h>    /* prototype for exit() */
#include <string.h>
#include "list.h"      /* defines List, Item   */
void showmovies(Item item);
char * s_gets(char * st, int n);
int main(void)
{
    List movies;
    Item temp;

    /* ititialize */
    InitializeList(&movies);
    if (ListIsFull(&movies))
    {
        fprintf(stderr, "No memory avaliable! Bye!\n");
        exit(EXIT_FAILURE);
    }

/* gather and store   */
    puts("Enter first movie title:");
    while(s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
    {
        puts("Enter your rating <0-10>:");
        scanf("%d", &temp.rating);
        while(getchar() != '\n')
            continue;
        if (AddItem(temp, &movies) == false)
        {
            fprintf(stderr, "Problem allocating memory\n");
            break;
        }
        if (ListIsFull(&movies))
        {
            puts("The list is now full.");
            break;
        }
        puts("Enter next movie title (empty line to stop):");
    }

/* display      */
    if (ListIsEmpty(&movies))
        printf("No data entered. ");
    else 
    {
        printf("Here is the movie list:\n");
        Traverse(&movies, showmovies);
    }
    printf("You entered %d movies.\n", ListItemCount(&movies));

    /* clean up   */
    EmptyTheList(&movies);
    printf("Bye!\n");

    return 0;
}

void showmovies(Item item)
{
    printf("Movie: %s  Rating: %d\n", item.title,
           item.rating);
}
char * s_gets(char * st, int n)
{
    char * ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar()!= '\n')
                continue;
    }
    return ret_val;
}