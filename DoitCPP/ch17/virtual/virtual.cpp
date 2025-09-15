#include <iostream>

// 다중 상속의 문제 : 다이아몬드 문제(Diamond Problem)
//
// 만약 두 부모 클래스가 같은 조상 클래스를 상속하고 있으면, 어떤 경로로 상속된 멤버를 써야 할지 모호성이 발생합니다.

//class Base { public: void hello() {} };
//class A : public Base {};
//class B : public Base {};
//class C : public A, public B {}; // 다이아몬드 구조


//C에서 hello()를 호출하면 A → Base와 B → Base 두 경로가 생겨서 모호성이 생깁니다.
//
//해결책: 가상 상속(Virtual Inheritance)
class Base { public: void hello() {} };
class A : virtual public Base {};
class B : virtual public Base {};
class C : public A, public B {}; // 이제 Base는 한 번만 상속됨