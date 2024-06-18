// Write a program that reads two binary strings as command-line arguments and prints
// the results of applying the ~ operator to each number and the results of applying the
// &, |, and ^ operators to the pair. Show the results as binary strings. (If you don’t have a
// command-line environment available, have the program read the strings interactively.)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int bin_to_dec(char * pbin);
char * to_bin_str(int size, char bin_str[size],int dec);
int main(int argc, char * argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <binary string 1> <binary string 2>\n", argv[0]);
        exit(EXIT_SUCCESS);
    }

    int size = (sizeof(int) * CHAR_BIT + 1);
    char bin_str[size];
    int num1 = bin_to_dec(argv[1]);
    int num2 = bin_to_dec(argv[2]);

    printf("~%s = %s\n", argv[1] ,to_bin_str(size, bin_str,~(num1)));
    printf("~%s = %s\n", argv[2] ,to_bin_str(size, bin_str, ~(num2)));

    printf("%s & %s = %s\n", argv[1], argv[2], to_bin_str(size, bin_str, (num1 & num2)));
    printf("%s | %s = %s\n", argv[1], argv[2], to_bin_str(size, bin_str, (num1 | num2)));
    printf("%s ^ %s = %s\n", argv[1], argv[2], to_bin_str(size, bin_str, (num1 ^ num2)));

    return 0;
}

int bin_to_dec(char * pbin)
{
    int dec = 0;

    while (*pbin != '\0')
    {
       if (*pbin != '0' && *pbin != '1')
       {
        fprintf(stderr, "%s is not a valid binary string\n", pbin);
        exit(EXIT_FAILURE);
       }
        if (*pbin == '1')
        {
            dec |= 1;
        }
        if (*(pbin+1) != '\0')
            dec <<= 1;
        pbin++;
    }
    return dec;
}

char * to_bin_str(int size ,char bin_str[size], int dec)
{
    
    int i = size - 1;
    bin_str[i] = '\0';
    i--;
    for (; i >= 0; i--)
    {
        if (dec & 1)
            bin_str[i] = '1';
        else
            bin_str[i] = '0';
        dec >>= 1;
    }

    return bin_str;
}