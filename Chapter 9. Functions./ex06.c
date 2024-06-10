// Write and test a function that takes the addresses of three double variables as arguments
// and that moves the value of the smallest variable into the first variable, the middle value
// to the second variable, and the largest value into the third variable.

#include <stdio.h>
void dSort(double *dn1, double *dn2, double *dn3);
void flush_input_buffer(void);
int main(void)
{
    double dn1, dn2, dn3;
    printf("Enter three double numbers: ");
    while ((scanf("%lf %lf %lf", &dn1, &dn2, &dn3)) != 3)
    {
        flush_input_buffer();
        printf("Invalid input. Try again.\n");
        printf("Enter three double numbers: ");
    }
    dSort(&dn1, &dn2, &dn3);
    printf("dn1 = %lf, dn2 = %lf, dn3 = %lf\n", dn1, dn2, dn3);
    return 0;
}

void dSort(double *dn1, double *dn2, double *dn3)
{
    double temp;
    if (*dn1 > *dn2)
    {
        temp = *dn2;
        *dn2 = *dn1;
        *dn1 = temp;
        if (*dn2 > *dn3)
        {
            temp = *dn3;
            *dn3 = *dn2;
            *dn2 = temp;
        }
        if (*dn1 > *dn2)
        {
            temp = *dn2;
            *dn2 = *dn1;
            *dn1 = temp;
        }
    }
    else if (*dn2 > *dn3)
    {
        temp = *dn3;
        *dn3 = *dn2;
        *dn2 = temp;
    }
}

void flush_input_buffer(void)
{
    while (getchar() != '\n')
        continue;
}