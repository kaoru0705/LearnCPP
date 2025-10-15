#include <iostream>
#include <string>

// T& is an lvalue reference, so this overload will be preferred for lvalues
template <typename T>
constexpr bool is_lvalue(T&)
{
    return true;
}

// T&& is an rvalue reference, so this overload will be preferred for rvalues
template <typename T>
constexpr bool is_lvalue(T&&)
{
    return false;
}

// A helper macro (#expr prints whatever is passed in for expr as text)
#define PRINTVCAT(expr) { std::cout << #expr << " is an " << (is_lvalue(expr) ? "lvalue\n" : "rvalue\n"); }

int getint() { return 5; }

int main()
{
    PRINTVCAT(5);        // rvalue
    PRINTVCAT(getint()); // rvalue
    int x{ 5 };
    PRINTVCAT(x);        // lvalue
    PRINTVCAT(std::string{ "Hello" }); // rvalue
    PRINTVCAT("Hello");  // lvalue
    PRINTVCAT(++x);      // lvalue
    PRINTVCAT(x++);      // rvalue
}
// lvalue�� modifiable lvalue�� non-modifiable lvalue�� �ִ�. const constexpr ���� �� non-modifiable�̴�.
// lvalue�� right operand�� �� rvalue expression�� �ȴ�.

// int a = 5;
// int& ref = a; �̰� �˰� �ִ�. lvalue��� is_lvalue(T&) ������ �� ���̴�.
// int& ref = 5; �̰� �Ұ����ϴ�. ���ͷ� 5�� �ӽð� literal�̰� ���� evaluate�� ���̴�. expression�� ������ ����� �������.
// int&& ref = 5; c++11���� �����ߴ�.�ӽð��� ����Ƶ� �� �ִ�.

/*
int& operator++() {
    *this += 1;
    return *this;  // ���� ��ȯ �� lvalue
}
*/

/*
int operator++(int) {  // dummy int parameter
    MyType temp = *this;
    *this += 1;
    return temp;        // �� ��ȯ �� rvalue
}
*/
// std::string{"Hello"}�� �ӽ� ��ü rvalue
// "hello"�� �迭 ��ü lvalue��. ���ڿ� ���ͷ��� �ڵ����� �����ͷ� ��ȯ�Ǵ� rvalueó�� ������ �� �ִ�.