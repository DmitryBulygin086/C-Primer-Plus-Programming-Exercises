// Do Programming Exercise 13, but use variable-length array function parameters.

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