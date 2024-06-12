// Write a function called is_within() that takes a character and a string pointer as its two
// function parameters. Have the function return a nonzero value (true) if the character is
// in the string and zero (false) otherwise. Test the function in a complete program that uses
// a loop to provide input values for feeding to the function.

#include <stdio.h>
#include <stdbool.h>
#define STLEN 20
// Returns true if ch is in st, zero otherwise
bool is_within(char ch, char *st);
void s_gets(char *st, int n);
void flush_input_buffer(void);
int main(void)
{
    char string[STLEN];
    char ch;

    puts("Enter a string(empty line to quit):");
    s_gets(string, STLEN);
    while(string[0] != '\0')
    {

        puts("Enter a character which you want to find in string:");
        ch = getchar();
        flush_input_buffer();
       
    
        if (is_within(ch, string))
        {
            printf("%c is found in %s\n", ch, string);
        }
        else 
        {
            printf("%c is not found in %s\n", ch, string);
        }
        puts("Enter a string(empty line to quit):");
        s_gets(string, STLEN);
    }
    return 0;
}

bool is_within(char ch, char *st)
{
    while(*st != '\0')
    {
        if (*st == ch)
        {
            return true;
        }
        st++;
    }
    return false;
}

void s_gets(char *st, int n)
{
    if (fgets(st, n, stdin) != NULL)
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
    {
        continue;
    }
}