#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Parallelogram.h"

class Rhombus : public Parallelogram
{
public:
    Rhombus(double side, double angleA, double angleB);
    virtual ~Rhombus() = default;
};

#endif
