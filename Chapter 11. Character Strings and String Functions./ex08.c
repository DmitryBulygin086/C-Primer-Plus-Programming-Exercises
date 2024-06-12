// Write a function called string_in() that takes two string pointers as arguments. If
// the second string is contained in the first string, have the function return the address
// at which the contained string begins. For instance, string_in("hats", "at") would
// return the address of the a in hats. Otherwise, have the function return the null pointer.
// Test the function in a complete program that uses a loop to provide input values for
// feeding to the function.

#include <stdio.h>
#include <string.h>
#define STRLEN 30

char *string_in(char *string, char *substring);
void s_gets(char *st, int n);
int main(void)
{
    char string[STRLEN];
    char substring[STRLEN];
    char *addr;
    while(1)
    {
        puts("Enter a string:");
        s_gets(string, STRLEN);
        if (string[0] == '\0')
        {
            break;
        }

        puts("Enter a substring:");
        s_gets(substring, STRLEN);

        if ((addr = string_in(string, substring)) != NULL)
        {
            printf("%s start to contains in %s at index %d\n", substring, string, addr - &string[0]);
        }
        else 
        {
            printf("%s does not contains in %s.\n", substring, string);
        }
    }
}

char *string_in(char *string, char *substring)
{
    int i = 0;
    while(*string != '\0')
    {
        while(string[i] == substring[i])
        {
            i++;
            if (substring[i] == '\0')
            {
                return string;
            }
        }
        string++;
    }
    return NULL;
}

void s_gets(char *st, int n)
{
    char *rv;
    rv = fgets(st, n, stdin);
    if (rv)
    {
        while(*st != '\0')
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