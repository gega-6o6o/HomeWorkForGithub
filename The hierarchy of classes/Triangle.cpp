#include "Triangle.h"
#include <iostream>

Triangle::Triangle(double sideA, double sideB, double sideC, double angleA, double angleB, double angleC)
    : a(sideA), b(sideB), c(sideC), A(angleA), B(angleB), C(angleC) {}

void Triangle::display() const {
    std::cout << "Треугольник:\nСтороны: a=" << a << " b=" << b << " c=" << c << "\nУглы: A=" << A << " B=" << B << " C=" << C << '\n';
}
