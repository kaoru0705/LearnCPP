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
// lvalue는 modifiable lvalue와 non-modifiable lvalue가 있다. const constexpr 같은 게 non-modifiable이다.
// lvalue가 right operand일 때 rvalue expression이 된다.

// int a = 5;
// int& ref = a; 이건 알고 있다. lvalue라면 is_lvalue(T&) 쪽으로 갈 것이다.
// int& ref = 5; 이건 불가능하다. 리터럴 5는 임시값 literal이고 값을 evaluate할 뿐이다. expression의 범위를 벗어나면 사라진다.
// int&& ref = 5; c++11부터 등장했다.임시값을 붙잡아둘 수 있다.

/*
int& operator++() {
    *this += 1;
    return *this;  // 참조 반환 → lvalue
}
*/

/*
int operator++(int) {  // dummy int parameter
    MyType temp = *this;
    *this += 1;
    return temp;        // 값 반환 → rvalue
}
*/
// std::string{"Hello"}는 임시 객체 rvalue
// "hello"는 배열 객체 lvalue다. 문자열 리터럴은 자동으로 포인터로 변환되니 rvalue처럼 느껴질 수 있다.