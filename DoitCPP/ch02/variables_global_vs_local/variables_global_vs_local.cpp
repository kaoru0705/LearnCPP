#include <iostream>


int value = 1;   // ���� ����

int main() {
	int value = -1;   // ���� ����

	std::cout << value << std::endl;     // ���� ���� ���
	std::cout << ::value << std::endl;   // ���� ���� ���

	return 0;
}
