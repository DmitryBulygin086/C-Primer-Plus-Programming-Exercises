// The harmonic mean of two numbers is obtained by taking the inverses of the two
// numbers, averaging them, and taking the inverse of the result. Write a function that
// takes two double arguments and returns the harmonic mean of the two numbers.

#include <stdio.h>

double harmonic_mean(double, double);

int main(void)
{
    double dn1 = 4.6, dn2 = 4.5;
    printf("Harmonic mean of %lf and %lf is %lf\n", dn1, dn2, harmonic_mean(dn1, dn2));
    return 0;
}

double harmonic_mean(double dn1, double dn2)
{
    double inv_dn1 = (double)1.0 / dn1;
    double inv_dn2 = (double)1.0 / dn2;
    double avg = (inv_dn1 + inv_dn2) / 2;
    double inv_avg = (double)1.0 / avg;
    return inv_avg;
}