// https://www.learncpp.com/cpp-tutorial/introduction-to-the-copy-constructor/
// generateFraction은 main에 a Fraction을 반환할 때 이 임시 Fraction은 생성되고 복사생성자를 사용하여 초기화된다.
// 이 임시 Fraction은 f2를 초기화하는 데 사용되므로 복사생성자를 또 호출시킨다.
// 그리고 printFraction이 복사 생성자를 세 번째 호출 시킴
// Copy constructor called
// Copy constructor called
// Copy constructor called
// Fraction(1, 2)

// 허나 컴파일러 최적화 기법인 copy elision으로 인해 여기서는 한 번만 호출됐다.
// https://www.learncpp.com/cpp-tutorial/class-initialization-and-copy-elision/
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

Fraction generateFraction(int n, int d)
{
    Fraction f{ n, d };
    return f;
}

int main()
{
    Fraction f2{ generateFraction(1, 2) }; // Fraction is returned using copy constructor

    printFraction(f2); // f2 is copied into the function parameter using copy constructor

    return 0;
}