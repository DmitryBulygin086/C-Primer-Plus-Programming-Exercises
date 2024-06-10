// Chapter 6, “C Control Statements: Looping,” (Listing 6.20) shows a power() function
// that returned the result of raising a type double number to a positive integer value.
// Improve the function so that it correctly handles negative powers. Also, build into the
// function that 0 to any power other than 0 is 0 and that any number to the 0 power is 1.
// (It should report that 0 to the 0 is undefined, then say it’s using a value of 1.) Use a loop.
// Test the function in a program.

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double power(double *dn, int pow);

int main(void)
{
    double dn;
    int pow;
    double rv; // return value
    while (1)
    {
        printf("Enter double number and power(nonnumeric value to quit): ");
        if (scanf("%lf %d", &dn, &pow) != 2)
        {
            // flush_input_buffer();
            break;
        }
        rv = power(&dn, pow);
        printf("%lf to the power of %d is %lf\n", dn, pow, rv);
    }
    puts("bye");
    return 0;
}

double power(double *dn, int pow)
{
    double ret_val = 1.0;

    // Rare cases handling
    if (*dn == 0)
    {
        if (pow == 0)
        {
            printf("0 to 0 power is undefined\n");
            printf("Therefore 1 for number is used.\n");
            *dn = 1.0;  // for this expression we need dn to be a pointer
            return 1;
        }
        return 0;
    }
    else if (pow == 0)
    {
        return 1;
    }

    bool neg_pow = false;
    if (pow < 0)
        neg_pow = true;
    for(unsigned count = 0; count < fabs(pow); count++)
    {
        ret_val *= *dn;
    }
    if (neg_pow)
       ret_val = (double)1.0 / ret_val;
    
    return ret_val;
}
