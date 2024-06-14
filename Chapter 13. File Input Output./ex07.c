// Write a program that opens two files. You can obtain the filenames either by using
// command-line arguments or by soliciting the user to enter them.
// a. Have the program print line 1 of the first file, line 1 of the second file, line 2 of the
// first file, line 2 of the second file, and so on, until the last line of the longer file (in
// terms of lines) is printed.
// b. Modify the program so that lines with the same line number are printed on the
// same line.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define FILENAME_LEN 101
#define LINE_LEN 256


char * s_gets(char *st, int n);
int main(void)
{
    FILE *fp1, *fp2;
    char filename1[FILENAME_LEN], filename2[FILENAME_LEN];
    char ch1, ch2;
    unsigned long line_num = 1;
    bool first_eof_flag = false;


    printf("Enter the name of the first file: ");
    s_gets(filename1, FILENAME_LEN);
    fp1 = fopen(filename1, "r");
    if (fp1 == NULL)
    {
        fprintf(stderr, "Can't open %s\n", filename1);
        exit(EXIT_FAILURE);
    }


    printf("Enter the name of the second file: ");
    s_gets(filename2, FILENAME_LEN);
    fp2 = fopen(filename2, "r");
    if (fp2 == NULL)
    {
        fprintf(stderr, "Can't open %s\n", filename2);
        exit(EXIT_FAILURE);
    }
    ch1 = getc(fp1);
    ch2 = getc(fp2);
    while (ch1 != EOF || ch2 != EOF)
    {   
        if (ch1 != EOF)
            printf("%lu line in %s: ", line_num, filename1);
        while (ch1 != EOF && ch1 != '\n')
        {
            putc(ch1, stdout);
            ch1 = getc(fp1);
        }
        if (ch1 != EOF)
        {
            putc('\n', stdout);
            ch1 = getc(fp1);
        }
        if (ch1 == EOF && !first_eof_flag)
        {
            putc('\n', stdout);
            first_eof_flag = true;
        }


        if (ch2 != EOF)
            printf("%lu line in %s: ", line_num, filename2);
        while (ch2 != EOF && ch2 != '\n')
        {
            putc(ch2, stdout);
            ch2 = getc(fp2);
        }
        if (ch2 != EOF)
        {
            putc('\n', stdout);
            ch2 = getc(fp2);
        }
        if (ch2 == EOF && !first_eof_flag)
        {
            putc('\n', stdout);
            first_eof_flag = true;
        }
        line_num++;
    }
    putchar('\n');

    if (fclose(fp1) != 0)
    {
        fprintf(stderr, "Can't close file %s\n", filename1);
        exit(EXIT_FAILURE);
    }

    if (fclose(fp2) != 0)
    {
        fprintf(stderr, "Can't close file %s\n", filename2);
        exit(EXIT_FAILURE);
    }

    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    ret_val = fgets(st, n, stdin);

    if (ret_val)
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
        return ret_val;
    }
    else 
    {
        return NULL;
    }
}

