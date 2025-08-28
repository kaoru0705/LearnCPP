/* https://www.learncpp.com/cpp-tutorial/class-initialization-and-copy-elision/ */
#include <iostream>

class Something
{
    int m_x{};

public:
    Something(int x)
        : m_x{ x }
    {
        std::cout << "Normal constructor\n";
    }

    Something(const Something& s)
        : m_x{ s.m_x }
    {
        std::cout << "Copy constructor\n";
    }

    void print() const { std::cout << "Something(" << m_x << ")\n"; }
};

int main()
{
    Something s{ Something { 5 } }; // focus on this line
    s.print();

    return 0;
}
//  In the initialization of variable s above, we first construct a temporary Something, initialized with value 5 (which uses the Something(int) constructor).
//  This temporary is then used to initialize s.
//  Because the temporary and s have the same type (they are both Something objects),
//  the Something(const Something&) copy constructor would normally be called here to copy the values in the temporary into s.
//  The end result is that s is initialized with value 5.
//  However, this program is needlessly inefficient, as we��ve had to make two constructor calls: one to Something(int), and one to Something(const Something&).
//  Note that the end result of the above is the same as if we had written the following instead:
//  Something s { 5 }; // only invokes Something(int), no copy constructor
//  This version produces the same result, but is more efficient, as it only makes a call to Something(int) (no copy constructor is needed)
//  
//  �����Ϸ��� ����ȭ�� ���� ��ɹ��� �����Ӱ� �ٽ� �ۼ��� �� �����Ƿ�,
//  �����Ϸ��� ���ʿ��� ���� Something s { Something{5} };�� ����ȭ�Ͽ� ��ġ ó������ Something s { 5 }�� �ۼ��� ��ó�� ó���� �� ������ �ñ��� ���� �ֽ��ϴ�.
//  ���� '��'�Դϴ�. �� ������ ���� ����(copy elision) �̶�� �մϴ�.
//  ���� ������ �����Ϸ��� ���ʿ��� ��ü ���縦 ������ �� �ֵ��� �ϴ� �����Ϸ� ����ȭ ����Դϴ�.
//  �ٽ� ����, �����Ϸ��� �Ϲ������� ���� �����ڸ� ȣ���ϴ� ���, �����Ϸ��� ���� ������ ȣ���� ������ ���ϱ� ���� �ڵ带 �����Ӱ� �ٽ� �ۼ��� �� �ֽ��ϴ�.
//  �����Ϸ��� ���� ������ ȣ���� ����ȭ�Ͽ� �����ϸ�, �����ڰ� �����Ǿ��ٰ� �մϴ�.
//  copy semantics�� �ƴ� move semantics�� �˾ƾ� �Ѵ�.