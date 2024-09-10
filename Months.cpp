#include <iostream>
#include <string>
#include <array>

enum class Month : int
{
    Январь = 1, Февраль, Март, Апрель, Май, Июнь,
    Июль, Август, Сентябрь, Октябрь, Ноябрь, Декабрь
};

int main()
{
    std::array<std::string, 12> monthNames =
    {
        "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
        "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"
    };

    while (true)
    {
        int monthNumber;
        std::cout << "Введите номер месяца (0 для выхода): ";
        std::cin >> monthNumber;

        if (monthNumber == 0)
        {
            std::cout << "До свидания!" << std::endl;
            break;
        }

        if (monthNumber < 1 || monthNumber > 12)
        {
            std::cout << "Неправильный номер!" << std::endl;
            continue;
        }

        Month month = static_cast<Month>(monthNumber);
        std::cout << monthNames[static_cast<int>(month) - 1] << std::endl;
    }

    return 0;
}