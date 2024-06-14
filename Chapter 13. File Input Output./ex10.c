// Write a program that opens a text file whose name is obtained interactively. Set up a
// loop that asks the user to enter a file position. The program then should print the part of
// the file starting at that position and proceed to the next newline character. Let negative
// or nonnumeric input terminate the user-input loop.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILENAME 100
char *s_gets(char *st, int n);
void flush_input_buffer(void);
int main(void)
{
    FILE *fp;
    char filename[MAX_FILENAME];
    long pos;
    char ch;

    printf("Enter a file name: ");
    s_gets(filename, MAX_FILENAME);
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    
    printf("Enter a file position: (< 0 or non-numeric to quit): ");
    while (scanf("%ld", &pos) == 1 && pos >= 0)
    {   
        flush_input_buffer();
        rewind(fp); 
        fseek(fp, pos, SEEK_SET);
        

        while ((ch = getc(fp)) != '\n' && ch != EOF)
        {
            putc(ch, stdout);
        }
        putc('\n', stdout);
        printf("Enter a file position: (< 0 or non-numeric to quit): ");
    }
    if ((fclose(fp)) != 0)
    {
        fprintf(stderr, "Can't close %s\n", filename);
        exit(EXIT_FAILURE);
    }
    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
        {
            *find = '\0';
        }

    }
    return ret_val;
}

void flush_input_buffer(void)
{
    while (getchar() != '\n')
        continue;
}