#include <iostream>
#include <string>

class Figure
{
protected:
    int sides_count;

public:
    Figure() : sides_count() {}

protected:
    Figure(int sides) : sides_count(sides) {}

public:
    int get_sides_count() const
    {
        return sides_count;
    }

    virtual std::string get_name() const
    {
        return "Фигура";
    }
};

class Triangle : public Figure
{
protected:
    double a, b, c;
    double A, B, C;

public:
    Triangle(double a, double b, double c, double A, double B, double C)
        : Figure(3), a(a), b(b), c(c), A(A), B(B), C(C) {}

    std::string get_name() const override
    {
        return "Треугольник";
    }

    double get_a() const { return a; }
    double get_b() const { return b; }
    double get_c() const { return c; }

    double get_A() const { return A; }
    double get_B() const { return B; }
    double get_C() const { return C; }
};

class RightTriangle : public Triangle
{
public:
    RightTriangle(double a, double b, double c, double A, double B)
        : Triangle(a, b, c, A, B, 90.0) {}

    std::string get_name() const override {
        return "Прямоугольный треугольник";
    }
};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(double a, double b, double A, double B)
        : Triangle(a, b, a, A, B, A) {}

    std::string get_name() const override
    {
        return "Равнобедренный треугольник";
    }
};

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(double a)
        : Triangle(a, a, a, 60.0, 60.0, 60.0) {}

    std::string get_name() const override
    {
        return "Равносторонний треугольник";
    }
};

class Quadrangle : public Figure
{
protected:
    double a, b, c, d;
    double A, B, C, D;

public:
    Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D)
        : Figure(4), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

    std::string get_name() const override
    {
        return "Четырёхугольник";
    }

    double get_a() const { return a; }
    double get_b() const { return b; }
    double get_c() const { return c; }
    double get_d() const { return d; }

    double get_A() const { return A; }
    double get_B() const { return B; }
    double get_C() const { return C; }
    double get_D() const { return D; }
};

class Rectangle : public Quadrangle
{
public:
    Rectangle(double a, double b)
        : Quadrangle(a, b, a, b, 90.0, 90.0, 90.0, 90.0) {}

    std::string get_name() const override
    {
        return "Прямоугольник";
    }
};

class Square : public Rectangle
{
public:
    Square(double a)
        : Rectangle(a, a) {}

    std::string get_name() const override
    {
        return "Квадрат";
    }
};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(double a, double b, double A, double B)
        : Quadrangle(a, b, a, b, A, B, 180.0 - A, 180.0 - B) {}

    std::string get_name() const override
    {
        return "Параллелограмм";
    }
};

class Rhombus : public Parallelogram
{
public:
    Rhombus(double a, double A, double B)
        : Parallelogram(a, a, A, B) {}

    std::string get_name() const override
    {
        return "Ромб";
    }
};

void print_info(const Figure* figure)
{
    std::cout << figure->get_name() << ":\n";

    if (const Triangle* triangle = dynamic_cast<const Triangle*>(figure))
    {
        std::cout << "Стороны: a=" << triangle->get_a()
                  << " b=" << triangle->get_b()
                  << " c=" << triangle->get_c() << "\n"
                  << "Углы: A=" << triangle->get_A()
                  << " B=" << triangle->get_B()
                  << " C=" << triangle->get_C() << "\n";
    } else if (const Quadrangle* quadrangle = dynamic_cast<const Quadrangle*>(figure))
    {
        std::cout << "Стороны: a=" << quadrangle->get_a()
                  << " b=" << quadrangle->get_b()
                  << " c=" << quadrangle->get_c()
                  << " d=" << quadrangle->get_d() << "\n"
                  << "Углы: A=" << quadrangle->get_A()
                  << " B=" << quadrangle->get_B()
                  << " C=" << quadrangle->get_C()
                  << " D=" << quadrangle->get_D() << "\n";
    } else
    {
        std::cout << "Неизвестная фигура\n";
    }

    std::cout << std::endl;
}

int main()
{
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle right_triangle(10, 20, 30, 50, 60);
    IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
    EquilateralTriangle equilateral_triangle(30);

    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);

    print_info(&triangle);
    print_info(&right_triangle);
    print_info(&isosceles_triangle);
    print_info(&equilateral_triangle);
    print_info(&quadrangle);
    print_info(&rectangle);
    print_info(&square);
    print_info(&parallelogram);
    print_info(&rhombus);

    return 0;
}