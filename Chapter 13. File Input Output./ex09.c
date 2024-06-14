// Modify the program in Listing 13.3 so that each word is numbered according to the order
// in which it was added to the list, starting with 1. Make sure that, when the program is
// run a second time, new word numbering resumes where the previous numbering left off.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>



void fprintf_word(FILE *fp, const char * format, char *str);
void print_words(FILE *fp,char *str);

#define MAX 41

int main(void)
{
    FILE *fp;
    char words[MAX];
    unsigned word_ct = 0;
    char ch;

    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    rewind(fp);
    while (fgets(words, MAX, fp) != NULL)
    {
        word_ct++;
    }

    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
    {
        word_ct++;
        fprintf(fp,"%u: %s\n", word_ct, words);
    }
    puts("File contents:");
    rewind(fp);          /* go back to beginning of file */
    while ((ch = getc(fp)) != EOF)
        putc(ch, stdout);
    puts("Done!");
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;
}


void print_words(FILE *fp,char *str)
{
    char ch;
    bool inword = false;
    unsigned word_ct = 0;
    while (isspace(*str))
    {
        str++;
    }
    while ((ch = (*str)) != '\0')
    {
        if (!inword)
        {
            inword = true;
            word_ct++;
        }
        fprintf(fp,"%u: ", word_ct);
        putc(ch, fp);

        if (isspace(ch))
        {
            inword = false;
            break;
        }
    }

}