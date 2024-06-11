// Write a function that returns the index of the largest value stored in an array-of-double.
// Test the function in a simple program.

#include <stdio.h>

#define ARRLEN 5

int indexOfLargest(double dArray[], int arrlen);

int main(void)
{
    double dArray[ARRLEN] = {8.6, 4.7, 7.4, 3.4, 10};
    int indexOfMax = indexOfLargest(dArray, ARRLEN);
    printf("indexOfMax in dArray = %d\n", indexOfMax);
    return 0;
}

int indexOfLargest(double dArray[], int arrlen)
{
    double max = dArray[0]; 
    int indexOfMax = 0;
    for (int index = 1; index < arrlen; index++)
    {
        if (dArray[index] > max)
        {
            max = dArray[index];
            indexOfMax = index;
        }
    }
    return indexOfMax;
}