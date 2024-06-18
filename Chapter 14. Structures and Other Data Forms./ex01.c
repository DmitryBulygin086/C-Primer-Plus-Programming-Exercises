// Redo Review Question 5, but make the argument the spelled-out name of the month
// instead of the month number. (Don’t forget about strcmp().) Test the function in a
// simple program.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MONTH_NAME_LEN 10
#define MONTHS 12
#define DAYS_IN_YEAR 365
#define DAYS_IN_LEAP_YEAR 366

struct month {
    char name[10];
    char abbrev[4];
    unsigned  days;
    unsigned  month_number;
};

struct month months[12] = {
    {"January", "jan", 31, 1},
    {"February", "feb", 28, 2},
    {"March", "mar", 31, 3},
    {"April", "apr", 30, 4},
    {"May", "may", 31, 5},
    {"June", "jun", 30, 6},
    {"July", "jul", 31, 7},
    {"August", "aug", 31, 8},
    {"September", "sep", 30, 9},
    {"October", "oct", 31, 10},
    {"November", "nov", 30, 11},
    {"December", "dec", 31, 12}
};
void days_up_to_month(char *month_name);
char * s_gets(char *st, int n);

int main(void)
{
    char month_name[MONTH_NAME_LEN];
   
    bool found = false;
    while (1)
    {
        int total = 0;
        printf("Enter a month name(empty line to quit): ");
        s_gets(month_name, MONTH_NAME_LEN);
        if (month_name[0] == '\0')
        {
            break;
        }

        days_up_to_month(month_name);
    }
}

void days_up_to_month(char *month_name)
{
    int total = 0;
    bool found = false;
    for (int index = 0; index < MONTHS; index++)
    {
        total += months[index].days;
        if (strcmp(month_name, months[index].name) == 0)
        {
            found = true;
            break;
        }
    }
    if (!found)
    {
        fprintf(stderr,"%s is not a valid month name.\n", month_name);
        printf("Please try again.\n");
    }
    else 
    {
        printf("%s has %d days up to it.\n", month_name, total);
    }
}


char * s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
        {
            *find = '\0';
        }
        else
        {
            while (getchar()!= '\n')
            {
                continue;
            }
        }
    }
    return ret_val;
}