#include <iostream>
#include <stdexcept>

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

    Fraction operator+(const Fraction& other) const
    {
        return Fraction(numerator_ * other.denominator_ + other.numerator_ * denominator_,
                        denominator_ * other.denominator_);
    }

    Fraction operator-(const Fraction& other) const
    {
        return Fraction(numerator_ * other.denominator_ - other.numerator_ * denominator_,
                        denominator_ * other.denominator_);
    }

    Fraction operator*(const Fraction& other) const
    {
        return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_);
    }

    Fraction operator/(const Fraction& other) const
    {
        if (other.numerator_ == 0) {throw std::invalid_argument("Cannot divide by zero.");}
        return Fraction(numerator_ * other.denominator_, denominator_ * other.numerator_);
    }

    Fraction operator-() const {return Fraction(-numerator_, denominator_);}

    Fraction& operator++()
    {
        numerator_ += denominator_;
        simplify();
        return *this;
    }


    Fraction operator++(int)
    {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }

    Fraction& operator--()
    {
        numerator_ -= denominator_;
        simplify();
        return *this;
    }

    Fraction operator--(int)
    {
        Fraction temp = *this;
        --(*this);
        return temp;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction)
    {
        os << fraction.numerator_ << '/' << fraction.denominator_;
        return os;
    }
};

int main()
{
    int num1, denom1, num2, denom2;

    std::cout << "Введите числитель дроби 1: ";
    std::cin >> num1;
    std::cout << "Введите знаменатель дроби 1: ";
    std::cin >> denom1;
    std::cout << "Введите числитель дроби 2: ";
    std::cin >> num2;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> denom2;

    Fraction f1(num1, denom1);
    Fraction f2(num2, denom2);

    std::cout << f1 << " + " << f2 << " = " << (f1 + f2) << '\n';
    std::cout << f1 << " - " << f2 << " = " << (f1 - f2) << '\n';
    std::cout << f1 << " * " << f2 << " = " << (f1 * f2) << '\n';
    std::cout << f1 << " / " << f2 << " = " << (f1 / f2) << '\n';

    std::cout << "++" << f1 << " * " << f2 << " = " << (++f1 * f2) << '\n';
    std::cout << "Значение дроби 1 = " << f1 << '\n';

    std::cout << f1 << "-- * " << f2 << " = " << (f1-- * f2) << '\n';
    std::cout << "Значение дроби 1 = " << f1 << '\n';

    return 0;
}
