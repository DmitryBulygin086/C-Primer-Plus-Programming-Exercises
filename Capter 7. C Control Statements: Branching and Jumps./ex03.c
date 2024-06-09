// Write a program that reads integers until 0 is entered. After input terminates, the
// program should report the total number of even integers (excluding the 0) entered, the
// average value of the even integers, the total number of odd integers entered, and the
// average value of the odd integers.

#include <stdio.h>

int main(void)
{
    int input;

    unsigned int even_ct = 0;
    int even_sum = 0;
    float even_avg;

    unsigned int odd_ct = 0;
    int odd_sum = 0;
    float odd_avg;
    while (scanf("%d", &input) == 1 && input != 0)
    {
        if (input % 2 == 0)
        {
            even_ct++;
            even_sum += input;
        }
        else
        {
            odd_ct++;
            odd_sum += input;
        }
    }
    even_avg = (float)even_sum / (float)even_ct;
    odd_avg = (float)odd_sum / (float)odd_ct;

    printf("even_ct = %u\n", even_ct);
    printf("even_avg = %f\n", even_avg);
    putchar('\n');
    printf("odd_ct = %u\n", odd_ct);
    printf("odd_avg = %f\n", odd_avg);
    return 0;
}