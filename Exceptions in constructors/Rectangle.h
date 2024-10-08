#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Quadrilateral.h"

class Rectangle : public Quadrilateral
{
public:
    Rectangle(double w, double h);
    virtual ~Rectangle() = default;
};

#endif
