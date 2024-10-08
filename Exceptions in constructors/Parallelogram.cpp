#include "Parallelogram.h"

Parallelogram::Parallelogram(double a, double b, double angleA, double angleB)
    : Quadrilateral(a, b, a, b, angleA, angleB, angleA, angleB) {}
