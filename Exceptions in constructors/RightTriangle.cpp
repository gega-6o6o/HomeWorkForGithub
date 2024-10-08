#include "RightTriangle.h"

RightTriangle::RightTriangle(double a, double b)
: Triangle(a, b, sqrt(a*a + b*b), 90, atan(b / a) * (180.0 / M_PI)) {}
