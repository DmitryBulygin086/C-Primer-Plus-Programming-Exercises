// Write a program that requests the hours worked in a week and then prints the gross pay,
// the taxes, and the net pay. Assume the following:
//      a. Basic pay rate = $10.00/hr
//      b. Overtime (in excess of 40 hours) = time and a half
//      c. Tax rate:    15% of the first $300
//                      20% of the next $150
//                      25% of the rest
// Use #define constants, and don’t worry if the example does not conform to current
// tax law.

#include <stdio.h>

#define BASIC_PAY_RATE_PER_HOUR 10.0
#define OVER_HOURS 40.0
#define OVER_MULTIPLIER 1.5

#define TAX_BRACKET1   300.0
#define TAX_RATE1      0.15

#define TAX_BRACKET2   (TAX_BRACKET1 + 150.0)
#define TAX_RATE2 0.2

#define TAX_RATE3 0.25

double gross(double hours);
double tax(double gross_pay);

int main(void)
{
    double hours;
    double gross_pay;
    double taxes;
    printf("Enter hours worked in a week: "); scanf("%lf", &hours);

    gross_pay = gross(hours);
    
    taxes = tax(gross_pay);

    double net_pay = gross_pay - taxes;

    printf("gross_pay = %lf\n", gross_pay);
    printf("taxes = %lf\n", taxes);
    printf("net_pay = %lf\n", net_pay);
    return 0;
}

double gross(double hours)
{
    double gross_pay;
    if (hours <= OVER_HOURS)
    {
        gross_pay = hours * BASIC_PAY_RATE_PER_HOUR;
    }
    else 
    {
        gross_pay = BASIC_PAY_RATE_PER_HOUR * OVER_HOURS + (hours - OVER_HOURS) * BASIC_PAY_RATE_PER_HOUR * OVER_MULTIPLIER;
    }
    return gross_pay;
}

double tax(double gross_pay)
{
    double taxes;
    if (gross_pay <= TAX_BRACKET1)
    {
        taxes = gross_pay * TAX_RATE1;
    }
    else if (gross_pay > TAX_BRACKET1 && gross_pay <= TAX_BRACKET2)
    {
        taxes =      TAX_BRACKET1 * TAX_RATE1
                  + ((gross_pay - TAX_BRACKET1) * TAX_RATE2);
              
    }
    else if (gross_pay > TAX_BRACKET2)
    {
        taxes =     TAX_BRACKET1 * TAX_RATE1
                  + ((TAX_BRACKET2 - TAX_BRACKET1) * TAX_RATE2)
                  + ((gross_pay - TAX_BRACKET2) * TAX_RATE3);
    }
    return taxes; 
}