/* https://eli.thegreenplace.net/2012/02/06/dependent-name-lookup-for-c-templates */

#include <iostream>

//template <typename T> class Base {
//public:
//    void f() {
//        std::cout << "    Base<T>::f" << std::endl;
//    }
//};
//
//template <typename T> class Derived : public Base<T> {
//public:
//    void g() {
//        std::cout << "Derived<T>::g" << std::endl; 
//        f(); // error 'f': identifier not found
//    }
//};
// 위의 Derived<T>::g 의 의도는 Base<T>::f를 호출하는 것이지만, 컴파일러는 대신 다음 오류를 생성합니다.
// 컴파일러가 호출 f 가 템플릿 매개변수 T 에 종속된다는 것을 이해하도록 만들기만 하면 됩니다.
// 이를 위한 몇 가지 방법은 f() 를 Base<T>::f() 로 바꾸 거나 this->f() 로 바꾸는 것입니다(this 는 T 에 암묵적으로 종속되기 때문입니다).

template <typename T> class Base {
public:
    void f() {
        std::cout << "    Base<T>::f" << std::endl;
    }
};

template <typename T> class Derived : public Base<T> {
public:
    void g() {
        std::cout << "Derived<T>::g" << std::endl;
        //this->f();
        //Base<T>::f();
    }
};
// 위처럼 적으면 문제 해결. 근데 왜?
// Base class를 specialization(명시적 특수화) 시켜보자.
template <>
class Base<int> {
public:
    void f() {
        std::cout << "    Base<int>::f" << std::endl;
    }
};
/*
Derived<T>::g
    Base<T>::f
Derived<T>::g
    Base<int>::f
*/
// 어떻게 Derived<int>가 요구했을 때 base template은 int로 특수화어 있는 건가? 컴파일러는 어떻게 이해했지? Base<int>는 Derived<int> 뒤에 정의돼 있잖아!


// 컴파일러가 코드에서 어떤 이름을 확인하려고 할 때, 먼저 해당 이름이 종속적인지 여부를 판단하며, 확인 과정은 이러한 구분에서 시작됩니다.
// 종속적이지 않은 이름은 "정상적으로" 확인되지만, 템플릿이 정의될 때 종속적인 이름은 템플릿의 인스턴스화 시점에 확인됩니다. 이것이 위 예에서 특수화가 올바르게 인식되도록 하는 것입니다.
// 이제 원래 문제로 돌아가 보겠습니다. 컴파일러가 Base 클래스에서 f를 찾지 않는 이유는 무엇일까요?
// 먼저, 첫 번째 코드 f() 호출에서 f는 종속되지 않는 이름입니다.
// 따라서 템플릿 정의 지점에서 f를 확인해야 합니다. 그 시점에서 컴파일러는 Base<T>::f 가 무엇인지 여전히 알지 못합니다. 나중에 특수화될 수 있기 때문입니다.
// 따라서 컴파일러는 Base 클래스에서 이름을 찾지 않고, 감싸는 범위에서만 이름을 찾습니다. 감싸는 범위에 f가 없기 때문에 컴파일러는 오류를 발생시킵니다.
// 반면, this-> 를 통해 f를 호출하여 명시적으로 f찾기(look-up)를 dependent로 만들면 찾기 규칙이 변경됩니다.
// 이제 f는 템플릿의 인스턴스화 지점에서 확인되며, 컴파일러는 이 지점에서 Base 클래스를 완전히 이해하고 이름을 올바르게 확인할 수 있습니다.

int main()
{
    Derived<float> df;
    df.g();

    Derived<int> di;
    di.g();
    return 0;
}