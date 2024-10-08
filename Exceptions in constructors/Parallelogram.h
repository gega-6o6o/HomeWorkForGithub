#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "Quadrilateral.h"

class Parallelogram : public Quadrilateral
{
public:
    Parallelogram(double a, double b, double angleA, double angleB);
    virtual ~Parallelogram() = default;
};

#endif
