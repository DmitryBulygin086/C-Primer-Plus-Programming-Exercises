// Write a program that reads input up to # and reports the number of times that the
// sequence ei occurs.

#include <stdio.h>
#include <stdbool.h> // for e_flag

int main(void)
{
    char ch;
    bool e_flag = false;
    unsigned int ei_ct = 0;

    puts("Enter an input:");
    while ((ch = getchar()) != '#')
    {
        if (ch == 'e')
        {
            e_flag = true;
        }
        else if (ch == 'i' && e_flag == true)
        {
            ei_ct++;
            e_flag = false;
        }
        else 
        {
            e_flag = false;
        }
    }
    printf("ei_ct = %u\n", ei_ct);
    return 0;
}