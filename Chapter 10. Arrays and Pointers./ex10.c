// Write a function that sets each element in an array to the sum of the corresponding
// elements in two other arrays. That is, if array 1 has the values 2, 4, 5, and 8 and array 2
// has the values 1, 0, 4, and 6, the function assigns array 3 the values 3, 4, 9, and 14. The
// function should take three array names and an array size as arguments. Test the function
// in a simple program.

#include <stdio.h>
#define ARRLEN 4

void sum(int *target, int *src1, int *src2, int arrlen);
void print_1Darray(int *array, int arrlen);   
int main(void)
{
    int src1[ARRLEN] = {3, 6, 3, 4};
    int src2[ARRLEN] = {7, 9, -3, 4};
    int target[ARRLEN];
    sum(target, src1, src2, ARRLEN);

    puts("target:");
    print_1Darray(target, ARRLEN);
    putchar('\n');
    return 0;
}

void sum(int *target, int *src1, int *src2, int arrlen)
{
    for(int index = 0; index < arrlen; index++)
    {
        target[index] = src1[index] + src2[index];
    }
}

void print_1Darray(int *array, int arrlen)
{
    for (int index = 0; index < arrlen; index++)
    {
        printf("%d ", array[index]);
    }
}