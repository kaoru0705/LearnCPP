#include <iostream>

class Base {
public:
	int a;
private:
	int b;
protected:
	int c;
};

class Derived : private Base {
public:
	Derived() {
		a = 5;
		b = 6;
		c = 7;
	}
};

int main() {
	Derived f;
	f.a;
	f.b;
	f.c;

	std::cout << f.a << std::endl;

	return 0;
}