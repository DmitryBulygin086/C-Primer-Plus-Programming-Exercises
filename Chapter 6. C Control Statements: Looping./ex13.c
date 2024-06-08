// Write a program that creates an eight-element array of ints and sets the elements to the
// first eight powers of 2 and then prints the values. Use a for loop to set the values, and,
// for variety, use a do while loop to display the values.

#include <stdio.h>

int main(void)
{
    int ints[8];
    int powers = 1;
    for (int i = 0; i < 8; i++)
    {
        powers *= 2;
        ints[i] = powers;
    }

    int i = 0;
    do
    {
        printf("%d ", ints[i]);
        i++;
    } while (i < 8);
    return 0;
}

