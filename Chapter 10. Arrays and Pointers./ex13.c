// Write a program that prompts the user to enter three sets of five double numbers each.
// (You may assume the user responds correctly and doesn’t enter non-numeric data.) The
// program should accomplish all of the following:
// a. Store the information in a 3×5 array.
// b. Compute the average of each set of five values.
// c. Compute the average of all the values.
// d. Determine the largest value of the 15 values.
// e. Report the results.
// Each major task should be handled by a separate function using the traditional C
// approach to handling arrays. Accomplish task “b” by using a function that computes
// and returns the average of a one-dimensional array; use a loop to call this function three
// times. The other tasks should take the entire array as an argument, and the functions
// performing tasks “c” and “d” should return the answer to the calling program.

#include <stdio.h>
#define SETS 3
#define NUMBERS 5

// Get array from user
void getArray(int sets, int numbers, double array[sets][numbers]);

// returns average of setNo set
double computeAvgOfSet(int numbers, double array[][numbers], int setNo);

// Returns average value of 2D array
double computeAvgOfAll(int sets, int numbers, double array[sets][numbers]);

// Returns largest value of 2D array
double detLargest(int sets, int numbers, double array[sets][numbers]);

void print1Darray(double *array, int arrlen);
int main(void)
{
    double array[SETS][NUMBERS];
    double setAvgs[SETS];   // We store here averages of sets
    double avgOfAllArr;     // We store here average of all array
    double largest;         // We will store here largest value of array

    // get array
    getArray(SETS, NUMBERS, array);
    
    // compute averages of sets and store them in setAvgs
    for (int set = 0; set < SETS; set++)
    {
        setAvgs[set] = computeAvgOfSet(NUMBERS, array, set);
    }

    avgOfAllArr = computeAvgOfAll(SETS, NUMBERS, array);

    largest = detLargest(SETS, NUMBERS, array);

    puts("setAvgs:");
    print1Darray(setAvgs, SETS);
    putchar('\n');
   
    printf("avgOfAllArr: %lf\n", avgOfAllArr);
    printf("largest: %lf\n", largest);
    


}

void getArray(int sets, int numbers, double array[sets][numbers])
{
    
    for (int set = 0; set < sets; set++)
    {
        printf("Enter set of five double numbers: ");
        for (int number = 0; number < numbers; number++)
        {
            scanf("%lf", &array[set][number]);
        }
    } 
}

double computeAvgOfSet(int numbers, double array[][numbers], int setNo)
{
    double total = 0;
    double avg;
    for (int number = 0; number < numbers; number++)
    {
        total += array[setNo][number];
    }   
    avg = total / numbers;
    return avg;
}

double computeAvgOfAll(int sets, int numbers, double array[sets][numbers])
{
    double total = 0;
    double avg;
    for (int set = 0; set < sets; set++)
    {
        for (int number = 0; number < numbers; number++)
        {
            total += array[set][number];
        }
    }
    avg = total / (sets * numbers);
    return avg;
}

double detLargest(int sets, int numbers, double array[sets][numbers])
{
    double largest = array[0][0];
    for (int set = 0; set < sets; set++)
    {
        for (int number = (set == 0 ? 1 : 0); number < numbers; number++)
        {
            if (array[set][number] > largest)
            {
                largest = array[set][number];
            }
        }
    }
    return largest;
}

void print1Darray(double *array, int arrlen)
{
    for(int index = 0; index < arrlen; index++)
    {

        printf("set #%d: %lf", index + 1, array[index]);
        putchar('\n');
    }
}