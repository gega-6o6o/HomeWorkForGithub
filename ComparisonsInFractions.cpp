#include <iostream>

class Fraction
{
private:
    int numerator_;
    int denominator_;

    int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}

    void simplify()
    {
        int divisor = gcd(numerator_, denominator_);
        numerator_ /= divisor;
        denominator_ /= divisor;
        if (denominator_ < 0)
        {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
    }

public:
    Fraction(int numerator, int denominator) : numerator_(numerator), denominator_(denominator)
    {
        if (denominator == 0) {throw std::invalid_argument("Denominator cannot be zero.");}
        simplify();
    }

    bool operator==(const Fraction& other) const {return numerator_ * other.denominator_ == other.numerator_ * denominator_;}

    bool operator!=(const Fraction& other) const {return !(*this == other);}

    bool operator<(const Fraction& other) const {return numerator_ * other.denominator_ < other.numerator_ * denominator_;}

    bool operator>(const Fraction& other) const {return other < *this;}

    bool operator<=(const Fraction& other) const {return !(*this > other);}

    bool operator>=(const Fraction& other) const {return !(*this < other);}
};

int main()
{
    Fraction f1(4, 3);
    Fraction f2(6, 11);

    std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
    std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
    std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
    std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
    std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
    std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
    return 0;
}
