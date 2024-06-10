// 1. Devise a function called min(x,y) that returns the smaller of 
//two double values. Test
// the function with a simple driver.

#include <stdio.h>

double min(double x, double y)
{
    return x < y ? x : y;
}

int main(void)
{
    double x = 4.5, y = 4.6;
    printf("min of x and y is %lf\n", min(y, // x is a formal parameter, y is an actual argument for x formal parameter
                                                    x)); // y is a formal argument, x is an actual argument for y formal parameter
    return 0;
}