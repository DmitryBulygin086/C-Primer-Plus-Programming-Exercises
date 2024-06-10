// Write and test a Fibonacci() function that uses a loop instead of recursion to calculate
// Fibonacci numbers.

#include <stdio.h>

unsigned Fibonacci(unsigned n);
void flush_input_buffer(void);

int main(void)
{
    unsigned input;
    unsigned rv;
    while (1)
    {
        printf("Enter a number(0 to quit): ");
        while (scanf("%d", &input) != 1)
        {
            flush_input_buffer();
            printf("Invalid input. Try again.\n");
            printf("Enter a number: ");
        }
        rv = Fibonacci(input);
        if (rv == 0)
            break;
        printf("#%u Fibonacci number = %u\n", input, rv);
    }
    return 0;
}

unsigned Fibonacci(unsigned n)
{
    unsigned fib_n = 1, preFib_n = 1, prepreFib_n;
    if (n < 1)
    {
   
        return 0;
    }

    if (n == 1) return 1;
    if (n == 2) return 1;

    for (int i = 3; i <= n; i++)
    {
        prepreFib_n = preFib_n;
        preFib_n = fib_n;
        fib_n = prepreFib_n + preFib_n;
    }
    return fib_n;
}

void flush_input_buffer(void)
{
    while (getchar() != '\n')
        continue;
}