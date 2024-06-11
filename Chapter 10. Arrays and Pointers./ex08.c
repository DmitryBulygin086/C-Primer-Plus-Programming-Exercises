// Use a copy function from Programming Exercise 2 to copy the third through fifth
// elements of a seven-element array into a three-element array. The function itself need
// not be altered; just choose the right actual arguments. (The actual arguments need not be
// an array name and array size. They only have to be the address of an array element and a
// number of elements to be processed.)

#include <stdio.h>

void copy_ptrs(double *target, double *source, double *lastSource);

int main(void)
{
    int array[7] = {3, 4, 2, 3, 4, 67, 34};
    int array1[3];
    copy_ptrs(array1, array + 2, (array + 2 )+ 3);

    printf("array1:\n");
    for (int index = 0; index < 3; index++)
    {
        printf("%d ", array1[index]);
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