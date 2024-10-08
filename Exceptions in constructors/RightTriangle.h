#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "Triangle.h"

class RightTriangle : public Triangle
{
public:
    RightTriangle(double a, double b);
    virtual ~RightTriangle() = default;
};

#endif
