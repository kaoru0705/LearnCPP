#include <iostream>

int main() {

	int int_a = 10;

	// 역시 앞에 식만 계산하고 false일 경우 그냥 넘어간다. 
	if (0 && ++int_a)
		std::cout << "haha" << std::endl;

	std::cout << int_a << std::endl;

	return 0;
}
