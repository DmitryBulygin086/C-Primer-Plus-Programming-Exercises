/* manydice.c -- multiple dice rolls */
/* compile with diceroll.c           */
#include <stdio.h>
#include <stdlib.h>         /* for library srand() */
#include <time.h>           /* for time()          */
#include "diceroll.h"       /* for roll_n_sets()  */
/* and for roll_count */

int main(void)
{
    int dice, roll, sets_len;
    int sides;
    int status;


    srand((unsigned int) time(0));  /* randomize seed   */
    printf("Enter the number of sets; enter q to stop: ");
    while (status = (scanf("%d", &sets_len)) == 1)
    {
        if (sets_len <= 0)
        {
            printf("Invalid input. Try again.\n");
            printf("Enter the number of sets; enter q to stop: ");
            continue;
        }
        int sets[sets_len];
        
        printf("How many sides and how many dice? ");
        while ((scanf("%d %d", &sides, &dice) != 2) || sides <= 0 || dice <= 0)
        {
            eat_newline();
            printf("Invalid input. Try again.\n");
            printf("How many sides and how many dice? ");
        }
        roll_n_sets(sets_len,sets, dice, sides);
        printf("Here are %d sets of %d %d-sides throws.\n", sets_len, dice, sides);
        print_array_contents(sets_len, sets);
        putchar('\n');

        printf("How many sets? Enter q to stop: ");
    }
    printf("The rollem() function was called %d times.\n",
            roll_count);        /* use extern variable */
    printf("GOOD FORTUNE TO YOU!\n");

    return 0;
}