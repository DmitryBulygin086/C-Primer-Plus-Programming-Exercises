// Write a program that reads input as a stream of characters until encountering EOF.
// Have it report the number of uppercase letters, the number of lowercase letters, and the
// number of other characters in the input. You may assume that the numeric values for the
// lowercase letters are sequential and assume the same for uppercase. Or, more portably,
// you can use appropriate classification functions from the ctype.h library.

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    unsigned upper_ct = 0, lower_ct = 0, other_ct = 0;
    while ((ch = getchar()) != EOF)
    {
        if (isupper(ch))
            upper_ct++;
        else if (islower(ch))
            lower_ct++;
        else 
            other_ct++;
    }
    printf("upper_ct = %u\n", upper_ct);
    printf("lower_ct = %u\n", lower_ct);
    printf("other_ct = %u\n", other_ct);
    return 0;
}