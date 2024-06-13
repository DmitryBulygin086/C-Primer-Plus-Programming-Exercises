// Redesign the program described in Programming Exercise 2 so that it uses only automatic
// variables. Have the program offer the same user interface—that is, it should prompt the
// user to enter a mode, and so on. You’ll have to come up with a different set of function
// calls, however.
// pe12-3b.c
// compile with pe12-3a.c
#include <stdio.h>
#include "pe12-3a.h"
int main(void)
{
    int mode;
    double distance, fuel_consumed;
    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    eat_newline();
    while (mode >= 0)
    {
        set_mode(&mode);
        get_info(mode, &distance, &fuel_consumed);
        show_info(mode, distance, fuel_consumed);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
        eat_newline();
    }
    printf("Done.\n");
    return 0;
}
