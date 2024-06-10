// Write a program that reads characters from the standard input to end-of-file. For each
// character, have the program report whether it is a letter. If it is a letter, also report
// its numerical location in the alphabet. For example, c and C would both be letter 3.
// Incorporate a function that takes a character as an argument and returns the numerical
// location if the character is a letter and that returns –1 otherwise.

#include <stdio.h>
#include <ctype.h>

int numLoc(char ch);
void flush_input_buffer(void);
int main(void)
{
    char ch;
    int ret_val; // for numLoc return value
    while ((ch = getchar()) != EOF)
    {
        flush_input_buffer();
        ret_val = numLoc(ch);  
        if (ret_val == -1)
            break;
    }
    puts("bye");
    return 0;
}

int numLoc(char ch)
{
    char backup_ch = ch;    // for output
    int numLoc;
    if (isalpha(ch))
        {  
            if (isupper(ch))
                ch = tolower(ch);
            numLoc = ch - 'a' + 1;
            printf("%c is %d in alphabet.\n", backup_ch, numLoc);
        }
    else 
        numLoc = -1;
    
    return numLoc;
}

void flush_input_buffer(void)
{
    while (getchar() != '\n')
    {
        continue;
    }
}