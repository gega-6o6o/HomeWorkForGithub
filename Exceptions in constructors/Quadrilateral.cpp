#include "Quadrilateral.h"

Quadrilateral::Quadrilateral(double a, double b, double c, double d,
                             double angleA, double angleB, double angleC, double angleD)
    : a(a), b(b), c(c), d(d), angleA(angleA), angleB(angleB), angleC(angleC), angleD(angleD)
{

    if (a <= 0 || b <= 0 || c <= 0 || d <= 0)
    {
        throw GeometryException("Стороны должны быть положительными!");
    }
    if ((angleA + angleB + angleC + angleD) != 360)
    {
        throw GeometryException("Сумма углов не равна 360!");
    }
}
