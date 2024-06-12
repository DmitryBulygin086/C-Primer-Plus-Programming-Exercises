// Write a function that takes a string as an argument and removes the spaces from the
// string. Test it in a program that uses a loop to read lines until you enter an empty line.
// The program should apply the function to each input string and display the result.

#include <stdio.h>
#include <string.h>
#define STRLEN 30

void clear_spaces(char *string);

void s_gets(char *st, int n);

int main(void)
{
    char string[STRLEN];
    while(1)
    {
        puts("Enter input(empty line to quit):");
        s_gets(string, STRLEN);
        if (string[0] == '\0')
            break;

        clear_spaces(string);

        puts("Here is your string without spaces:");
        puts(string);
    }
}

void clear_spaces(char *string)
{
    unsigned spaces_found = 0;

    while(1)
    {   
            if (*string == ' ')
            {
                spaces_found++; // collect spaces
            }
            else 
            {
                *(string - spaces_found) = *string;     // then remove spaces
            }

            if (*string == '\0')
                break;
            string++;
    }
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