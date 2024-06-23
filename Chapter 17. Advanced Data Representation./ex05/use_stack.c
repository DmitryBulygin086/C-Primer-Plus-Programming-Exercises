// Write a program that lets you input a string. The program then should push the
// characters of the string onto a stack, one by one (see review question 5), and then pop
// the characters from the stack and display them. This results in displaying the string in
// reverse order.

#include <stdio.h>
#include <string.h>
#include "stack.h"

char * s_gets(char * str, int n);
int main(void)
{
    Stack character_stack;
    Stack * pstack = InitializeStack(&character_stack);
    char input_string[STRLEN];
    char * pstr;
    char pch[1];

    puts("Enter a string: ");
    s_gets(input_string, STRLEN);
    pstr = input_string;
    while (*pstr!= '\0')
    {
        PushItem(pstr, pstack);
        pstr++;
    }

    while (PopItem(pch, pstack))
        printf("%c", *pch);

    puts("");
}

char * s_gets(char * str, int n)
{
    char * ret_val = fgets(str, n, stdin);
    char * find;

    if (ret_val)
    {
        find = strchr(str, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar()!= '\n')
                continue;
    }
    return ret_val;
}