/* https://eli.thegreenplace.net/2012/02/06/dependent-name-lookup-for-c-templates */
#include <iostream>

template <typename T> class Base {
public:
    typedef int MyType;
};

template <typename T> class Derived : public Base<T> {
public:
    void g() {
        // A. error: ‘MyType’ was not declared in this scope
        // MyType k = 2;

        // B. error: need ‘typename’ before ‘Base<T>::MyType’ because
        // ‘Base<T>’ is a dependent scope
        // Base<T>::MyType k = 2;

        // C. works!
        typename Base<T>::MyType k = 2;

        std::cout << "Derived<T>::g --> " << k << std::endl;
    }
};

int main()
{
    Derived<float> df;
    df.g();


    return 0;
}
//  MyType 타입의 지역 변수 k를 선언하려는 세 가지 시도가 나와 있습니다. 처음 두 개는 컴파일 오류를 발생시켜 주석 처리했습니다.
//   
//  (A)는 이제 명확해졌을 것입니다. MyType 은 종속적이지 않기 때문에 Base 클래스에서 찾을 수 없습니다. 이전과 동일한 문제입니다.
//  
//  하지만 (B)는 왜 작동하지 않을까요?
//  Base<T>는 특수화될 수 있기 때문에 컴파일러는 MyType이 type인지 아닌지 확신할 수 없기 때문입니다.
//  특수화는 type으로 두는 것 대신에 MyType이라 불리는 메서드로 선언할 수 있습니다. 또한 컴파일러는 인스턴스화 시점까지 이 결정을 미룰 수 없습니다.
//  MyType이 type인지 아닌지의 여부는 정의의 나머지 부분이 어떻게 구문 분석되는지에 영향을 미치기 때문입니다.
//  따라서 정의 시점에 MyType이 타입인지 여부를 컴파일러에 명시적으로 알려줘야 합니다.
//  default는 "not a type"이며, 컴파일러에게 타입 임을 알리기 위해 이름 앞에 typename 을 붙여야 합니다. 이는 C++ 표준 14.6절에 명시되어 있습니다.