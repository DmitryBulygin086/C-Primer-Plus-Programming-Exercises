// Polar coordinates describe a vector in terms of magnitude and the counterclockwise angle
// from the x-axis to the vector. Rectangular coordinates describe the same vector in terms
// of x and y components (see Figure 16.3). Write a program that reads the magnitude and
// angle (in degrees) of a vector and then displays the x and y components. The relevant
// equations are these:
// x = r cos A
// y = r sin A
// To do the conversion, use a function that takes a structure containing the polar
// coordinates and returns a structure containing the rectangular coordinates (or use
// pointers to such structures, if you prefer).

#include "ex01.h"
#include "coordinates.h"
#include <math.h>

int main(void)
{
    Rect rect;
    Polar polar;
    double magnitude, angle;

    while (1)
    {
        printf("Enter the magnitude and angle (in degrees) of a vector(non-numeric input to quit):\n");
        if (scanf("%lf %lf", &polar.magnitude, &polar.angle) != 2)
        {
            EATLINE;
            break;
        }
        EATLINE;

        rect = rect_from_polar(polar);
        
        printf("The x-component is %.2f\n", rect.x);
        printf("The y-component is %.2f\n", rect.y);
    }
    return 0;
}