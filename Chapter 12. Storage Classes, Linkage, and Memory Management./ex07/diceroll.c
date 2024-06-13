/* diceroll.c -- dice role simulation */
/* compile with manydice.c           */
#include "diceroll.h"
#include <stdio.h>
#include <stdlib.h>         /* for library rand() */

int roll_count = 0;         /* external linkage  */

static int rollem(int sides)    /* private to this file */
{
    int roll;

    roll = rand() % (sides + 1);
    ++roll_count;           /* count function calls */
    
    return roll;
}

int roll_n_dice(int dice, int sides)
{
    int d;
    int total = 0;
    if (sides < 2)
    {
        printf("Need at least 2 sides.\n");
        return -2;
    }

    if (dice < 1)
    {
        printf("Need at least 1 die.\n");
        return -1;
    }

    for (d = 0; d < dice; d++)
    {
        total += rollem(sides);
    }

    return total;
}

void roll_n_sets(int sets_len, int sets[sets_len],  int dice, int sides)
{
    int s;

    for (s = 0; s < sets_len; s++)
    {
        sets[s] = roll_n_dice(dice, sides);
    }
}

void print_array_contents(int size,int array[size])
{
    int ct = 0;
    for (int i = 0; i < size; i++)
    {
        printf("%2d ", array[i]);
        ct++;
        if (ct % 16 == 15)
            putchar('\n');
    }
}

void eat_newline(void)
{
    while (getchar() != '\n')
    {
        continue;
    }
}