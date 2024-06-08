// Chuckie Lucky won a million dollars (after taxes), which he places in an account that
// earns 8% a year. On the last day of each year, Chuckie withdraws $100,000. Write a
// program that finds out how many years it takes for Chuckie to empty his account.

#include <stdio.h>


int main(void)
{
    const double WINNINGS = 1000000.0;
    const double INTEREST = 0.08;
    const double WITHDRAWS_PER_YEAR = 100000.0;

    double chuckie_balance = WINNINGS;
    unsigned int years = 0;

    while (chuckie_balance >= 0)
    {
        chuckie_balance -= WITHDRAWS_PER_YEAR; // assume that first withdraw was before any earning
        chuckie_balance += (chuckie_balance * INTEREST);
        years++;
    }

    printf("years = %u\n", years);
    return 0;
}