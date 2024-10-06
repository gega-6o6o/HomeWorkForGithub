#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include "Shape.h"

class Quadrilateral : public Shape {
protected:
    double a, b, c, d; // стороны
    double A, B, C, D; // углы

public:
    Quadrilateral(double sideA, double sideB, double sideC, double sideD, double angleA, double angleB, double angleC, double angleD);
    void display() const override;
};

#endif
