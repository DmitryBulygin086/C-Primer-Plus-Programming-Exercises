/* manybook.c -- multiple book inventory */
#include <stdio.h>
#include <string.h>
char * s_gets(char * st, int n);
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100          /* maximum number of books */
struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
void print_in_order_entered(struct book * library, int count);
void print_in_alphabetical_order(struct book * library, int count);
void print_in_order_of_increased_value(struct book * library, int count);
int main(void)
{
    struct book library[MAXBKS];  /* array of book structures  */
    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
          && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;    /* clear input line  */
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }

    if (count > 0)
    {
        print_in_order_entered(library, count);  /* print the list  */
        putchar('\n');
        print_in_alphabetical_order(library, count);
        putchar('\n');
        print_in_order_of_increased_value(library, count);
        putchar('\n');

    }
    else    
    {
        printf("No books? Too bad.\n");
    }

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');    // look for newline
        if (find)              // if the address is not NULL,
            *find = '\0';         // place a null character there
        else 
            while (getchar() != '\n')
                continue;           // dispose of rest of line
    }
    return ret_val;
}

void print_in_order_entered(struct book * library, int count)
{
    int index;
    printf("Here is the list of your books in order entererd:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                   library[index].author, library[index].value);
}

void print_in_alphabetical_order(struct book * library, int count)
{
    struct book temp;
    for (int i = 0; i < count-1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (strcmp(library[i].title, library[j].title) > 0)
            {
                temp = library[i];
                library[i] = library[j];
                library[j] = temp;
            }
        }
    }

    printf("Here is the list of your books in alphabetical order:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%s by %s: $%.2f\n", library[i].title,
               library[i].author, library[i].value);
    }
}

void print_in_order_of_increased_value(struct book * library, int count)
{
    struct book temp;
    for (int i =0; i < count-1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (library[i].value > library[j].value)
            {
                temp = library[i];
                library[i] = library[j];
                library[j] = temp;
            }
        }
    }

    printf("Here is the list of your books in order of increased value:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%s by %s: $%.2f\n", library[i].title, library[i].author, library[i].value);
    }
}