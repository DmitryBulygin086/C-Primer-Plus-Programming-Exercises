// Using if else statements, write a program that reads input up to #, replaces each period
// with an exclamation mark, replaces each exclamation mark initially present with two
// exclamation marks, and reports at the end the number of substitutions it has made.

#include <stdio.h>

int main(void)
{
    char ch;
    unsigned int subs_ct = 0;

    printf("enter input (# to stop):\n");
    while ((ch = getchar()) != '#')
    {
        if (ch == '.')
        {
            putchar('!');
            subs_ct++;
        }
        else if (ch == '!')
        {
            putchar('!');
            putchar('!');
            subs_ct++;
        }
        else
            putchar(ch);
    }
    putchar('\n');
    printf("subs_ct = %d\n", subs_ct);
    return 0;
}