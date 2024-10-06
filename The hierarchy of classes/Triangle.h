#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
protected:
    double a, b, c; // стороны
    double A, B, C; // углы

public:
    Triangle(double sideA, double sideB, double sideC, double angleA, double angleB, double angleC);
    void display() const override;
};

#endif
