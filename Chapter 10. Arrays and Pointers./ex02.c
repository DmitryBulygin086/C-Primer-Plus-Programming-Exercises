// Write a program that initializes an array-of-double and then copies the contents of the
// array into three other arrays. (All four arrays should be declared in the main program.) To
// make the first copy, use a function with array notation. To make the second copy, use a
// function with pointer notation and pointer incrementing. Have the first two functions
// take as arguments the name of the target array, the name of the source array, and the
// number of elements to be copied. Have the third function take as arguments the name
// of the target, the name of the source, and a pointer to the element following the last
// element of the source. That is, the function calls would look like this, given the following
// declarations:
// double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
// double target1[5];
// double target2[5];
// double target3[5];
// copy_arr(target1, source, 5);
// copy_ptr(target2, source, 5);
// copy_ptrs(target3, source, source + 5);

#include <stdio.h>

#define ARRLEN 5

// Copy n elements of source  into target using array notation
void copy_arr(double *target, double *source, int n);

// Copy n elements of source into target using pointer notation
void copy_ptr(double *target, double *source, int n);

// Copy &source trough &lastSource elements into target
void copy_ptrs(double *target, double *source, double *lastSource);

int main(void)
{
    double dArray[ARRLEN] = {3.4, 45.4, 476.3, 3.2, 4.6};
    double dArray1[ARRLEN], dArray2[ARRLEN], dArray3[ARRLEN];

    copy_arr(dArray1, dArray, ARRLEN);
    copy_ptr(dArray2, dArray, ARRLEN);
    copy_ptrs(dArray3, dArray, &dArray[0] + ARRLEN);

    printf("dArray1 = { ");
    for (int count = 0; count < ARRLEN; count++)
    {
        printf("%lf ", dArray1[count]);
    }
    putchar('}');
    putchar('\n');
    printf("dArray2 = { ");
    for (int count = 0; count < ARRLEN; count++)
    {
        printf("%lf ", dArray2[count]);
    }
    putchar('}');
    putchar('\n');
    printf("dArray3 = { ");
    for (int count = 0; count < ARRLEN; count++)
    {
        printf("%lf ", dArray3[count]);
    }
    putchar('}');
    putchar('\n');
}

void copy_arr(double *target, double *source, int n)
{
    int count;
    for (count = 0; count < n; count++)
    {
        target[count] = source[count];
    }
}

void copy_ptr(double *target, double *source, int n)
{
    for (int count = 0; count < n; count++)
    {
        *(target + count) = *(source + count);
    }
}

void copy_ptrs(double *target, double *source, double *lastSource)
{
    for (;source < lastSource; source++, target++)
    {
        *target = *source;
    }
}