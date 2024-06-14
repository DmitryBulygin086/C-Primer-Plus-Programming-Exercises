// Write a program that takes two command-line arguments. The first is a string; the
// second is the name of a file. The program should then search the file, printing all lines
// containing the string. Because this task is line oriented rather than character oriented,
// use fgets() instead of getc(). Use the standard C library function strstr() (briefly
// described in exercise 7 of Chapter 11) to search each line for the string. Assume no lines
// are longer than 255 characters.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LINE_LEN 255

char *s_gets(char *st, int n);
int main(int argc, char *argv[])
{
    if (argc < 3 || argc > 3)
    {
        fprintf(stderr, "Usage: %s string filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    fp = fopen(argv[2], "r");
    char line[LINE_LEN];
    bool one_found = false;


    if (fp == NULL)
    {
        fprintf(stderr, "Could not open file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while ((fgets(line, LINE_LEN, fp))!= NULL)
    {
        if (strstr(line, argv[1]) != NULL)
        {
            one_found = true;
            fputs(line, stdout);
        }
    }
    if (!one_found)
    {
        printf("%s not found in %s\n", argv[1], argv[2]);
    }

    if (fclose(fp)!= 0)
    {
        fprintf(stderr, "Could not close file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    return 0; 
}   

