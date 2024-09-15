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

    std::string getOutputAddress() const {
        return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment);
    }

    bool operator<(const Address& other) const {
        return city < other.city;
    }
};

void sortAddresses(std::vector<Address>& addresses) {
    std::sort(addresses.begin(), addresses.end());
}

int main() {
    std::ifstream in("in.txt");
    std::ofstream out("out.txt");

    int n;
    in >> n;

    std::vector<Address> addresses;
    addresses.reserve(n);

    for (int i = 0; i < n; ++i) {
        std::string city, street;
        int house, apartment;
        in >> city >> street >> house >> apartment;
        addresses.emplace_back(city, street, house, apartment);
    }

    sortAddresses(addresses);

    out << addresses.size() << "\n";
    for (const auto& address : addresses) {
        out << address.getOutputAddress() << "\n";
    }

    return 0;
}