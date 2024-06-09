// Modify the guessing program of Listing 8.4 so that it uses a more intelligent guessing
// strategy. For example, have the program initially guess 50, and have it ask the user
// whether the guess is high, low, or correct. If, say, the guess is low, have the next guess
// be halfway between 50 and 100, that is, 75. If that guess is high, let the next guess be
// halfway between 75 and 50, and so on. Using this binary search strategy, the program
// quickly zeros in on the correct answer, at least if the user does not cheat.

// Listing 8.4
/* guess.c -- an inefficient and faulty number-guesser */
// #include <stdio.h>
// int main(void)
// {
    // int guess = 1;
    // printf("Pick an integer from 1 to 100. I will try to guess ");
    // printf("it.\nRespond with a y if my guess is right and with");
    // printf("\nan n if it is wrong.\n");
    // printf("Uh...is your number %d?\n", guess);
    // while (getchar() != 'y')
    // /* get response, compare to y */
    //      printf("Well, then, is it %d?\n", ++guess);
    // printf("I knew I could do it!\n");
    // return 0;
// }

#include <stdio.h>

void flush_input_buffer(void);

int main(void)
{
    int guess = 50;
    char answer;
    int upper_bound = 100;
    int lower_bound = 0;
    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it.\nRespond with a y if my guess is right, with");
    printf("\nan h if it is high,\n");
    printf("with l if it is low.\n");
    printf("Uh...is your number %d?\n", guess);
    while ((answer = getchar()) != 'y')
    {
        flush_input_buffer();
        if (answer == 'h')
        {
            upper_bound = guess;
        }
        else if (answer == 'l')
        {
            lower_bound = guess;
        }
        else 
        {
            printf("Invalid input.\n");
            continue;
        }
        guess = (upper_bound + lower_bound) / 2;
        printf("Well, then, it is %d?\n", guess);
    }
    printf("I knew I could do it!\n");
    return 0;

}

void flush_input_buffer(void)
{
    while (getchar() != '\n')
    {
        continue;
    }
}