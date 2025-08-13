#include <iostream>
/*
Cpp�� Ŭ������ ���������ڸ� �����ϴ� �� �ƴ϶� ��ӹ��� Ŭ������ ���������ڸ� ������ �� �ִ�.
superclass�� �ɹ����� public���� ������ ��� �״���̸� private�̸� ���� private���� �ٲ��, protected�̸� public�� protected�� �ٲ��.
���� ������ �켱���� private > protected > public
��� ���� �������� �켱�������� ���� ���� �����ڴ� ��� ��� ���� �����ڷ� ����ȴ�. 290p
���� �����ڸ� �����ϸ� �⺻ ���� ������(default access specifier)�� �Ǵµ�, c++���� �⺻ ���� �����ڴ� private�̴�. ����ü�� public
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