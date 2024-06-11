// Write a program that initializes a two-dimensional 3×5 array-of-double and uses a VLA-
// based function to copy it to a second two-dimensional array. Also provide a VLA-based
// function to display the contents of the two arrays. The two functions should be capable,
// in general, of processing arbitrary N×M arrays. (If you don’t have access to a VLA-capable
// compiler, use the traditional C approach of functions that can process an N×5 array).

#include <stdio.h>
#define ROWS 3
#define COLS 5

void copy(int rows, int cols, double target[rows][cols], double src[rows][cols]);
void display(int rows, int cols, double array[rows][cols]);
int main(void)
{
    double array[ROWS][COLS] = {{3.4, 6, 34, 3,  2},
                                {3,   4, 6,  4,  3},
                                {4,   2, 4,  23, 4}};
    double array_copy[ROWS][COLS];

    copy(ROWS, COLS, array_copy, array);

    printf("array:\n");
    display(ROWS, COLS, array);
    putchar('\n');

    puts("array_copy:");
    display(ROWS, COLS, array_copy);
    putchar('\n');

    return 0;
}

void copy(int rows, int cols, double target[rows][cols], double src[rows][cols])
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            target[row][col] = src[row][col];
        }
    }
}

void display(int rows, int cols, double array[rows][cols])
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            printf("%6.1lf", array[row][col]);
        }
        putchar('\n');
    }
}

