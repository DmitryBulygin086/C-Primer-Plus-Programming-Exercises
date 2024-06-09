// Write a program that reads input until encountering the # character and then reports
// the number of spaces read, the number of newline characters read, and the number of all
// other characters read.

#include <stdio.h>

int main(void)
{
    char ch;
    unsigned int space_ct = 0;
    unsigned int newline_ct = 0;
    unsigned int other_ct = 0;
    while ((ch = getchar()) != '#')
    {
        if (ch == ' ')
            space_ct++;
        else if (ch == '\n')
            newline_ct++;
        else 
            other_ct++;
    }
    printf("space_ct = %u\n", space_ct);
    printf("newline_ct = %u\n", newline_ct);
    printf("other_ct = %u\n", other_ct);
    return 0;
}