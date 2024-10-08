#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include "Shape.h"
#include "GeometryException.h"

class Quadrilateral : public Shape
{
protected:
    double a, b, c, d;
    double angleA, angleB, angleC, angleD;

public:
    Quadrilateral(double a, double b, double c, double d,
                  double angleA, double angleB, double angleC, double angleD);

    virtual ~Quadrilateral() = default;
};

#endif
