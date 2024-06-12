// Design and test a function that reads the first word from a line of input into an array and
// discards the rest of the line. It should skip over leading whitespace. Define a word as a
// sequence of characters with no blanks, tabs, or newlines in it. Use getchar().
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

void getword(char *array);

int main(void)
{
    char array[10];
    puts("Enter input:");
    getword(array);
    puts(array);
    return 0;
}
void getword(char *array)
{   
    int i = 0;
    char ch;
    bool inword = false;
    while ((ch = getchar()) != EOF)
    {
        if (isspace(ch))
        {
            if (inword)
                break;
            else 
                continue;
        }
        else 
        {
            if (!inword)
                inword = true;
            array[i] = ch;
            i++;
        }
    }
    
}


