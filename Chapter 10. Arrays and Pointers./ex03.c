// Write a function that returns the largest value stored in an array-of-int. Test the function
// in a simple program.

#include <stdio.h>

#define ARRLEN 5

int iLargestInArray(int array[], int arrlen);

int main(void)
{
    int array[5] = {9, 4, 3, 4, 8};
    int largest = iLargestInArray(array, ARRLEN);
    printf("largest = %d\n", largest);
    return 0;
}

int iLargestInArray(int array[], int arrlen)
{
    int max = array[0];
    for (int count = 1; count < arrlen; count++)
    {
        if (array[count] > max)
        {
            max = array[count];
        }
    }
    return max;
}