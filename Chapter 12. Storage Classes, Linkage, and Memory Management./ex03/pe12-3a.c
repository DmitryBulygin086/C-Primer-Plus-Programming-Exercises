#include "pe12-3a.h"
#include <stdio.h>

void get_info(int mode, double *distance, double *fuel_consumed)
{
    printf("Enters distance traveled in %s: ", mode == METRIC_MODE ? "kilometers" : "miles");
    scanf("%lf", distance);
    printf("Enter fuel consumed in %s: ", mode == METRIC_MODE ? "liters" : "gallons");
    scanf("%lf", fuel_consumed);
}

void show_info(int mode, double distance, double fuel_consumed)
{
    double fuel_consumption;
    if (mode == METRIC_MODE)
    {
        fuel_consumption = (fuel_consumed / distance) * 100.0;
    }
    else 
    {
        fuel_consumption = distance / fuel_consumed;
    }
    printf("Fuel consumption is %.2lf %s per %s.\n", fuel_consumption, 
    mode == METRIC_MODE ? "liters" : "miles", mode == METRIC_MODE ? "100 km" : "gallon");
}

void set_mode(int * mode)
{
    if (*mode > 1)
    {
        printf("Invalid mode specified. Mode 1(US) used.\n");
        *mode = US_MODE;
    }
}

void eat_newline(void)
{
    while (getchar() != '\n')
    {
        continue;
    }
}