// The ABC Mail Order Grocery sells artichokes for $2.05 per pound, beets for $1.15 per
// pound, and carrots for $1.09 per pound. It gives a 5% discount for orders of $100 or
// more prior to adding shipping costs. It charges $6.50 shipping and handling for any
// order of 5 pounds or under, $14.00 shipping and handling for orders over 5 pounds
// and under 20 pounds, and $14.00 plus $0.50 per pound for shipments of 20 pounds or
// more. Write a program that uses a switch statement in a loop such that a response of a
// lets the user enter the pounds of artichokes desired, b the pounds of beets, c the pounds
// of carrots, and q allows the user to exit the ordering process. The program should keep
// track of cumulative totals. That is, if the user enters 4 pounds of beets and later enters
// 5 pounds of beets, the program should use report 9 pounds of beets. The program then
// should compute the total charges, the discount, if any, the shipping charges, and the
// grand total. The program then should display all the purchase information: the cost per
// pound, the pounds ordered, and the cost for that order for each vegetable, the total cost
// of the order, the discount (if there is one), the shipping charge, and the grand total of all
// the charges.

#include <stdio.h>
#include <stdbool.h>

#define ARTICHOKES_PER_POUND 2.05
#define BEETS_PER_POUND 1.15
#define CARROTS_PER_POUND 1.09

#define DISCOUNT 0.05
#define DISCOUNT_BRACKET 100.0

#define SHIPPING1 6.50
#define SHIPPING_BRACKET1 5

#define SHIPPING2 14.0
#define SHIPPING_BRACKET2 20

#define SHIPPING_MULTIPLIER_PER_POUND 0.5

void print_menu(void);
void flush_input_buffer(void);

int main(void)
{
    double pounds_of_artichokes, pounds_of_beets, pounds_of_carrots;
    char choice;
    double artichokes_cost = 0, beets_cost = 0, carrots_cost = 0;
    double subtotal_cost;
    bool exit_loop = false;
    double total_pounds = 0;
    double discount;
    double shipping;
    double grand_total;
    while (1)
    {
        print_menu();
        printf("Enter the character of desired vegetable: ");
        
        choice = getchar();
        
        switch(choice)
        {
            case 'a' :
                printf("Enter the amount of artichokes in pounds: ");
                while (scanf("%lf", &pounds_of_artichokes) != 1 || pounds_of_artichokes < 0)
                {
                    flush_input_buffer();
                    printf("Enter the amount of artichokes in pounds: ");
                }
                flush_input_buffer();
                artichokes_cost += pounds_of_artichokes * ARTICHOKES_PER_POUND;
                subtotal_cost += pounds_of_artichokes * ARTICHOKES_PER_POUND;
                total_pounds += pounds_of_artichokes;
                break;
            
            case 'b' :
                printf("Enter the amount of beets in pounds: ");
                while (scanf("%lf", &pounds_of_beets) != 1 || pounds_of_beets < 0)
                {
                    flush_input_buffer();
                    printf("Enter the amount of beets in pounds: ");
                }
                flush_input_buffer();
                beets_cost += pounds_of_beets * BEETS_PER_POUND;
                subtotal_cost += pounds_of_beets * BEETS_PER_POUND;
                total_pounds += pounds_of_beets;
                break;
            
            case 'c' :
                printf("Enter the amount of carrots in pounds: ");
                while (scanf("%lf", &pounds_of_carrots) != 1 || pounds_of_carrots < 0)
                {
                    flush_input_buffer();
                    printf("Enter the amount of carrots in pounds: ");
                }
                flush_input_buffer();
                carrots_cost += pounds_of_carrots * CARROTS_PER_POUND;
                subtotal_cost += pounds_of_carrots * CARROTS_PER_POUND;
                total_pounds += pounds_of_carrots;
                break;

            case 'q' :
                exit_loop = true;
                break;

            default :
                flush_input_buffer();
                printf("Invalid input.\n");
                continue;
        }
        if (exit_loop)
            break;
        //flush_input_buffer();

        printf("subtotal_cost = %lf\n", subtotal_cost);

    // Calculate discount
    if (subtotal_cost > 100.0)
    {
        discount = subtotal_cost * DISCOUNT;
    }
    printf("discount = %lf\n", discount);

    // Calculates shipping
    if (total_pounds > SHIPPING_BRACKET2)
    {
        shipping = (total_pounds - SHIPPING_BRACKET2) * SHIPPING_MULTIPLIER_PER_POUND + SHIPPING2;
    }
    else if (total_pounds > SHIPPING_BRACKET1)
    {
        shipping = SHIPPING2;
    }
    else 
        shipping = SHIPPING1;
    printf("shipping = %lf\n", shipping);

    // Calculates Grand total
    grand_total = subtotal_cost - discount + shipping;
    printf("grand_total = %lf\n", grand_total);


    // print pounds and costs for each vegetable
    printf("pounds_of_artichokes = %lf. $%lf/pound\n", pounds_of_artichokes, ARTICHOKES_PER_POUND);
    printf("pounds_of_beets = %lf. $%lf/pound\n", pounds_of_beets, BEETS_PER_POUND);
    printf("pounds_of_carrots = %lf. $%lf/pound\n", pounds_of_carrots, CARROTS_PER_POUND);

    // print total_pounds
    printf("total_pounds = %lf\n", total_pounds);

    // prints cost for each vegetable
    printf("artichokes_cost = %lf\n", artichokes_cost);
    printf("beets_cost = %lf\n", beets_cost);
    printf("carrots_cost = %lf\n", carrots_cost);

    // prints subtotal
    printf("subtotal_cost = %lf\n", subtotal_cost);

    // prints discount
    printf("discount = %lf\n", discount);

    // prints shipping charges
    printf("shipping = %lf\n", shipping);

    // prints grand_total
    printf("grand_total = %lf\n", grand_total);

    }
    
    return 0;
}

void print_menu(void)
{
    printf("Vegetable                  Cost\n");
    printf("a) Artichokes              $2.05/pound\n");
    printf("b) Beets                   $1.15/pound\n");
    printf("c) Carrots                 $1.09/pound\n");
    putchar('\n');
    printf("q) Quit\n");
}

void flush_input_buffer(void)
{
    while (getchar() != '\n')
        continue;
}