// Design and test a function that fetches the next n characters from input
// (including blanks, tabs, and newlines), storing the results in an array
// whose address is passed as an argument.

#include <stdio.h>
#define ARRLEN 5
void getnchars(char *array, int n);
int main(void)
{
    char array[ARRLEN];
    getnchars(array, ARRLEN);
    printf("%s\n", array);
    return 0;
}

void getnchars(char *array, int n)
{   
    char ch;
    for (int i = 0; i < n; i++)
    {
        if ((ch = getchar()) == EOF)
            break;
        array[i] = ch;
    }
}