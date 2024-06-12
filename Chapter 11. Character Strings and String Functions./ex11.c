// Write a program that reads in up to 10 strings or to EOF, whichever comes first. Have it
// offer the user a menu with five choices: print the original list of strings, print the strings
// in ASCII collating sequence, print the strings in order of increasing length, print the
// strings in order of the length of the first word in the string, and quit. Have the menu
// recycle until the user enters the quit request. The program, of course, should actually
// perform the promised tasks.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define STRLEN 30
#define STR_COUNT 10

// aPS: array of pointers to strings
char * s_gets(char *st, int n);

void print_menu(void);

// Prints array of strings
void printArrOfStrs(int arrlen, char *aPS[arrlen]);

char getchoice(void);

// Sort strings in aPS in ASCII collating sequence
void sort_ASCII(int arrlen,char *aPS[arrlen]);

// Sort strings in aPS in order of increasing length
void sortIncrLen(int arrlen, char *aPS[arrlen]);

// Returns length of first word in str
int fWLen(char *str);

// Sort strings in aPS in order of the increasing lenght of the first word in the string
void sortFWLen (int arrlen, char *aPS[arrlen]);

int main(void)
{
    char strings[STR_COUNT][STRLEN];
    char *aPS[STR_COUNT];   // array of pointers to strings
    char *success;   
    char choice;
    bool exit_flag = false;

    for(int count = 0; count < STR_COUNT; count++)
    {
        aPS[count] = strings[count];
    }


    while (1)
    {
        int count = 0;
        puts("Enter up to 10 strings(empty line to stop):");
        for(count = 0; count < STR_COUNT; count++)
        {
            printf("%d: ", count + 1);
            success = s_gets(aPS[count], STRLEN);

            if (!success)
            {
                break;
            }

            
        }
        putchar('\n');
        while (1)
        {
            print_menu();
            choice = getchoice();

            switch(choice)
            {
                case '1' :
                    puts("Original list:");
                    printArrOfStrs(count, aPS);
                    break;
                case '2' :
                    sort_ASCII(count, aPS);
                    puts("List sorted in ASCII collating sequence:");
                    printArrOfStrs(count, aPS);
                    break;
                case '3' :
                    sortIncrLen(count, aPS);
                    puts("List sorted by increasing length:");
                    printArrOfStrs(count, aPS);
                    break;
                case '4' :
                    sortFWLen(count, aPS);
                    puts("List sorted in order of increasing length of first word:");
                    printArrOfStrs(count, aPS);
                    break;
                case '5' :
                {
                    exit_flag = true;
                    break;
                }
                default :
                    puts("Invalid input. Try again.");
                    continue;
            }
            if (exit_flag)
            {
                break;
            }
            break;
        }
        if (exit_flag)
        {
            break;
        }
    }
    puts("Bye");
    return 0;
}

/* COMMON CASE    */
char * s_gets(char *st, int n)
{
    char *ret_val;
    ret_val = fgets(st, n, stdin);
    
    while (*st != '\0')
    {
        if (*st == '\n')
        {
            *st = '\0';
            break;
        }
        st++;
    }
    
    return ret_val;
}

void print_menu(void)
{
    printf("1) Print the original list of strings.\n");
    printf("2) Print the strings in ASCII collating sequence.\n");
    printf("3) Print the strings in order of increasing length.\n");
    printf("4) Print the strings in order of the length of the first word in the string.\n");
    printf("5) Quit.\n");
    printf("Enter the number corresponding to your choice: ");
}

char getchoice(void)
{
    char ch;
    ch = getchar();
    while (getchar() != '\n')
    {
        continue;
    }
    return ch;
}

void printArrOfStrs(int arrlen ,char *aPS[arrlen])
{
    //printf("Original list:\n");
    for (int count = 0; count < arrlen; count++)
    {
        printf("%d: %s\n", count + 1, aPS[count]);
    }
}




/* CASE 2  */
void sort_ASCII(int arrlen, char *aPS[arrlen])
{
    char *temp_str;
    for (int index = 0; index < arrlen - 1; index++)
    {
        for (int index2 = index+1; index2 < arrlen; index2++)
        {
            if (strcmp(/*tolower*/(aPS[index]), /*tolower*/(aPS[index2])) > 0)
            {
                temp_str = aPS[index];
                aPS[index] = aPS[index2];
                aPS[index2] = temp_str;
            }
        }
    }

}



/* CASE 3      */
void sortIncrLen(int arrlen, char *aPS[arrlen])
{
    char *temp_str;
    for (int index = 0; index < arrlen - 1; index++)
    {
        for (int index2 = index + 1; index2 < arrlen; index2++)
        {
            if (strlen(aPS[index]) > strlen(aPS[index2]))
            {
                temp_str = aPS[index];
                aPS[index] = aPS[index2];
                aPS[index2] = temp_str;
            }
        }
    }
}



/*  CASE 4       */
int fWLen(char *str)
{
    int len = 0;

    while (isspace(*str))
    {
        str++;
    }
    while(!isspace(*str))
    {
        len++;
        str++;
    }
    return len;
}

void sortFWLen(int arrlen, char *aPS[arrlen])
{
    char *temp_str;
    for (int index = 0; index < arrlen - 1; index++)
    {
        for (int index2 = index + 1; index2 < arrlen; index2++)
        {
            if (fWLen(aPS[index]) > fWLen(aPS[index2]))
            {
                //str_exchange(aPS[index], aPS[index2]);
                temp_str = aPS[index];
                aPS[index] = aPS[index2];
                aPS[index2] = temp_str;
            }
        }
    }
}