// Modify the rain program in Listing 10.7 so that it does the calculations using pointers
// instead of subscripts. (You still have to declare and initialize the array.)

/* rain.c
-- finds yearly totals, yearly average, and monthly
average for several years of rainfall data */
#include <stdio.h>
#define MONTHS 12
// number of months in a year
#define YEARS 5
// number of years of data
int main(void)
{
    // initializing rainfall data for 2010 - 2014
    const float rain[YEARS][MONTHS] =
    {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };
    float (*year_ptr)[MONTHS];
    float *month_ptr;
    float subtot, total;
    printf(" YEAR  RAINFALL (inches)\n");
    for (year_ptr = &rain[0], total = 0; year_ptr < &rain[0] + YEARS; year_ptr++)
    {
        // for each year, sum rainfall for each month
        for (month_ptr = *year_ptr, subtot = 0; month_ptr < *year_ptr + MONTHS; month_ptr++)
            subtot += *month_ptr;
        printf("%5d %15.1f\n", (int)(2010 + (year_ptr - &rain[0])), subtot);
        total += subtot; // total for all years
    }
    printf("\nThe yearly average is %.1f inches.\n\n",
            total/YEARS);

    int month, year;
    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct ");
    printf("Nov Dec\n");
    for (month = 0; month < MONTHS; month++)
    {
        for (year = 0, total = 0; year < YEARS; year++)
        {
            total += *(*(rain + year) + month);
        }
        printf("%.1f ", total / YEARS);
    }
    
    printf("\n");
    return 0;
}