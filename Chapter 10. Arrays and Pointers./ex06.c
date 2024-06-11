// Write a function that reverses the contents of an array of double and test it in a simple
// program.

#include <stdio.h>

#define ARRLEN 4

void reverse(double *array, int arrlen);

int main(void)
{
    double array[ARRLEN] = {4, 5.6, 3.6, 3};
    printf("Initialy array was:\n");
    for (int index = 0; index < ARRLEN; index++)
    {
        printf("%lf ", array[index]);
    }
    putchar('\n');
    reverse(array, ARRLEN);

    printf("After reverse array is:\n");
    for (int index = 0; index < ARRLEN; index++)
    {
        printf("%lf ", array[index]);
    }
    return 0;
}

void reverse(double *array, int arrlen)
{
    double temp;

    for (int index = 0; index < arrlen / 2; index++)
    {
        temp = array[index];
        array[index] = array[(arrlen - 1) - index];
        array[(arrlen - 1) - index] = temp;

    }
}

