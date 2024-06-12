// Use the character classification functions to prepare an implementation of atoi(); have
// this version return the value of 0 if the input string is not a pure number.

#include <stdio.h>
#include <ctype.h>

int myatoi(char *str);

int main(int argc, char *argv[])
{
    int input;
    if (argc != 2)
    {
        printf("Usage: <%s> <integer>\n", argv[0]);
        return 1;
    }
    else 
    {
        input = myatoi(argv[1]);
        printf("%d + 5 = %d\n", input, input + 5);
		printf("%d / 2 = %d\n", input, input / 2);
		printf("%d %% 3 = %d\n", input, input % 3);
    }
    return 0;
}

int myatoi(char *str)
{
    int integer = 0;
    while (*str != '\0')
    {
        if (!isdigit(*str)) // if not a pure number
        {
            return 0;
        }
        else
        {
            integer *= 10; // new digit, so shift old digits one place to the left
            integer += *str - '0'; // add new digit to the ones place
        }
        return integer;
    }
}