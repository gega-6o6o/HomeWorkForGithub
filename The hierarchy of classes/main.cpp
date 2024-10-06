#include <iostream>
#include "Triangle.h"
#include "RightTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Quadrilateral.h"
#include "Rectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhombus.h"

int main() {
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle rightTriangle(10, 20);
    IsoscelesTriangle isoscelesTriangle(10, 20);
    EquilateralTriangle equilateralTriangle(30);
    
    Quadrilateral quad(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30);
    Rhombus rhombus(30, 30);

    triangle.display();
    rightTriangle.display();
    isoscelesTriangle.display();
    equilateralTriangle.display();

    quad.display();
    rectangle.display();
    square.display();
    parallelogram.display();
    rhombus.display();

    return 0;
}

