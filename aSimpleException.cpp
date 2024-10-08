#include <iostream>
#include <string>
#include <stdexcept>

class bad_length : public std::runtime_error
{
public:
    bad_length() : std::runtime_error("Длина строки равна запрещенной!") {}
};

size_t function(const std::string& str, size_t forbidden_length)
{
    size_t length = str.length();
    if (length == forbidden_length)
    {
        throw bad_length();
    }
    return length;
}

int main()
{
    size_t forbidden_length;

    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;

    std::string input;

    while (true)
    {
        std::cout << "Введите слово: ";
        std::cin >> input;

        try
        {
            size_t length = function(input, forbidden_length);
            std::cout << "Длина слова \"" << input << "\" равна " << length << std::endl;
        } catch (const bad_length& e)
        {
            std::cout << "Вы ввели слово запретной длины! До свидания" << std::endl;
            break;
        }
    }

    return 0;
}
