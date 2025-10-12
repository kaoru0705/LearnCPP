// class가 copy constructor가 없으면 암묵적으로 생성한다. 하지만 원한다면 = default sytanx를 통해 default copy constructor를 요청할 수 있다.
#include <iostream>

class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    // Default constructor
    Fraction(int numerator = 0, int denominator = 1)
        : m_numerator{ numerator }, m_denominator{ denominator }
    {
    }

    // Explicitly request default copy constructor
    Fraction(const Fraction& fraction) = default;

    void print() const
    {
        std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
    }
};

int main()
{
    Fraction f{ 5, 3 };
    Fraction fCopy{ f };

    f.print();
    fCopy.print();

    return 0;
}