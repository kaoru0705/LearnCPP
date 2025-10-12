// https://www.learncpp.com/cpp-tutorial/introduction-to-the-copy-constructor/
// generateFraction�� main�� a Fraction�� ��ȯ�� �� �� �ӽ� Fraction�� �����ǰ� ��������ڸ� ����Ͽ� �ʱ�ȭ�ȴ�.
// �� �ӽ� Fraction�� f2�� �ʱ�ȭ�ϴ� �� ���ǹǷ� ��������ڸ� �� ȣ���Ų��.
// �׸��� printFraction�� ���� �����ڸ� �� ��° ȣ�� ��Ŵ
// Copy constructor called
// Copy constructor called
// Copy constructor called
// Fraction(1, 2)

// �㳪 �����Ϸ� ����ȭ ����� copy elision���� ���� ���⼭�� �� ���� ȣ��ƴ�.
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