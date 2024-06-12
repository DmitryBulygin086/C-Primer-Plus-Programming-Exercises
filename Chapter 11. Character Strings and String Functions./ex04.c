// Design and test a function like that described in Programming Exercise 3 except that it
// accepts a second parameter specifying the maximum number of characters that can be
// read.

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define WORDLEN 10

void getword(char *array, int n);

int main(void)
{
    char array[10];
    puts("Enter input:");
    getword(array, WORDLEN);
    puts(array);
    
    return 0;
}
void getword(char *array, int n)
{   
    int i = 0;
    char ch;
    bool inword = false;
    while ((ch = getchar()) != EOF && i < n)
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

