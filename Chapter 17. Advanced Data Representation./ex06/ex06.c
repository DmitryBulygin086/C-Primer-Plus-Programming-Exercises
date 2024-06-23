// Write a function that takes three arguments: the name of an array of sorted integers, the
// number of elements of the array, and an integer to seek. The function returns the value
// 1 if the integer is in the array, and 0 if it isn’t. Have the function use the binary search
// technique.

// compile with bin_search.c

#include <stdio.h>
#include "bin_search.h"
#define ARR_SIZE 10

#define EATLINE while (getchar()!= '\n') continue
int main(void)
{
    int num;
    int arr[ARR_SIZE] = {1, 2, 3, 4, 8 , 9, 10, 11, 12, 13};

    printf("Enter a number to search for: ");
    while (scanf("%d", &num) != 1)
    {
        EATLINE;
        printf("Enter a number to search for: ");
    }
    EATLINE;
    printf("%d in arr? %s\n", num, inArr(arr, ARR_SIZE, num)? "Yes" : "No");
    return 0;
}