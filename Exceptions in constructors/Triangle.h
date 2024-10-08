#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include "GeometryException.h"

class Triangle : public Shape
{
protected:
    double a, b, c;
    double angleA, angleB, angleC;

public:
    Triangle(double a, double b, double c, double angleA, double angleB);

    virtual ~Triangle() = default;
};

#endif
