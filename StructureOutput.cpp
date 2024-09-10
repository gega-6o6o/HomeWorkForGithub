#include <iostream>
#include <string>

struct Address
{
    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;
    int postalCode;
};

void printAddress(const Address& addr)
{
    std::cout << "Город: " << addr.city << std::endl;
    std::cout << "Улица: " << addr.street << std::endl;
    std::cout << "Номер дома: " << addr.houseNumber << std::endl;
    std::cout << "Номер квартиры: " << addr.apartmentNumber << std::endl;
    std::cout << "Индекс: " << addr.postalCode << std::endl;
    std::cout << std::endl;
}

int main()
{
    Address addr1 = {"Москва", "Арбат", 12, 8, 123456};
    Address addr2 = {"Ижевск", "Пушкина", 59, 143, 953769};

    printAddress(addr1);
    printAddress(addr2);

    return 0;
}