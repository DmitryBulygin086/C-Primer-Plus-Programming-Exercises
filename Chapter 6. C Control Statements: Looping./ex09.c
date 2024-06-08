// Modify exercise 8 so that it uses a function to return the value of the calculation.

#include <stdio.h>
float calc(float num1, float num2);

int main(void)
{
    float num1, num2;
    puts("Enter two floating-point numbers:");
    

    while (scanf("%f %f", &num1, &num2) == 2)
    {
        printf("%f\n", calc(num1, num2));
        puts("Enter next pair of numbers(nonnumeric input to quit):");
    }
    return 0;
}

float calc(float num1, float num2) {return (num1 - num2) / (num1 * num2);}
