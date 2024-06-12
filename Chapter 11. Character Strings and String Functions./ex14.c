// Write a power-law program that works on a command-line basis. The first command-line
// argument should be the type double number to be raised to a certain power, and the
// second argument should be the integer power.

// compile from terminal like this 
// gcc -o ex14 ex14.c -lm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    double dNum;
    int iPow;
    bool neg_pow = false;
    if (argc != 3)
    {
        printf("Usage: %s [double number] [integer power]\n", argv[0]);
        return 1;
    }
    else 
    {
        dNum = atof(argv[1]);
        iPow = atof(argv[2]);

       

        printf("%s to the power of %s is %lf\n", argv[1], argv[2], pow(dNum, iPow));
        return 0;
    }
}