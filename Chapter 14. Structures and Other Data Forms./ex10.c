// Write a program that implements a menu by using an array of pointers to functions. For
// instance, choosing a from the menu would activate the function pointed to by the first
// element of the array.

#include <stdio.h>
#define SIZE 4
void eatline(void);

double sum(double n1, double n2);

double subtract(double n1, double n2);

double multiply(double n1, double n2);

double divide(double n1, double n2);
int main(void)
{
    double n1, n2;
    typedef double (*dpfdd)(double, double);
    dpfdd pf[SIZE] = {sum, subtract, multiply, divide};
    char choice;
    char action;
    double result;

    while (1)
    {
        printf("Enter two numbers(nonnumeric input to quit): ");
        if((scanf("%lf %lf", &n1, &n2) != 2))
        {
            eatline();
            break;
        }
        eatline();

        printf("a) Add two numbers\n");
        printf("b) Subtract two numbers\n");
        printf("c) Multiply two numbers\n");
        printf("d) Divide two numbers\n");
        choice = getchar();
        eatline();
        choice -= 'a';

        if (choice < 0 || choice >= SIZE)
        {
            fprintf(stderr, "Invalid input.Try again.\n");
            continue;
        }
        printf("result = %lf\n", pf[choice](n1, n2));
    }

    return 0;
}

void eatline(void)
{
    while (getchar()!= '\n')
        continue;
}

double sum(double n1, double n2)
{
    return ((n1) + (n2));
}

double subtract(double n1, double n2) {return ((n1) - (n2));}

double multiply(double n1, double n2) {return ((n1) * (n2));}

double divide(double n1, double n2) {return ((n1) / (n2));}