// Modify the get_first() function of Listing 8.8 so that it returns the first non-
// whitespace character encountered. Test it in a simple program.

// get_first() function in Listing 8.8.
// char get_first(void)
// {
    // int ch;
    // ch = getchar();
    // while (getchar() != '\n')
    //      continue;
    // return ch;
// }

#include <stdio.h>
#include <ctype.h>

char get_first(void);

int main(void)
{
    char ch;
    ch = get_first();
    printf("get_first() returns %c\n", ch);
    return 0;
}

char get_first(void)
{
    char ch;
    do 
    {
        ch = getchar();
    } while (isspace(ch));

    char garbage;
    while ((garbage = getchar()) != '\n' && garbage != EOF)
        continue;
   
    return ch;
}