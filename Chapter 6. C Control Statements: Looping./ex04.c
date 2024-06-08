// Use nested loops to produce the following pattern:
// A
// BC
// DEF
// GHIJ
// KLMNO
// PQRSTU

#include <stdio.h>
#define ROWS 6

int main(void)
{
    char letter = 'A';
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%c", letter++); // use letter, then increment it
        }
        putchar('\n');
    }
    return 0;
}