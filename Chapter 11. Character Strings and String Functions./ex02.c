// Modify and test the function in exercise 1 so that it stops after n characters or after the
// first blank, tab, or newline, whichever comes first. (Don’t just use scanf().)

#include <stdio.h>
#include <ctype.h>
#define ARRLEN 5

void getnchars(char *array, int n);
void flush_input_buffer(void);
int main(void)
{
    char array[ARRLEN];
    puts("Enter input:");
    getnchars(array, ARRLEN);
    puts(array);
    return 0;
}

void getnchars(char *array, int n)
{
	char ch;

    for (int i = 0; i < n; i++)
    {
        if ((ch = getchar()) == EOF || isspace(ch))
            break;
        else 
            array[i] = ch;
    }
    flush_input_buffer();
}

void flush_input_buffer(void)
{
    while (getchar() != '\n')
        continue;
}