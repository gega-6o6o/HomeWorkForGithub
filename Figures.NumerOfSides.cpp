#include <iostream>
#include <string>

class Figure
{
protected:
    int sides_count;

public:
    Figure() : sides_count(0) {}

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
public:
    Triangle() : Figure(3) {}

    std::string get_name() const override
    {
        return "Треугольник";
    }
};

class Quadrangle : public Figure
{
public:
    Quadrangle() : Figure(4) {}

    std::string get_name() const override
    {
        return "Четырёхугольник";
    }
};

int main()
{
    Figure figure;
    Triangle triangle;
    Quadrangle quadrangle;

    std::cout << "Количество сторон:\n"
              << figure.get_name() << ": " << figure.get_sides_count() << "\n"
              << triangle.get_name() << ": " << triangle.get_sides_count() << "\n"
              << quadrangle.get_name() << ": " << quadrangle.get_sides_count() << "\n";

    return 0;
}