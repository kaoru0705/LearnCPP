/*https://www.learncpp.com/cpp-tutorial/introduction-to-the-copy-constructor/*/
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

    void print() const
    {
        std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
    }
};

int main()
{
    Fraction f{ 5, 3 };  // Calls Fraction(int, int) constructor
    Fraction fCopy{ f }; // What constructor is used here?

    f.print();
    fCopy.print();

    return 0;
}

// A copy constructor is a constructor that is used to initialize an object with an existing object of the same type.
// After the copy constructor executes, the newly created object should be a copy of the object passed in as the initializer.
// If you do not provide a copy constructor for your classes, C++ will create a public implicit copy constructor for you.
// ��� ���� �߿� �����ͺ����� �ִٸ�? �ּҸ� �Ű�����. �׷��� �����ε��� ����� ��.