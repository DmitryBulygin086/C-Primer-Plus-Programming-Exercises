// Write a program that accepts a positive integer as input and then displays all the prime
// numbers smaller than or equal to that number.

#include <stdio.h>
#include <stdbool.h>

void flush_input_buffer(void);

int main(void)
{
   
    int input;
    printf("Enter a positive integer: ");
    
    while(scanf("%d", &input) != 1 || input < 0)
    {
        flush_input_buffer();
        printf("Enter a positive integer: ");
    }
   
    
    int i = 2;
    while (i <= input)
    {
        bool prime_flag = true;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
                prime_flag = false;
                break;
        }
        if (prime_flag)
        {
            printf("%d ", i);
        }
        i++;
    }
    return 0;
}

void flush_input_buffer(void)
{
    while (getchar() != '\n')
        continue;
}