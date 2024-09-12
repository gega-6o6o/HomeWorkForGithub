#include <iostream>

class Counter 
{
private:
    int value;

public:
    Counter() : value(1) {}
    Counter(int initialValue) : value(initialValue) {}

    void increment()
    {
        ++value;
    }

    void decrement()
    {
        --value;
    }

    int getCurrentValue() const 
    {
        return value;
    }
};

int main()
{
    std::string response;
    int initialValue;
    Counter counter;

    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> response;

    if (response == "да")
    {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> initialValue;
        counter = Counter(initialValue);
    }

    char command;
    while (true)
    {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;

        switch (command)
        {
            case '+':
                counter.increment();
                break;
            case '-':
                counter.decrement();
                break;
            case '=':
                std::cout << counter.getCurrentValue() << std::endl;
                break;
            case 'x':
                std::cout << "До свидания!" << std::endl;
                return 0;
            default:
                std::cout << "Неверная команда. Попробуйте еще раз." << std::endl;
                break;
        }
    }
}