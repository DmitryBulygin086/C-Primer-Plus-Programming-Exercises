// Write a program that initializes a two-dimensional array-of-double and uses one of the
// copy functions from exercise 2 to copy it to a second two-dimensional array. (Because a
// two-dimensional array is an array of arrays, a one-dimensional copy function can be used
// with each subarray.)

#include <stdio.h>

#define ROWS 3
#define ELEMS 3

void copy_ptrs(double *target, double *source ,double *lastSource);

int main(void)
{
    double array[ROWS][ELEMS] = {{3.6,  3.76,  7.4}, 
                                 {6.4,  1.3,   4.6}, 
                                 {4,    6,     7}};
    double array_copy[ROWS][ELEMS];

    for (int row = 0; row < ROWS; row++)
    {
        copy_ptrs(array_copy[row], array[row], array[row] + ROWS);
    }

    printf("array_copy:\n");
    for (int row = 0; row < ROWS; row++)
    {
        for (int elem = 0; elem < ELEMS; elem++)
        {
            printf("%lf ", array_copy[row][elem]);
        }
        putchar('\n');
    }
    putchar('\n');
    return 0;
}

void copy_ptrs(double *target, double *source, double *lastSource)
{
    for (;source < lastSource; source++, target++)
    {
        *target = *source;
    }
}