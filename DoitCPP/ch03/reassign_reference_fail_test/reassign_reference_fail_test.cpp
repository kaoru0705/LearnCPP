#include <iostream>


int main() {
	int value{ 10 };
	int& ref_value{ value };

	int value2{ 20 };
	ref_value = value2;   // ���۷��� ������ �Ұ� �׳� ���� �ٲ��. ���� value�� ���� 20�� �ȴ�.

	std::cout << "value: " << value << std::endl;
	std::cout << "ref_value: " << ref_value << std::endl;

	return 0;
}
