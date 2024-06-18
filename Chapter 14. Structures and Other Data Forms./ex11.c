// Write a function called transform() that takes four arguments: the name of a source
// array containing type double data, the name of a target array of type double, an int
// representing the number of array elements, and the name of a function (or, equivalently,
// a pointer to a function). The transform() function should apply the indicated function
// to each element in the source array, placing the return value in the target array. For
// example, the call
// transform(source, target, 100, sin);
// would set target[0] to sin(source[0]), and so on, for 100 elements. Test the function
// in a program that calls transform() four times, using two functions from the math.h
// library and two suitable functions of your own devising as arguments to successive calls
// of the transform() function.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define ARRLEN 11
void transform(const double source[], double target[], int arrlen, double (*func) (double));

double sqr(double);

double cb(double);

int main(void)
{
    double source[ARRLEN];
    double target[ARRLEN];

    srand(time(NULL));


    printf("Source array:\n");
    for (int i = 0; i < ARRLEN; i++)
    {
        source[i] = rand() % (10);
        printf("%lf\n", source[i]);
    }


    transform(source, target, ARRLEN, sqr);

    printf("\nTarget array (sqr):\n");
    for (int i = 0; i < ARRLEN; i++)
    {
        printf("%lf\n", target[i]);
    }

    transform(source, target, ARRLEN, cb);

    printf("\nTarget array (cube):\n");
    for (int i = 0; i < ARRLEN; i++)
    {
        printf("%lf\n", target[i]);
    }

    
    transform(source, target, ARRLEN, sin);
    printf("\nTarget array (sin):\n");
    for (int i = 0; i < ARRLEN; i++)
    {
        printf("%lf\n", target[i]);
    }

    transform(source ,target, ARRLEN, sqrt);
    printf("\nTarget array (sqrt):\n");
    for (int i = 0; i < ARRLEN; i++)
    {
        printf("%lf\n", target[i]);
    }
}

double sqr(double x) { return ((x) * (x));}

double cb(double x) { return ((x) * (x) * (x));}

void transform(const double source[], double target[], int arrlen, double (*func) (double))
{
    for (int i = 0; i < arrlen; i++)
    {
        target[i] = (*func)(source[i]);
    }
}