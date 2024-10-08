#include <iostream>
#include "GeometryException.h"
#include "EquilateralTriangle.h"
#include "IsoscelesTriangle.h"
#include "RightTriangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhombus.h"

int main()
{
    try
    {
        EquilateralTriangle equilateral(5);
        std::cout << "Равносторонний треугольник создан." << std::endl;
    } catch (const GeometryException& e)
        {
            std::cerr << "Ошибка создания фигуры. Причина: " << e.what() << std::endl;
        }

    try
    {
        IsoscelesTriangle isosceles(5, 5, 60);
        std::cout << "Равнобедренный треугольник создан." << std::endl;
    } catch (const GeometryException& e)
        {
            std::cerr << "Ошибка создания фигуры. Причина: " << e.what() << std::endl;
        }

    try
    {
        RightTriangle rightTriangle(3, 4);
        std::cout << "Прямоугольный треугольник создан." << std::endl;
    } catch (const GeometryException& e)
        {
            std::cerr << "Ошибка создания фигуры. Причина: " << e.what() << std::endl;
        }

    try
    {
        Rectangle rectangle(4, 5);
        std::cout << "Прямоугольник создан." << std::endl;
    } catch (const GeometryException& e)
        {
            std::cerr << "Ошибка создания фигуры. Причина: " << e.what() << std::endl;
        }

    try
    {
        Square square(4);
        std::cout << "Квадрат создан." << std::endl;
    } catch (const GeometryException& e)
        {
            std::cerr << "Ошибка создания фигуры. Причина: " << e.what() << std::endl;
        }

    try
    {
        Parallelogram parallelogram(4, 5, 60, 120);
        std::cout << "Параллелограмм создан." << std::endl;
    } catch (const GeometryException& e)
        {
            std::cerr << "Ошибка создания фигуры. Причина: " << e.what() << std::endl;
        }

    try
    {
        Rhombus rhombus(4, 60, 120);
        std::cout << "Ромб создан." << std::endl;
    } catch (const GeometryException& e)
        {
            std::cerr << "Ошибка создания фигуры. Причина: " << e.what() << std::endl;
        }

    return 0;
}
