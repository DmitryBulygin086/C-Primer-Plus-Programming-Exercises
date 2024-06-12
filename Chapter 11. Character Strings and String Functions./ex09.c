// Write a function that replaces the contents of a string with the string reversed. Test the
// function in a complete program that uses a loop to provide input values for feeding to
// the function.

#include <stdio.h>
#define STRLEN 30

void reverse(char *st);
void s_gets(char *st, int n);
int main(void)
{
    char string[STRLEN];

    while (1)
    {
        puts("Enter a string:");
        s_gets(string, STRLEN);

        if (string[0] == '\0')
            break;
        
        reverse(string);

        puts("string after reverse:");
        puts(string);
    }
}

void reverse(char *st)
{
    char *end = st;
    char temp;

    while (*(end + 1) != '\0')
    {
        end++;
        
    }   
    
    while (st < end)
    {
        temp = *end;
        *end = *st;
        *st = temp;

        st++;
        end--;
    }
}

void s_gets(char *st, int n)
{
    if (fgets(st, n , stdin) != NULL)
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