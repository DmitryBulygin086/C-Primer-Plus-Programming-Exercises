// Design and test a function that searches the string specified by the first function
// parameter for the first occurrence of a character specified by the second function
// parameter. Have the function return a pointer to the character if successful, and a null
// if the character is not found in the string. (This duplicates the way that the library
// strchr() function works.) Test the function in a complete program that uses a loop to
// provide input values for feeding to the function.

#include <stdio.h>
#define STLEN 20
char * findch(char *target, char ch);
char * s_gets(char *st, int n);
void flush_input_buffer(void);
int main(void)
{
    char string[STLEN];
    char ch;
    char *rv;   // return value of findch()
    while(1)
    {
        puts("Enter a string(empty line to quit):");
        s_gets(string, STLEN);
        //flush_input_buffer();
        if (string[0] == '\0')
            break;
        puts(string);
        puts("Enter a character which you want to find in string:");
        while ((ch = getchar()) == EOF || ch == '\n')
        {
            if (ch == '\n')
                continue;

            puts("Invalid input.");
            puts("Enter a character which you want to find in string:");
        }
        flush_input_buffer();
        rv = findch(string, ch);
        if (rv != NULL)
        {
            printf("%c is found at %d index in string\n", ch, rv - &string[0]);
        }
        else 
            printf("%c not found in string\n", ch);
    }
    return 0;
}

char *findch(char *target, char ch)
{
    while (*target != '\0')
    {
        if (*target == ch)
            return target;
        target++;
    }
    return NULL;
}

char * s_gets(char *st, int n)
{
    char *ret_val;
    ret_val = fgets(st, n, stdin);
    if (ret_val != NULL)
    {
        while (*st != '\0')
        {
            if (*st == '\n')
            {
                *st = '\0';
                break;
            }
            st++;
        }
    }  
}

void flush_input_buffer(void)
{
    while (getchar() != '\n')
        continue;
}