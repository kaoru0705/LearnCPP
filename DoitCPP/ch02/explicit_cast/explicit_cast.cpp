#include <iostream>

int main() {
	int int_a = 10;
	int int_b = 5;

	int int_avg = (int_a + int_b) / 2;
	float float_avg_1 = (int_a + int_b) / 2;        // �Ͻ��� ����ȯ: ������ ����
	float float_avg_2 = float(int_a + int_b) / 2;   // ����� ����ȯ c++ style

	std::cout << "int_avg: " << int_avg << std::endl;
	std::cout << "float_avg_1: " << float_avg_1 << std::endl;
	std::cout << "float_avg_2: " << float_avg_2 << std::endl;

	return 0;
}
