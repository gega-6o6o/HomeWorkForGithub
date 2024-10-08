#ifndef ISOSCELESTRIANGLE_H
#define ISOSCELESTRIANGLE_H

#include "Triangle.h"

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(double base, double side, double baseAngle);
    virtual ~IsoscelesTriangle() = default;
};

#endif
