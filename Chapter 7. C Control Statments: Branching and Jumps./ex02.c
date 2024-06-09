// Write a program that reads input until encountering #. Have the program print each
// input character and its ASCII decimal code. Print eight character-code pairs per line.
// Suggestion: Use a character count and the modulus operator (%) to print a newline
// character for every eight cycles of the loop.

#include <stdio.h>

int main(void)
{
    char ch;
    unsigned int ch_ct = 0;
    while ((ch = getchar()) != '#')
    {
        
        if (ch == '\n') // if newline was entered
            // printf("\'\\n\' = %d", '\n');  // we can print it
            continue; // or we can continue to the next cycle of the loop
        
        else
            printf("\'%c\' = %d", ch, ch);

        printf("   "); // spaces between pairs
        ch_ct++;

        if (ch_ct % 8 == 0)
            printf("\n");
    }
    return 0;
}