// https://www.learncpp.com/cpp-tutorial/introduction-to-the-copy-constructor/
// object가 값으로서 전달될 때 arguement(실질 매개변수 전달되는 값)가 parameter로 복사된다. arguement와 parameter가 같은 클래스 타입일 때 내부적으로 copy constructor가 호출된다. 
// the call to printFraction(f) is passing f by value.
// The copy constructor is invoked to copy f from main into the f parameter of function printFraction().
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

    // Copy constructor
    Fraction(const Fraction& fraction)
        : m_numerator{ fraction.m_numerator }
        , m_denominator{ fraction.m_denominator }
    {
        std::cout << "Copy constructor called\n";
    }

    void print() const
    {
        std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
    }
};

void printFraction(Fraction f) // f is pass by value
{
    f.print();
}

int main()
{
    Fraction f{ 5, 3 };

    printFraction(f); // f is copied into the function parameter using copy constructor

    return 0;
}