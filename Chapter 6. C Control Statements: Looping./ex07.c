// Write a program that reads a single word into a character array and then prints the word
// backward. Hint: Use strlen() (Chapter 4) to compute the index of the last character in
// the array.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define WORDLEN 20

int main(void)
{
    char word[WORDLEN + 1];
    puts("Enter a word:");
    scanf("%s", word);

    for (int i = strlen(word) - 1; i >= 0; i--)
    {
        printf("%c", word[i]);
    }

    return 0;
}