#include <iostream>
#include <cmath>

class Figure
{
protected:
    int sides_count;
    std::string name;

public:
    Figure() : sides_count(0), name("Фигура") {}
    virtual ~Figure() {}

    virtual int get_sides_count() const { return sides_count; }
    virtual std::string get_name() const { return name; }

    virtual void print_info()
    {
        std::cout << get_name() << ":\n"
                  << (check() ? "Правильная\n" : "Неправильная\n")
                  << "Количество сторон: " << get_sides_count() << "\n";
    }

    virtual bool check() { return get_sides_count() == 0 || check_angles(); }

    virtual bool check_angles() { return true; }
};

class Triangle : public Figure
{
protected:
    double a, b, c;
    double A, B, C;

public:
    Triangle(double a, double b, double c, double A, double B, double C)
        : a(a), b(b), c(c), A(A), B(B), C(C), Figure()
    {
        sides_count = 3;
        name = "Треугольник";
    }
    virtual ~Triangle() {}

    double get_a() const { return a; }
    double get_b() const { return b; }
    double get_c() const { return c; }
    double get_A() const { return A; }
    double get_B() const { return B; }
    double get_C() const { return C; }

    void print_info() override
    {
        Figure::print_info();
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << "\n"
                  << "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C() << "\n";
    }

    bool check_angles() override
    {
        return std::abs(get_A() + get_B() + get_C() - 180.0) < 1e-6;
    }
};

class RightTriangle : public Triangle
{
public:
    RightTriangle(double a, double b, double c, double A, double B)
        : Triangle(a, b, c, A, B, 90.0) { name = "Прямоугольный треугольник"; }

    bool check() override { return Triangle::check() && std::abs(get_C() - 90.0) < 1e-6; }
};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(double a, double b, double C)
        : Triangle(a, b, a, C, 180.0 - 2 * C, C) { name = "Равнобедренный треугольник"; }

    bool check() override
    {
        return Triangle::check() && std::abs(get_a() - get_c()) < 1e-6 && std::abs(get_A() - get_C()) < 1e-6;
    }
};

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(double a)
        : Triangle(a, a, a, 60.0, 60.0, 60.0) { name = "Равносторонний треугольник"; }

    bool check() override
    {
        return Triangle::check() && std::abs(get_a() - get_b()) < 1e-6 && std::abs(get_b() - get_c()) < 1e-6 &&
               std::abs(get_A() - 60.0) < 1e-6 && std::abs(get_B() - 60.0) < 1e-6 && std::abs(get_C() - 60.0) < 1e-6;
    }
};

class Quadrilateral : public Figure
{
protected:
    double a, b, c, d;
    double A, B, C, D;

public:
    Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D)
        : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D), Figure()
    {
        sides_count = 4;
        name = "Четырёхугольник";
    }

    double get_a() const { return a; }
    double get_b() const { return b; }
    double get_c() const { return c; }
    double get_d() const { return d; }
    double get_A() const { return A; }
    double get_B() const { return B; }
    double get_C() const { return C; }
    double get_D() const { return D; }

    void print_info() override
    {
        Figure::print_info();
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << "\n"
                  << "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << "\n";
    }

    bool check() override { return Figure::check() && std::abs(get_A() + get_B() + get_C() + get_D() - 360.0) < 1e-6; }
};

class Rectangle : public Quadrilateral
{
public:
    Rectangle(double a, double b)
        : Quadrilateral(a, b, a, b, 90.0, 90.0, 90.0, 90.0) { name = "Прямоугольник"; }

    bool check() override
    {
        return Quadrilateral::check() && std::abs(get_a() - get_c()) < 1e-6 && std::abs(get_b() - get_d()) < 1e-6;
    }
};

class Square : public Rectangle
{
public:
    Square(double a)
        : Rectangle(a, a) { name = "Квадрат"; }

    bool check() override { return Rectangle::check() && std::abs(get_a() - get_b()) < 1e-6; }
};

class Parallelogram : public Quadrilateral
{
public:
    Parallelogram(double a, double b, double A, double B)
        : Quadrilateral(a, b, a, b, A, B, 180.0 - A, 180.0 - B) { name = "Параллелограмм"; }

    bool check() override
    {
        return Quadrilateral::check() && std::abs(get_a() - get_c()) < 1e-6 && std::abs(get_b() - get_d()) < 1e-6 &&
               std::abs(get_A() - get_C()) < 1e-6 && std::abs(get_B() - get_D()) < 1e-6;
    }
};

class Rhombus : public Parallelogram
{
public:
    Rhombus(double a, double A, double B)
        : Parallelogram(a, a, A, B) { name = "Ромб"; }

    bool check() override
    {
        return Parallelogram::check() && std::abs(get_a() - get_b()) < 1e-6 && std::abs(get_A() - get_C()) < 1e-6 &&
               std::abs(get_B() - get_D()) < 1e-6;
    }
};

int main()
{
    Figure* figure = new Figure();
    Triangle* triangle = new Triangle(10, 20, 30, 50, 60, 70);
    RightTriangle* rightTriangle1 = new RightTriangle(10, 20, 30, 50, 60);
    RightTriangle* rightTriangle2 = new RightTriangle(10, 20, 30, 50, 40);
    IsoscelesTriangle* isoscelesTriangle = new IsoscelesTriangle(10, 20, 50);
    EquilateralTriangle* equilateralTriangle = new EquilateralTriangle(30);
    Quadrilateral* quadrilateral = new Quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle* rectangle = new Rectangle(10, 20);
    Square* square = new Square(20);
    Parallelogram* parallelogram = new Parallelogram(20, 30, 30, 40);
    Rhombus* rhombus = new Rhombus(30, 30, 40);

    Figure* figures[] = {figure, triangle, rightTriangle1, rightTriangle2, isoscelesTriangle, equilateralTriangle,
                        quadrilateral, rectangle, square, parallelogram, rhombus};

    for (Figure* f : figures)
    {
        f->print_info();
        std::cout << "\n";
    }

    for (Figure* f : figures)
    {
        delete f;
    }

    return 0;
}
