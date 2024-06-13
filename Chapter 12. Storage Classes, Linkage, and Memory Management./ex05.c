// Write a program that generates a list of 100 random numbers in the range 1–10
// in sorted decreasing order. (You can adapt the sorting algorithm from Chapter 11,
// “Character Strings and String Functions,” to type int. In this case, just sort the numbers
// themselves.)

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
void sortDecr(int size, int array[size]);
void printArr(int size, int array[size]);
int main(void)
{
    int randNums[SIZE];
    for (unsigned count = 0; count < SIZE; count++)
    {
        randNums[count] = rand() % (10 + 1);
    }
    puts("Random array before sorting:");
    printArr(SIZE, randNums);
    putchar('\n');

    puts("Array after sorting:");
    sortDecr(SIZE, randNums);
    printArr(SIZE, randNums);
    return 0;
}

void sortDecr(int size, int array[size])
{
    int temp;
    for (unsigned i = 0; i < SIZE - 1; i++)
    {
        for (unsigned j = i + 1; j < SIZE; j++)
        {
            if (array[i] < array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void printArr(int size, int array[size])
{
    
    for (int count = 0; count < size; count++)
    {
        printf("%2d ", array[count]);
        if (count % 10 == 9)
        {
            putchar('\n');
        }
    }
}