#include <iostream>

int main() {

	int int_a = 10;

	// ���� �տ� �ĸ� ����ϰ� false�� ��� �׳� �Ѿ��. 
	if (0 && ++int_a)
		std::cout << "haha" << std::endl;

	std::cout << int_a << std::endl;

	return 0;
}
