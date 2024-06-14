// Do Programming Exercise 12, but use variable-length arrays (VLAs) instead of standard
// arrays.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 20
#define COLS 30

const char trans[11] = " .':~*=&@#";

void eat_newline(void);
int main(void)
{
    
    FILE *fp;
    int rows, cols;

    printf("Enter resoulution of the picture: rows, columns: ");
    while (scanf("%d %d", &rows, &cols) != 2)
    {
        eat_newline();
        printf("Enter resoulution of the picture: rows, columns: ");
    }
    eat_newline();

    int array[rows][cols]; // cols + 1 to store '\0'

    printf("Enter %d rows of %d integers. The integers should be in the range 0-9.\n", rows, cols);
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            scanf("%d", &array[row][col]);
        }
        array[row][cols] = '\0';
    }

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

void eat_newline(void)
{
    while (getchar() != '\n')
    {
        continue;
    }
}