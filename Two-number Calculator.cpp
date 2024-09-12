#include <iostream>

class Calculator
{
private:
    double num1;
    double num2;

public:
    bool set_num1(double value)
    {
        if (value != 0)
        {
            num1 = value;
            return true;
        }
        return false;
    }

    bool set_num2(double value)
    {
        if (value != 0)
        {
            num2 = value;
            return true;
        }
        return false;
    }

    double add()
    {
        return num1 + num2;
    }

    double multiply()
    {
        return num1 * num2;
    }

    double subtract_1_2()
    {
        return num1 - num2;
    }

    double subtract_2_1()
    {
        return num2 - num1;
    }

    double divide_1_2()
    {
        if (num2 != 0)
        {
            return num1 / num2;
        }
        return 0.0;
    }

    double divide_2_1()
    {
        if (num1 != 0)
        {
            return num2 / num1;
        }
        return 0.0;
    }
};

int main()
{
    Calculator calc;
    double num1, num2;

    while (true)
    {
        std::cout << "Введите num1: ";
        std::cin >> num1;
        if (!calc.set_num1(num1))
        {
            std::cout << "Неверный ввод!" << std::endl;
            continue;
        }

        std::cout << "Введите num2: ";
        std::cin >> num2;
        if (!calc.set_num2(num2))
        {
            std::cout << "Неверный ввод!" << std::endl;
            continue;
        }

        std::cout << "num1 + num2 = " << calc.add() << std::endl;
        std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
        std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
        std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
        std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
    }

    return 0;
}