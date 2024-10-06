#include "Parallelogram.h"

Parallelogram::Parallelogram(double sideA, double sideB, double angleA)
    : Quadrilateral(sideA, sideB, sideA, sideB, angleA, 180 - angleA, angleA, 180 - angleA) {}
