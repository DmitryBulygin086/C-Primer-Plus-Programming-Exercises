// Write a function that takes three arguments: a character and two integers. The character
// is to be printed. The first integer specifies the number of times that the character is to
// be printed on a line, and the second integer specifies the number of lines that are to be
// printed. Write a program that makes use of this function.

#include <stdio.h>

void printer(char ch, unsigned cols, unsigned rows);

int main(void)
{
    char ch;
    unsigned cols, rows;
    printf("Enter a character and value of cols and rows: ");
    scanf("%c %u %u", &ch, &cols, &rows);
    printer(ch, cols, rows);
    return 0;
}

void printer(char ch, unsigned cols, unsigned rows)
{
    unsigned local_rows, local_cols;
    for (local_rows = 0; local_rows < rows; local_rows++)
    {
        for (local_cols = 0; local_cols < cols; local_cols++)
        {
            putchar(ch);
        }
        putchar('\n');
    }
}