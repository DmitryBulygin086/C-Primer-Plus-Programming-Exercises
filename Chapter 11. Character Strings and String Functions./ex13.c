// Write a program that echoes the command-line arguments in reverse word order. That
// is, if the command-line arguments are see you later, the program should print later
// you see.

#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s argv[1] argv[2] ...\n", argv[0]);
        return 1;
    }
    else 
    {
        for (int count = argc - 1; count > 0; count--)
        {
            printf("%s ", argv[count]);
        }
    }
    putchar('\n');
    return 0;
}