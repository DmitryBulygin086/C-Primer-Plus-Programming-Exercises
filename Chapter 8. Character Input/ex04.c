// Write a program that reads input as a stream of characters until encountering EOF. Have
// it report the average number of letters per word. Don’t count whitespace as being letters
// in a word. Actually, punctuation shouldn’t be counted either, but don’t worry about that
// now. (If you do want to worry about it, consider using the ispunct() function from the
// ctype.h family.)

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(void)
{
    char ch;
    bool inword = false;
    unsigned ch_ct = 0, word_ct = 0;
    float avg;

    while ((ch = getchar()) != EOF)
    {
        if (isalpha(ch))
        {
            if (!inword)
            {
                inword = true;
                word_ct++;  
            }
            ch_ct++;
        }
        else 
            inword = false;
    }
    avg = (float)ch_ct / (float)word_ct;
    printf("avg = %f\n", avg);
    return 0;
}