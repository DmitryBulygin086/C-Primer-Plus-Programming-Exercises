// Write a program that reads in a line of input and then prints the line in reverse order.
// You can store the input in an array of char; assume that the line is no longer than 255
// characters. Recall that you can use scanf() with the %c specifier to read a character at
// a time from input and that the newline character (\n) is generated when you press the
// Enter key.

#include <stdio.h>
#include <string.h>
// assume that the line is no longer than 255
// characters
#define LINELEN 255
int main(void)
{
    char line[LINELEN];
    printf("Enter a line:\n");
    int i = 0;
    while(scanf("%c", &line[i]) && line[i] != '\n' && i < LINELEN)
    {
        i++;
    }

    // prints the line in reverse order
    int count = (int)(strlen(line) - 1);
    for (; count >= 0; count--)
    {
        printf("%c", line[count]);
    }
    printf("\n");
    return 0;

    

}