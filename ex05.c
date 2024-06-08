// Have a program request the user to enter an uppercase letter. Use nested loops to produce
// a pyramid pattern like this:
//     A
//    ABA
//   ABCBA
//  ABCDCBA
// ABCDEDCBA
// The pattern should extend to the character entered. For example, the preceding pattern
// would result from an input value of E. Hint: Use an outer loop to handle the rows. Use
// three inner loops in a row, one to handle the spaces, one for printing letters in ascending
// order, and one for printing letters in descending order. If your system doesn’t use ASCII
// or a similar system that represents letters in strict number order, see the suggestion in
// programming exercise 3.

#include <stdio.h>

int main(void)
{
    char letter;
    puts("Enter a letter:");
    scanf("%c", &letter);

   // Use an outer loop to handle the rows
    
    for (char c1 = 'A'; c1 <= letter; c1++)
    {
        char c2 = 'A';
        unsigned int spaces = letter - c1;
        for (unsigned int i = 0; i < spaces; i++)
        {
            putchar(' ');
        }
        // printing letters in ascending order (whithout center letter)
        while (c2 < c1)
        {
            printf("%c", c2);
            c2++;
        }

        // printing letters in descending order (with center letter)
        while (c2 >= 'A')
        {
            printf("%c", c2--);
        }
        putchar('\n');
    }
    return 0;
}