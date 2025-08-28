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
//  However, this program is needlessly inefficient, as we’ve had to make two constructor calls: one to Something(int), and one to Something(const Something&).
//  Note that the end result of the above is the same as if we had written the following instead:
//  Something s { 5 }; // only invokes Something(int), no copy constructor
//  This version produces the same result, but is more efficient, as it only makes a call to Something(int) (no copy constructor is needed)
//  
//  컴파일러는 최적화를 위해 명령문을 자유롭게 다시 작성할 수 있으므로,
//  컴파일러가 불필요한 복사 Something s { Something{5} };를 최적화하여 마치 처음부터 Something s { 5 }를 작성한 것처럼 처리할 수 있을지 궁금할 수도 있습니다.
//  답은 '예'입니다. 이 과정을 복사 생략(copy elision) 이라고 합니다.
//  복사 생략은 컴파일러가 불필요한 객체 복사를 제거할 수 있도록 하는 컴파일러 최적화 기법입니다.
//  다시 말해, 컴파일러가 일반적으로 복사 생성자를 호출하는 경우, 컴파일러는 복사 생성자 호출을 완전히 피하기 위해 코드를 자유롭게 다시 작성할 수 있습니다.
//  컴파일러가 복사 생성자 호출을 최적화하여 제거하면, 생성자가 생략되었다고 합니다.
//  copy semantics가 아닌 move semantics를 알아야 한다.