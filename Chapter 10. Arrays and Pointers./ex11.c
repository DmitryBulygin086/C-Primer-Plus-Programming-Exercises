// Write a program that declares a 3×5 array of int and initializes it to some values of
// your choice. Have the program print the values, double all the values, and then display
// the new values. Write a function to do the displaying and a second function to do the
// doubling. Have the functions take the array name and the number of rows as arguments.

#include <stdio.h>
#define ROWS 3
#define COLS 5

void print2Darray(int rows, int cols, int array[rows][cols]);
void double2Darray(int rows, int cols, int array[rows][cols]);
int main(void)
{
    int array[ROWS][COLS] = {{4, 6, 4, 4, 2},
                             {3, 7, 2, 9, 3},
                             {9, 4, 1, 1, 2}};
    puts("array before doubling:");
    print2Darray(ROWS, COLS, array);
    putchar('\n');

    puts("array after doubling:");
    double2Darray(ROWS, COLS, array);
    print2Darray(ROWS, COLS, array);
    putchar('\n');
    return 0;
}

void print2Darray(int rows, int cols, int array[rows][cols])
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            printf("%5d", array[row][col]);
        }
        putchar('\n');
    }
}

void double2Darray(int rows, int cols, int array[rows][cols])
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            array[row][col] *= 2;
        }
    }
}