#include "pe12-2a.h"
#include <stdio.h>
static int mode;
static double distance;
static double fuel_consumed;
void get_info(void)
{
    printf("Enters distance traveled in %s: ", mode == METRIC_MODE ? "kilometers" : "miles");
    scanf("%lf", &distance);
    printf("Enter fuel consumed in %s: ", mode == METRIC_MODE ? "liters" : "gallons");
    scanf("%lf", &fuel_consumed);
}

void show_info(void)
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

void set_mode(int ext_mode)
{
    if (ext_mode > 1)
    {
        printf("Invalid mode specified. Mode 1(US) used.\n");
        mode = US_MODE;
    }
    else 
    {
        mode = ext_mode;
    }
}