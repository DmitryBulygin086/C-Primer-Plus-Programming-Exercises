// Daphne invests $100 at 10% simple interest. (That is, every year, the investment earns
// an interest equal to 10% of the original investment.) Deirdre invests $100 at 5% interest
// compounded annually. (That is, interest is 5% of the current balance, including previous
// addition of interest.) Write a program that finds how many years it takes for the value
// of Deirdre’s investment to exceed the value of Daphne’s investment. Also show the two
// values at that time.


#include <stdio.h>

// the investment earns
// an interest equal to 10% of the original investment
#define DAPHNE_SIMPLE_INTEREST 0.1

// interest is 5% of the current balance, including previous
// addition of interest
#define DEIRDRE_COMPOUND_INTEREST 0.05

#define INIT_INV_DEAPHNE 100
#define INIT_INV_DEIRDRE 100

int main(void)
{
    // Write a program that finds how many years it takes for the value
    // of Deirdre’s investment to exceed the value of Daphne’s investment.
    double daphne_balance = INIT_INV_DEAPHNE;
    double deirdre_balance = INIT_INV_DEIRDRE;

    unsigned int years = 0;

    for(; deirdre_balance <= daphne_balance; years++)
    {
        deirdre_balance += deirdre_balance * DEIRDRE_COMPOUND_INTEREST;
        daphne_balance  += INIT_INV_DEAPHNE * DAPHNE_SIMPLE_INTEREST;
    }

    printf("years = %u\n", years);


    //Also show the two
    // values at that time.
    printf("deirdre_balance = %lf\n", deirdre_balance);
    printf("daphne_balance = %lf\n", daphne_balance);
    return 0;
    
}
