// Professor Rabnud joined a social media group. Initially he had five friends. He noticed
// that his friend count grew in the following fashion. The first week one friend dropped
// out and the remaining number of friends doubled. The second week two friends dropped
// out and the remaining number of friends doubled. In general, in the Nth week, N friends
// dropped out and the remaining number doubled. Write a program that computes and
// displays the number of friends each week. The program should continue until the count
// exceeds Dunbar’s number. Dunbar’s number is a rough estimate of the maximum size of
// a cohesive social group in which each member knows every other member and how they
// relate to one another. Its approximate value is 150.

#include <stdio.h>

#define INIT_FR 5
#define DUNBARS_NUM 150


int main(void)
{
    unsigned int weeks = 0;
    unsigned int fr_ct = INIT_FR;
    printf("%20s %20s\n", "WEEK", "FR_CT");
    while (fr_ct <= DUNBARS_NUM)
    {
        weeks++;
        fr_ct -= weeks;
        fr_ct *= 2;
        
        printf("%20u %20u\n", weeks, fr_ct);
    }
    printf("\n");
    return 0;
}