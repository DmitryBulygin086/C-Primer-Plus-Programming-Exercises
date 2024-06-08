// Write a program that reads eight integers into an array and then prints them in reverse
// order.

#include <stdio.h>

int main(void)
{
    int eight_ints[8];
    puts("Enter 8 integers:");

    for (unsigned int i = 0; scanf("%d", &eight_ints[i]) == 1 && i < 7; i++)
    {
        continue;
    }

    puts("Reverse order:");
    for(int i = 7; i >= 0; i--)
    {
        printf("%d ", eight_ints[i]);
    }
    return 0;
}