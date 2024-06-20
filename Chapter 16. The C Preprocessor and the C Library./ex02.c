// The harmonic mean of two numbers is obtained by taking the inverses of the two
// numbers, averaging them, and taking the inverse of the result. Use a #define directive
// to define a macro “function” that performs this operation. Write a simple program that
// tests the macro.

#include "ex01.h"

#define HARM_MEAN(X, Y) (1.0 / (((1.0 / (X)) + (1.0 / (Y))) / 2.0))

int main(void)
{
    double n1, n2;
    printf("Enter two numbers: ");
    while (scanf("%lf %lf", &n1, &n2) != 2)
    {
        EATLINE;
        printf("Enter two numbers: ");
    }
    EATLINE;

    printf("The harmonic mean of %g and %g is %g\n", n1, n2, HARM_MEAN(n1, n2));
    return 0;
}