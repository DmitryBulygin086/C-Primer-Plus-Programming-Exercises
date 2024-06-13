// Write a program that generates 1,000 random numbers in the range 1–10. Don’t save or
// print the numbers, but do print how many times each number was produced. Have the
// program do this for 10 different seed values. Do the numbers appear in equal amounts?
// You can use the functions from this chapter or the ANSI C rand() and srand()
// functions, which follow the same format that our functions do. This is one way to
// examine the randomness of a particular random-number generator.

#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
#define BYTES_PER_INT 4
void random_sample(void);
int main(void)
{
    for (int count = 1; count <= 10; count++)
    {
        srand(count);
        random_sample();
        putchar('\n');
    }
    return 0;
}

void random_sample(void)
{
    int counts[10] = {0,0,0,0,0,0,0,0,0,0};
    const int RAND_LIMIT = (RAND_MAX / 10) * 10; // gives us maximum random number divisible by 10 (2147483640)
    int rand_int;

    unsigned i = 0;
    while (i < SIZE)
    {
        rand_int = rand();

        if (rand_int >= RAND_LIMIT) // truncating
        {
            continue;
        }
        else 
        {
            rand_int %= 10;
            counts[rand_int]++;
        }
        i++;
    }
    puts("Counts:");
    for (int count = 0; count < (sizeof(counts) / BYTES_PER_INT); count++)
    {
        printf("%2d: %3d  ", count + 1, counts[count]);
    }
    putchar('\n');
}
