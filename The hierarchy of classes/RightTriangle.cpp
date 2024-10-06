#include <iostream>
#include "RightTriangle.h"

RightTriangle::RightTriangle(double a, double b)
    : Triangle(a, b, std::sqrt(a * a + b * b),
               std::atan(b / a) * (180 / 3.1415),
               90, 0) {}
