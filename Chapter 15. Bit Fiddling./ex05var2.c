// Write a function that rotates the bits of an unsigned int by a specified number of bits
// to the left. For instance, rotate_l(x,4) would move the bits in x four places to the left,
// and the bits lost from the left end would reappear at the right end. That is, the bit moved
// out of the high-order position is placed in the low-order position. Test the function in a
// program.
#include <stdio.h>
#include <limits.h>


const unsigned int BITS_IN_INT = (sizeof(unsigned int) * CHAR_BIT);
const unsigned int MOST_SIGN_BIT_MASK = 1 << (BITS_IN_INT - 1);
void rotate_l(unsigned int *x, unsigned int nbits);


char *to_bin_str(unsigned int dec, unsigned int strlength, char str[strlength]);

int main(void)
{
    unsigned int input;
    unsigned int nbits;
    unsigned int strlength = BITS_IN_INT + 1;
    char binstr[strlength];
    while (1)
    {
        printf("Enter an unsigned int(non-numeric input to quit): ");
        if (scanf("%u", &input) != 1)
        {
            break;
        }

        printf("%s\n", to_bin_str(input, strlength, binstr));

        printf("Enter number of bits to rotate: ");
        while (scanf("%u", &nbits) != 1)
        {
            fprintf(stderr, "Invalid input, try again.\n");
            printf("Enter number of bits to rotate: ");
        }

        rotate_l(&input, nbits);

        printf("%u\n", input);
        printf("%s\n", to_bin_str(input, strlength, binstr));
    }
}

void rotate_l(unsigned int *x, unsigned int nbits)
{
    unsigned int leftbit;
    for (int i = 0; i < nbits; i++)
    {
        leftbit = (*x & MOST_SIGN_BIT_MASK);
        *x <<= 1;
        if (leftbit)
        {
            *x |= 1;
        }
    }
}

char * to_bin_str(unsigned int dec, unsigned int strlength, char str[strlength])
{
    int i = strlength - 1;
    
    str[i] = '\0';
    i--;
    for (; i >= 0; i--)
    {
        str[i] = (dec & 01) + '0';
        dec >>= 1;
    }
    return str;
}