#include <iostream>


int main() {
	int value{ 10 };
	int& ref_value{ value };

	int value2{ 20 };
	ref_value = value2;   // 레퍼런스 재지정 불가 그냥 값을 바꿨다. 따라서 value의 값도 20이 된다.

	std::cout << "value: " << value << std::endl;
	std::cout << "ref_value: " << ref_value << std::endl;

	return 0;
}
