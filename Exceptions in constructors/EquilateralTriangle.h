#ifndef EQUILATERALTRIANGLE_H
#define EQUILATERALTRIANGLE_H

#include "Triangle.h"

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(double side);
    virtual ~EquilateralTriangle() = default;
};

#endif
