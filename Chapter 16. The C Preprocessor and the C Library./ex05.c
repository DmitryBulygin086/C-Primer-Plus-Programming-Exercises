// Write a function that takes as arguments the name of an array of type int elements, the
// size of an array, and a value representing the number of picks. The function then should
// select the indicated number of items at random from the array and prints them. No
// array element is to be picked more than once. (This simulates picking lottery numbers or
// jury members.) Also, if your implementation has time() (discussed in Chapter 12) or a
// similar function available, use its output with srand() to initialize the rand() random-
// number generator. Write a simple program that tests the function.
#include <time.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ex01.h"

#define ARRLEN 10

void pick_rand(int arr[], int size, int picks);

void print_arr(int arr[], int arr_len);

int main(void)
{
    int picks;
    int arr[ARRLEN];
    srand(time(NULL));
    for (int i = 0; i < ARRLEN; i++)
    {
        arr[i] = rand() % 10;
    }

    while(1)
    {
        printf("Enter the number of picks(non-numeric input to quit): ");
        if (scanf("%d", &picks) != 1)
        {
            break;
        }
        printf("array: \n");
        print_arr(arr, ARRLEN);
        putchar('\n');
        
        pick_rand(arr, ARRLEN, picks);
    }
}

void pick_rand(int arr[], int size, int picks)
{
    if (picks > size)
    {
        fprintf(stderr, "picks must be less than or equal to size\n");
        return;
    }
    bool chosen[size];

    for (int i = 0; i < size; i++)
    {
        chosen[i] = false;
    }

    srand(time(NULL));
    for (int i = 0; i < picks; i++)
    {
        int index = rand() % size;
        while(chosen[index] == true)
            index = rand() % size;
        chosen[index] = true;
        printf("%d\n", arr[index]);
    }
}

void print_arr(int arr[], int arr_len)
{
    for (int i = 0; i < arr_len; i++)
    {
        printf("%d ", arr[i]);
    }
}