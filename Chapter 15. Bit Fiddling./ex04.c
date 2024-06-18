// Write a function that takes two int arguments: a value and a bit position. Have the
// function return 1 if that particular bit position is 1, and have it return 0 otherwise. Test
// the function in a program.
#include <stdio.h>
#include <stdbool.h>

bool pos_checker(int dec, int pos);

void eatline(void) { while (getchar() != '\n') continue;}
int main(void)
{
    int input;
    int pos;
    while (1)
    {
        printf("Enter a decimal value(non-numeric input to quit): ");
        if (scanf("%d", &input) != 1)
        {
            eatline();
            break;
        }
        eatline();

        printf("Enter a bit position: ");
        while(scanf("%d", &pos)!= 1)
        {
            fprintf(stderr, "Enter an integer: ");
        }

        printf("%d bit in %d is turned %s\n", pos, input, pos_checker(input, pos) ? "on" : "off");
    }
}

bool pos_checker(int dec, int pos)
{
    int mask = 1;
    mask = mask << pos;
    return (dec & mask);
}