// Write a program that prints a table with each line giving an integer, its square, and its
// cube. Ask the user to input the lower and upper limits for the table. Use a for loop.

#include <stdio.h>

int main(void)
{
    int lower_lim, upper_lim;
    puts("Enter a lower and upper limits:");
    scanf("%d %d", &lower_lim, &upper_lim);

    printf("%20s %20s %20s", "an integer", "its square", "its cube");
    putchar('\n');
    for (; lower_lim <= upper_lim; lower_lim++)
    {
        printf("%20d %20d %20d", lower_lim, 
                                         lower_lim * lower_lim, 
                                         lower_lim * lower_lim * lower_lim);
        putchar('\n');
    }
    return 0;
}