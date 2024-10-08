#include "Triangle.h"

Triangle::Triangle(double a, double b, double c, double angleA, double angleB)
    : a(a), b(b), c(c), angleA(angleA), angleB(angleB)
{
    angleC = 180 - angleA - angleB;
    if (a <= 0 || b <= 0 || c <= 0)
    {
        throw GeometryException("Стороны должны быть положительными!");
    }
    if (angleA < 0 || angleB < 0 || angleC < 0)
    {
        throw GeometryException("Углы должны быть положительными!");
    }
    if ((angleA + angleB + angleC) != 180)
    {
        throw GeometryException("Сумма углов не равна 180!");
    }
}
