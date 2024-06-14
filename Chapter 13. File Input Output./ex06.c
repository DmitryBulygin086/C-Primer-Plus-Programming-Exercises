// Programs using command-line arguments rely on the user’s memory of how to use them
// correctly. Rewrite the program in Listing 13.2 so that, instead of using command-line
// arguments, it prompts the user for the required information.


#include <stdio.h>
#include <stdlib.h> // for exit()
#include <string.h>
#define LEN 81

char *s_gets(char *st, int n);

int main(void)
{
    FILE *in, *out;   // declare two FILE pointers
    int ch;
    char name[LEN];   // storage for output file name
    int count = 0;
    char filename[LEN];



    printf("Enter the name of the file to reduced: ");
    s_gets(filename,LEN - 5);

    


    // set up input
    if ((in = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", filename);
        exit(EXIT_FAILURE);
    }
    // set up output
    strncpy(name, filename, LEN - 5);  // copy filename
    name[LEN - 5] = '\0';
    strcat(name,".red");           // append .red
    if ((out = fopen(name, "w")) == NULL)
    {                   // open file for writing
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }

    // copy data
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);  // ptint every 3rd char
    
    printf("See %s file in your folder.\n", name);

    // clean up
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");
    
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
            // else // must be the EOF
            //     while (getchar()!= '\n')
            //         continue;
            st++;
        }
    }
    return ret_val;
}