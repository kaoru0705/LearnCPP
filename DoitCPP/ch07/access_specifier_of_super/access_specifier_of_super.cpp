#include <iostream>
/*
Cpp는 클래스의 접근지정자를 지정하는 게 아니라 상속받을 클래스의 접근지정자를 지정할 수 있다.
public으로 지정할 경우 그대로 이며 private이면 전부 private으로 바뀌고, protected이면 public변수는 protected로 바뀐다.
*/
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