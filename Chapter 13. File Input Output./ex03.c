// Write a file copy program that prompts the user to enter the name of a text file to act as
// the source file and the name of an output file. The program should use the toupper()
// function from ctype.h to convert all text to uppercase as it’s written to the output file.
// Use standard I/O and the text mode.

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILE_NAME 100
char *s_gets(char *st, int n);
void clear_input_stream(void);
int main(void)
{
    char src_file[MAX_FILE_NAME], dest_file[MAX_FILE_NAME];
    FILE *src_fp, *dest_fp;
    char ch;

    puts("Enter the name of a text file to act as the source file:");
    while (s_gets(src_file, MAX_FILE_NAME) == NULL) 
    {
        //clear_input_stream();
        puts("Enter the name of a text file to act as the source file:");
    }
    //clear_input_stream();

    puts("Enter the name of an output file:");
    while (s_gets(dest_file, MAX_FILE_NAME) == NULL)
    {
        //clear_input_stream();
        puts("Enter the name of an output file:");
    }
    //clear_input_stream();


    src_fp = fopen(src_file, "r");
    dest_fp = fopen(dest_file, "w");
    if (src_fp == NULL )
    {
        fprintf(stderr,"Can't open the %s.", src_file);
        exit(EXIT_FAILURE);
    }
    if (dest_fp == NULL)
    {
        fprintf(stderr,"Can't open the %s.", dest_file);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(src_fp))!= EOF)
    {
        if (islower(ch))
            ch = toupper(ch);
        
        putc(ch, dest_fp);
    }

    fclose(src_fp);
    fclose(dest_fp);

    puts("Done.");
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
    }
    return ret_val;
}

void clear_input_stream(void)
{
    while (getchar()!= '\n')
    {
        continue;
    }
}


