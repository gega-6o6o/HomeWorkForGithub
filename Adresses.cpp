#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

class Address {
private:
    std::string city;
    std::string street;
    int house;
    int apartment;

public:
    Address(const std::string& city, const std::string& street, int house, int apartment)
        : city(city), street(street), house(house), apartment(apartment) {}

    std::string get_output_address() const {
        return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment);
    }
};

int main() {
    std::ifstream in_file("in.txt");
    std::ofstream out_file("out.txt");

    if (!in_file.is_open() || !out_file.is_open()) {
        std::cerr << "Не удалось открыть файл" << std::endl;
        return 1;
    }

    int num_addresses;
    in_file >> num_addresses;

    std::vector<Address> addresses;
    addresses.reserve(num_addresses);

    for (int i = 0; i < num_addresses; ++i) {
        std::string city, street;
        int house, apartment;
        in_file >> city >> street >> house >> apartment;
        addresses.emplace_back(city, street, house, apartment);
    }

    out_file << num_addresses << std::endl;
    std::for_each(addresses.rbegin(), addresses.rend(), [&out_file](const Address& address) {
        out_file << address.get_output_address() << std::endl;
    });

    in_file.close();
    out_file.close();

    return 0;
}