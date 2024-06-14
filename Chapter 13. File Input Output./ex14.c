// Digital images, particularly those radioed back from spacecraft, may have glitches. Add
// a de-glitching function to programming exercise 12. It should compare each value to its
// immediate neighbors to the left and right, above and below. If the value differs by more
// than 1 from each of its neighbors, replace the value with the average of the neighboring
// values. You should round the average to the nearest integer value. Note that the points
// along the boundaries have fewer than four neighbors, so they require special handling.

// If error, try to compile like this:
// gcc -o ex14 ex14.c -lm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ROWS 20
#define COLS 30

const char trans[11] = " .':~*=&@#";

void deglitch(int rows, int cols, int array[rows][cols]);
int main(void)
{
    int array[ROWS][COLS];
    FILE *fp;

    puts("Enter 20 rows of 30 integers. The integers should be in the range 0-9.");
    for (int row = 0; row < ROWS; row++)
    {
        
        for (int col = 0; col < COLS; col++)
        {
            scanf("%d", &array[row][col]);
        }
        array[row][COLS] = '\0'; 
    }

    deglitch(ROWS, COLS, array);



    fp = fopen("pic.txt", "w");
    if (fp == NULL)
    {
        fprintf(stderr,"Could not open file.\n");
        exit(EXIT_FAILURE);
    }

    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col <= COLS; col++)
        {
            fprintf(fp, "%c", trans[array[row][col]]);
        }
        putc('\n', fp);
    }

    printf("\nSee your pic.txt file.\n");
    
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Could not close file.\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}

void deglitch(int rows, int cols,int array[rows][cols])
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (row == 0)
            {
                if (col == 0)   // left top angle
                {
                    if (array[row][col] - array[row][col + 1] > 1 ||  array[row][col] - array[row + 1][col] > 1)
                    {
                        array[row][col] = rint((array[row][col + 1]  + array[row + 1][col]) / (double)2);
                    }     
                }
                else if (col = cols - 1)    // right top angle
                {
                    if (array[row][col] - array[row][col - 1] > 1 ||  array[row][col] - array[row + 1][col] > 1)
                    {
                        array[row][col] = rint((array[row][col - 1]  + array[row + 1][col]) / (double)2);
                    }     
                }

                else    // first row
                {
                    if (array[row][col] - array[row][col + 1] > 1 ||  array[row][col] - array[row + 1][col] > 1 || array[row][col] - array[row][col - 1] > 1)
                        {
                            array[row][col] = rint((array[row][col + 1]  + array[row + 1][col] + array[row][col-1])) / (double)3;
                        } 
                }    
            }
            else if (row == rows - 1) // bottom row
            {
                if (col == 0)   // left bottom angle
                {
                    if (array[row][col] - array[row][col + 1] > 1 ||  array[row][col] - array[row - 1][col] > 1)
                    {
                        array[row][col] = rint((array[row][col + 1]  + array[row - 1][col]) / (double)2);
                    }     
                }
                else if (col = cols - 1)    // right bottom angle
                {
                    if (array[row][col] - array[row][col - 1] > 1 ||  array[row][col] - array[row - 1][col] > 1)
                    {
                        array[row][col] = rint((array[row][col - 1]  + array[row - 1][col]) / (double)2);
                    }
                }
                else    // bottom row
                {
                    if (array[row][col] - array[row][col + 1] > 1 ||  array[row][col] - array[row - 1][col] > 1 || array[row][col] - array[row][col - 1] > 1)
                        {
                            array[row][col] = rint((array[row][col + 1]  + array[row - 1][col] + array[row][col-1]) / (double)3);
                        }
                }  
            }

            else if (col == 0)  // left side
            {
                if (row == 0)   // left top angle
                {
                    if (array[row][col] - array[row][col + 1] > 1 ||  array[row][col] - array[row + 1][col] > 1)
                    {
                        array[row][col] = rint((array[row][col + 1]  + array[row + 1][col]) / (double)2);
                    }
                }
                if (row == rows - 1)   // left bottom angle
                {
                    if (array[row][col] - array[row][col + 1] > 1 ||  array[row][col] - array[row - 1][col] > 1)
                    {
                        array[row][col] = rint((array[row][col + 1]  + array[row - 1][col]) / (double)2);
                    }
                }
            }

            else if (col == cols - 1)  // right side
            {
                if (row == 0)   // right top angle
                {
                    if (array[row][col] - array[row][col - 1] > 1 ||  array[row][col] - array[row + 1][col] > 1)
                    {
                        array[row][col] = rint((array[row][col - 1]  + array[row + 1][col]) / (double)2);
                    }
                }
                if (row == rows - 1)   // right bottom angle
                {
                    if (array[row][col] - array[row][col - 1] > 1 ||  array[row][col] - array[row - 1][col] > 1)
                    {
                        array[row][col] = rint((array[row][col - 1]  + array[row - 1][col]) / (double)2);
                    }
                }
            }

            else
            {
                if (array[row][col] - array[row][col - 1] > 1 || array[row][col] - array[row][col + 1] > 1 || 
                    array[row][col] - array[row - 1][col] > 1 || array[row][col] - array[row + 1][col] > 1)
                {
                    array[row][col] = rint((array[row][col - 1] + array[row][col + 1] + array[row - 1][col] + array[row + 1][col]) / (double)4);
                }
            }
        }
    }
}