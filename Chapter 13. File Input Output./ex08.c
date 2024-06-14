// Write a program that takes as command-line arguments a character and zero or more
// filenames. If no arguments follow the character, have the program read the standard
// input. Otherwise, have it open each file in turn and report how many times the character
// appears in each file. The filename and the character itself should be reported along with
// the count. Include error-checking to see whether the number of arguments is correct and
// whether the files can be opened. If a file can’t be opened, have the program report that
// fact and go on to the next file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char ch;
    unsigned ch_ct = 0;


    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <character> <filename>...\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    


    else if (argc == 2)
    {
        ch_ct = 0;
        fp = stdin;
        if ((fp) == NULL)
        {
            fprintf(stderr, "Can't open stdin\n");
            exit(EXIT_FAILURE);
        }
        printf("Reading from standard input...(EOF at the beginning of the line to stop)\n");
        while ((ch = getc(fp)) != EOF)
        {
            if (ch == argv[1][0])
            {
                ch_ct++;
            }
        }
        if (fclose(fp) != 0)
        {
            fprintf(stderr, "Can't close stdin\n");
            exit(EXIT_FAILURE);
        }
        printf("The character '%c' appears %u times.\n", argv[1][0], ch_ct);
        exit(EXIT_SUCCESS);
    }
    else 
    {
        for (unsigned int i = 2; i < argc; i++)
        {
            ch_ct = 0;
            fp = fopen(argv[i], "r");
            if ((fp) == NULL)
            {
                fprintf(stderr, "Can't open %s\n", argv[i]);
                continue;
            }
            while ((ch = getc(fp)) != EOF)
            {
                if (ch == argv[1][0])
                {
                    ch_ct++;
                }
            }
            if ((fclose(fp) != 0))
            {
                fprintf(stderr, "Can't close %s\n", argv[i]);
                exit(EXIT_FAILURE);
            }
            printf("The character '%c' appears %u times in %s.\n", argv[1][0], ch_ct, argv[i]);
        }
    }
    return 0;
}