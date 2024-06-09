// Modify Programming Exercise 8 from Chapter 7 so that the menu choices are labeled by
// characters instead of by numbers; use q instead of 5 as the cue to terminate input.

// Exercise 8 from Chapter 7
// Modify assumption a. in exercise 7 so that the program presents a menu of pay rates
// from which to choose. Use a switch to select the pay rate. The beginning of a run
// should look something like this:
// *****************************************************************
// Enter the number corresponding to the desired pay rate or action:
// 1) $8.75/hr
// 2) $9.33/hr
// 3) $10.00/hr
// 4) $11.20/hr
// 5) quit
// *****************************************************************
// If choices 1 through 4 are selected, the program should request the hours worked. The
// program should recycle until 5 is entered. If something other than choices 1 through 5
// is entered, the program should remind the user what the proper choices are and then
// recycle. Use #defined constants for the various earning rates and tax rates.

// Exercise 7 from Chapter 7
// Write a program that requests the hours worked in a week and then prints the gross pay,
// the taxes, and the net pay. Assume the following:
// a. Basic pay rate = $10.00/hr
// b. Overtime (in excess of 40 hours) = time and a half
// c. Tax rate: #15% of the first $300
// 20% of the next $150
// 25% of the rest
// Use #define constants, and don’t worry if the example does not conform to current
// tax law.

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define PAY_RATE1 8.75
#define PAY_RATE2 9.33
#define PAY_RATE3 10.00
#define PAY_RATE4 11.20


#define OVER_HOURS 40.0
#define OVER_MULTIPLIER 1.5

#define TAX_BRACKET1   300.0
#define TAX_RATE1      0.15

#define TAX_BRACKET2   (TAX_BRACKET1 + 150.0)
#define TAX_RATE2 0.2

#define TAX_RATE3 0.25

void flush_input_buffer(void);
void print_menu(void);
double gross(double hours, double pay_rate);
double tax(double gross_pay);

char get_first(void);

int main(void)
{
    char choice;
    double pay_rate;
    bool exit_flag = false;
    double hours;
    double gross_pay;
    double taxes;
    double net_pay;
    while (1)
    {
        print_menu();
        choice = get_first();
        
        
        switch(choice)
        {
            case 'a':
                pay_rate = PAY_RATE1;
                break;
            case 'b' :
                pay_rate = PAY_RATE2;
                break;
            case 'c': 
                pay_rate = PAY_RATE3;
                break;
            case 'd' :
                pay_rate = PAY_RATE4;
                break;
            case 'q' :
                exit_flag = true;
                break;
                continue;
            default :
                flush_input_buffer();
                printf("Invalid input. Try again.\n");
                continue;
        }
        
        if (exit_flag)
            break;

        
        printf("Enter hours worked in a week: "); 
        while((scanf("%lf", &hours)) != 1 || hours < 0)
        {
            flush_input_buffer();
            printf("Please enter a positive number.\n");
            printf("Enter hours worked in a week: "); 
        }

        gross_pay = gross(hours, pay_rate);
        
        taxes = tax(gross_pay);

        net_pay = gross_pay - taxes;

        printf("gross_pay = %lf\n", gross_pay);
        printf("taxes = %lf\n", taxes);
        printf("net_pay = %lf\n", net_pay);
    }
    return 0;
}

double gross(double hours, double pay_rate)
{
    double gross_pay;
    if (hours <= OVER_HOURS)
    {
        gross_pay = hours * pay_rate;
    }
    else 
    {
        gross_pay = pay_rate * OVER_HOURS + (hours - OVER_HOURS) * pay_rate * OVER_MULTIPLIER;
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

void print_menu(void)
{
    printf("*****************************************************************\n"
            "Enter the character corresponding to the desired pay rate or action:\n"
            "a) $8.75/hr\n"
            "b) $9.33/hr\n"
            "c) $10.00/hr\n"
            "d) $11.20/hr\n"
            "q) quit\n"
            "*****************************************************************\n");
}

void flush_input_buffer(void)
{
    while (getchar() != '\n')
        continue;
}

char get_first(void)
{
    char ch, garbage;
    do 
    {
        (ch = getchar());
    }
    while ((isspace(ch)));

    while ((garbage = getchar()) != '\n' && garbage != EOF)
        continue;
    return ch;
}
