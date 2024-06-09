// The 1988 United States Federal Tax Schedule was the simplest in recent times. It had
// four categories, and each category had two rates. Here is a summary (dollar amounts are
// taxable income):
// Category                 Tax
// Single                   15% of first $17,850 plus 28% of excess
// Head of Household        15% of first $23,900 plus 28% of excess
// Married, Joint           15% of first $29,750 plus 28% of excess
// Married, Separate        15% of first $14,875 plus 28% of excess

// For example, a single wage earner with a taxable income of $20,000 owes 0.15 × $17,850
// + 0.28 × ($20,000−$17,850). Write a program that lets the user specify the tax category
// and the taxable income and that then calculates the tax. Use a loop so that the user can
// enter several tax cases.

#include <stdio.h>
#include <stdbool.h>
#define TAX_BRACKET1 17850
#define TAX_BRACKET2 23900
#define TAX_BRACKET3 29750
#define TAX_BRACKET4 14875
#define TAX_RATE1 0.15
#define TAX_RATE2 0.28
void print_menu(void);
void flush_input_buffer(void);
int main(void)
{
    
    while (1)
    {
        char category;
        double taxable_income;
        double bracket;
        double tax;
        bool exit_flag = false;
        print_menu();
        category = getchar();

        switch(category)
        {
            case '1' :
                bracket = TAX_BRACKET1;
                break;
            case '2' :
                bracket = TAX_BRACKET2;
                break;
            case '3' :
                bracket = TAX_BRACKET3; 
                break;
            case '4' :
                bracket = TAX_BRACKET4;
                break;
            case '5' :
                return 0;
            default :
                printf("Invalid input.\n");
                continue;
        }
        
        
        printf("Enter a taxable income: ");
        while ((scanf("%lf", &taxable_income)) != 1 || taxable_income < (double)0.0)
        {
            flush_input_buffer();
            printf("Enter a taxable income: ");
        }
        flush_input_buffer(); // eat newline

        if (taxable_income > bracket)
        {
            tax = bracket * TAX_RATE1 + (taxable_income - bracket) * TAX_RATE2;
        }
        else 
            tax = taxable_income * TAX_RATE1;

        printf("tax = %lf\n", tax);
    }
    return 0;
}

void print_menu(void)
{
    printf("Category                 Tax\n"
                  "1)Single                   15%% of first $17,850 plus 28%% of excess\n"
                  "2)Head of Household        15%% of first $23,900 plus 28%% of excess\n"
                  "3)Married, Joint           15%% of first $29,750 plus 28%% of excess\n"
                  "4)Married, Separate        15%% of first $14,875 plus 28%% of excess\n"
                  "5)Quit\n\n"
                  "Enter your category: ");
}

void flush_input_buffer(void)
{
    while (getchar() != '\n')
        continue;
}