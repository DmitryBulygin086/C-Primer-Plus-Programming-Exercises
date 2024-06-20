#include "coordinates.h"
#include <math.h>
Rect rect_from_polar(Polar pol)
{
    Rect rect;

    rect.x = pol.magnitude * cos(pol.angle);
    rect.y = pol.magnitude * sin(pol.angle);

    return rect;
}