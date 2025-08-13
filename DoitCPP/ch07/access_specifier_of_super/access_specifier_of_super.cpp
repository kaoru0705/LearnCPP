#include <iostream>
/*
Cpp는 클래스의 접근지정자를 지정하는 게 아니라 상속받을 클래스의 접근지정자를 지정할 수 있다.
superclass의 맴버들이 public으로 지정할 경우 그대로이며 private이면 전부 private으로 바뀌고, protected이면 public은 protected로 바뀐다.
접근 지정자 우선순위 private > protected > public
상속 접근 지정자의 우선순위보다 낮은 접근 지정자는 모두 상속 접근 지정자로 변경된다. 290p
접근 지정자를 생략하면 기본 접근 지정자(default access specifier)가 되는데, c++에서 기본 접근 지정자는 private이다. 구조체는 public
https://www.learncpp.com/cpp-tutorial/inheritance-and-access-specifiers/
Note that this does not affect the way that the derived class accesses members inherited from its parent!
*/
class Base {
public:
	int a{};
private:
	int b{};
protected:
	int c{};
};

class Derived1 : public Base {
public:
	Derived1() {
		a = 5;
		b = 6;
		c = 7;
	}
};

class Derived2 : private Base {
public:
	Derived2() {
		a = 5;
		b = 6;
		c = 7;
	}
};

class Derived3 : protected Base {
public:
	Derived3() {
		a = 5;
		b = 6;
		c = 7;
	}
};

int main() {
	Derived1 dr1;
	Derived2 dr2;
	Derived3 dr3;

	dr1.a;
	dr1.b;
	dr1.c;

	dr2.a;
	dr2.b;
	dr2.c;

	dr3.a;
	dr3.b;
	dr3.c;

	return 0;
}