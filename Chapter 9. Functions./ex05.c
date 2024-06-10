// Write and test a function called larger_of() that replaces the contents of two double
// variables with the maximum of the two values. For example, larger_of(x,y) would
// reset both x and y to the larger of the two.

#include <stdio.h>

void larger_of(double *dn1, double *dn2);
void flush_input_buffer(void);

int main(void)
{
    double dn1, dn2;
    printf("Enter two double numbers and I replace their contents\n");
    printf("with the maximum of the two values.\n");
    while ((scanf("%lf %lf", &dn1, &dn2)) != 2)
    {
        flush_input_buffer();
        printf("Invalid input. Try again.\n");
    }
    larger_of(&dn1, &dn2);  // put numbers in black box
    printf("After larger_of() dn1 = %lf and dn2 = %lf\n", dn1, dn2);
    return 0;
}

void larger_of(double *dn1, double *dn2)
{
    if (*dn1 > *dn2)
    {
        *dn2 = *dn1;
    }
    else 
        *dn1 = *dn2;
}
void flush_input_buffer(void)
{
    while (getchar() != '\n')
        continue;
}