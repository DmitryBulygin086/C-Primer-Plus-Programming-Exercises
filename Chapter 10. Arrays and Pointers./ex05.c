// Write a function that returns the difference between the largest and smallest elements of
// an array-of-double. Test the function in a simple program.

#include <stdio.h>

#define ARRLEN 5

double dif(double dArray[], int arrlen);

int main(void)
{
    double dArray[ARRLEN] = {12, 7.5, 15, 8.3, 2};
    double difBetweenMaxMin = dif(dArray, ARRLEN);
    printf("difBetweenMaxMin = %lf\n", difBetweenMaxMin);
    return 0;
}

double dif(double dArray[], int arrlen)
{
    double min = dArray[0], max = dArray[0];
    for (int index = 0; index < arrlen; index++)
    {
        if (dArray[index] > max)
            max = dArray[index];
        if (dArray[index] < min)
            min = dArray[index];
    }
    return max - min;
}