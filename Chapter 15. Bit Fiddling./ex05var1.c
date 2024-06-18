// Write a function that rotates the bits of an unsigned int by a specified number of bits
// to the left. For instance, rotate_l(x,4) would move the bits in x four places to the left,
// and the bits lost from the left end would reappear at the right end. That is, the bit moved
// out of the high-order position is placed in the low-order position. Test the function in a
// program.
#include <stdio.h>
#include <limits.h>



void rotate_l(unsigned int *x, unsigned int nbits);

int main(void)
{
    unsigned int input;
    unsigned int nbits;
    while (1)
    {
        printf("Enter an unsigned int(non-numeric input to quit): ");
        if (scanf("%u", &input) != 1)
        {
            break;
        }

        printf("Enter number of bits to rotate: ");
        while (scanf("%u", &nbits) != 1)
        {
            fprintf(stderr, "Invalid input, try again.\n");
            printf("Enter number of bits to rotate: ");
        }

        rotate_l(&input, nbits);

        printf("%u\n", input);
    }
}

void rotate_l(unsigned int *x, unsigned int nbits)
{
    unsigned int temp = *x;
    *x = (*x << nbits) | (temp >> ((sizeof(unsigned int) * CHAR_BIT) - nbits));
}