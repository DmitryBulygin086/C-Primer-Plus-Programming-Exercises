// Generalize the to_binary() function of Listing 9.8 to a to_base_n() function that
// takes a second argument in the range 2–10. It then should print the number that is its
// first argument to the number base given by the second argument. For example, to_
// base_n(129,8) would display 201, the base-8 equivalent of 129. Test the function in a
// complete program.


#include <stdio.h>

// May handle only positive numbers
void to_base_n(unsigned dec, unsigned base);

int main(void)
{
    unsigned dec;
    unsigned base;
    printf("Enter decimal number and base to which you want to convert this decimal number: ");
    scanf("%u %u", &dec, &base);
    to_base_n(dec, base);
    putchar('\n');
    return 0;
}

void to_base_n(unsigned dec, unsigned base)
{
    if (dec >= base)
        to_base_n(dec / base, base);
    printf("%u", dec % base);
    return;
}