// Consider these two infinite series:
// 1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
// 1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...
// Write a program that evaluates running totals of these two series up to some limit of
// number of terms. Hint: –1 times itself an odd number of times is –1, and –1 times itself
// an even number of times is 1. Have the user enter the limit interactively; let a zero or
// negative value terminate input. Look at the running totals after 100 terms, 1000 terms,
// 10,000 terms. Does either series appear to be converging to some value?

#include <stdio.h>

int main(void)
{   
    int limit;
    float sign = 1.0f;
    
    puts("Enter limit of terms:");
    while(scanf("%d", &limit) == 1)
    {
        float series1 = 0, series2 = 0;
        for(unsigned int i = 1; i <= limit; i++)
        {
            series1 += (1.0f/i);
            series2 += (1.0f/i) * sign;
            sign = -sign;
        }
        printf("1 series: %f\n", series1);
        printf("2 series: %f\n", series2);

        puts("Enter the next number of terms:");
    }
    return 0;
}