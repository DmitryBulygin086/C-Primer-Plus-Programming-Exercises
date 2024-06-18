// Write a program that prompts the user to enter the day, month, and year. The month
// can be a month number, a month name, or a month abbreviation. The program then
// should return the total number of days in the year up through the given day. (Do take
// leap years into account.)

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MONTH_NAME_LEN 20
#define MONTHS 12
#define FEB 1
#define JAN 0

struct month {
    char name[10];
    char abbrev[4];
    int  days;
    char month_number[3];
};

struct month months[12] = {
    {"January", "jan", 31, "1"},
    {"February", "feb", 28, "2"},
    {"March", "mar", 31, "3"},
    {"April", "apr", 30, "4"},
    {"May", "may", 31, "5"},
    {"June", "jun", 30, "6"},
    {"July", "jul", 31, "7"},
    {"August", "aug", 31, "8"},
    {"September", "sep", 30, "9"},
    {"October", "oct", 31, "10"},
    {"November", "nov", 30, "11"},
    {"December", "dec", 31, "12"}
};

char * s_gets(char *st, int n);
void eatline(void);
int main(void)
{
    int day;
    char month[MONTH_NAME_LEN];
    bool valid_month = false;
    bool leap_year = false;
    bool valid_day = false;
    int year;
    int total_days;
    int important_index;
    while (1)
    {
        total_days = 0;
        get_day(&day);
        if (day == 0)
            break;
        while (1)
        {
           
            printf("Enter the month: ");
            s_gets(month, MONTH_NAME_LEN);
            for (int index = 0; index < MONTHS; index++)
            {
                if (strcmp(month, months[index].name) == 0 ||
                    strcmp(month, months[index].abbrev) == 0 ||
                    strcmp(month, months[index].month_number) == 0)
                {
                    if (day > months[index].days)
                    {
                        fprintf(stderr, "Invalid input.\n");
                        printf("%s have only %d days.\n", months[index].name, months[index].days);
                        valid_day = false;
                        break;
                    }
                    valid_month = true;
                    valid_day = true;
                    important_index = index;
                    break;
                }
               
            }
            if (!valid_month)
            {
                fprintf(stderr, "Invalid month name.\nTry again.\n");
                continue;
            }
            
            break;
        }
        if (!valid_day)
        {
            continue;
        }

        get_year(&year);

        while (1)
        {
            if (year % 100 == 0)
            {
                if (year % 400 == 0)
                    months[FEB].days = 29;
                break;
            }
            if (year % 4 == 0)
            {
                months[FEB].days = 29;
                break;
            }
            break;
        }
        if (important_index != JAN)
        {
            for (int index = 0; index < MONTHS; index++)
            {
                total_days += months[index].days;
                if (strcmp(month, months[index+1].name) == 0 ||
                    strcmp(month, months[index+1].abbrev) == 0 ||
                    strcmp(month, months[index+1].month_number) == 0)
                {  
                    break;
                }
            }
        }
        total_days += day;

        printf("Total days in %d year up to %d %s is %d.\n", year, day, 
             months[important_index].name, total_days);
    }
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

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

void eatline(void)
{
    while (getchar() != '\n')
    {
        continue;
    }
}

void get_day(int * day)
{
    printf("Enter the day(0 to quit): ");
        while (scanf("%d", &day) != 1 || *day < 0 || *day > 31)
        {
            eatline();
            fprintf(stderr, "Invalid input.\n");
            printf("Try again.\n");
            printf("Enter the day: ");
        }
        eatline();
}

void get_year(int * year)
{
    printf("Enter the year: ");
        while (scanf("%d", &year) != 1 || *year < 0)
        {
            eatline();
            fprintf(stderr, "Invalid input.\n");
            printf("Try again.\n");
            printf("Enter the year: ");
        }
        eatline();
}