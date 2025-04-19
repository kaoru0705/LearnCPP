#include <iostream>


int value = 1;   // 전역 변수

int main() {
	int value = -1;   // 지역 변수

	std::cout << value << std::endl;     // 지역 변수 출력
	std::cout << ::value << std::endl;   // 전역 변수 출력

	return 0;
}
