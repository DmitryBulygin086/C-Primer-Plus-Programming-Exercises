// Write a program that sequentially displays onscreen all the files listed in the command
// line. Use argc to control a loop.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s file...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    char ch;
    for (int i = 1; i < argc; i++)
    {
        fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            fprintf(stderr, "Error opening file %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }

        printf("File %s:\n", argv[i]);
        while ((ch = getc(fp)) != EOF)
        {
            putc(ch, stdout);
        }
        
        putchar('\n');
    }

    fclose(fp);
   
    return 0;
}