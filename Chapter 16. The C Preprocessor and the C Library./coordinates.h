#ifndef COORDINATES_H_
#define COORDINATES_H_

typedef struct polar {
    double angle;
    double magnitude;
} Polar;

typedef struct rect {
    double x;
    double y;
} Rect;

// converts polar coordinates to rectangular
Rect rect_from_polar(Polar pol);

#endif