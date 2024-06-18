// Write a function that converts a binary string to a numeric value. That is, if you have
// char * pbin = "01001001";
// you can pass pbin as an argument to the function and have the function return an int
// value of 25.
#include <stdio.h>
#include <string.h>

int bin_to_dec(char * pbin);

int main(void)
{
    char * pbin = "01001001";

    printf("%d\n", bin_to_dec(pbin));
    return 0;
}

int bin_to_dec(char * pbin)
{
    int dec = 0;

    while (*pbin != '\0')
    {
        dec <<= 1;
        if (*pbin == '1')
            dec |= 1;
        pbin++;
    }
    return dec;
}