// Write a function that takes an int argument and returns the number of “on” bits in the
// argument. Test the function in a program.

#include <stdio.h>
#include <limits.h>

int ON_ct(int dec);

char * to_bin_str(int dec, int strlength, char str[strlength]);

void eatline(void);

int main(void)
{
    int input;
    int size = sizeof(int) * CHAR_BIT + 1;
    char bin_str[size];

    while (1)
    {
        printf("Enter a decimal number(nonnumeric input to quit): ");
        if(scanf("%d", &input) != 1)
        {
            break;
        }
        eatline();

        printf("The binary representation of %d is %s\n", input, to_bin_str(input, size, bin_str));
        printf("The number of \"on\" bits in %d is %d\n", input, ON_ct(input));
    }

    return 0;
}

int ON_ct(int dec)
{
    int ct = 0;
    while (dec != 0)
    {
        if (dec & 1)
        {
            ct++;
        }
        dec >>= 1;
    }
    return ct;
}

char * to_bin_str(int dec, int strlength,char str[strlength])
{
    int i = strlength - 1;  // go to the end of the string
    str[i] = '\0';
    i--;

    for (; i >= 0; i--)
    {
        if (dec & 1)
        {
            str[i] = '1';
        }
        else   
            str[i] = '0';
        dec >>= 1;
    }
    return str;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}
