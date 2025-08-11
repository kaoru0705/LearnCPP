#include <algorithm> // for std::max
#include <iostream>

/*
Because the C++ standard says so, the members in a member initializer list are always initialized in the order in which they are defined inside the class
(not in the order they are defined in the member initializer list).
*/
class Foo
{
private:
    int m_x{};
    int m_y{};

public:
    Foo(int x, int y)
        : m_y{ std::max(x, y) }, m_x{ m_y } // issue on this line
    {
    }

    void print() const
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
    }
};

int main()
{
    Foo foo{ 6, 7 };
    foo.print();

    return 0;
}