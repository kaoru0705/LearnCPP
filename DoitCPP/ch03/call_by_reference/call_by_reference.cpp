#include <iostream>

void swap(int& ref_a, int& ref_b)
{
	std::cout << "[swap func] before swap, ref_a: " << ref_a << " ref_b: " << ref_b << std::endl;

	int temp = ref_a;
	ref_a = ref_b;
	ref_b = temp;

	std::cout << "[swap func] after swap, ref_a: " << ref_a << " ref_b: " << ref_b << std::endl;
}

int main()
{
	int a = 5;
	int b = 10;

	std::cout << "[main] before swap, a: " << a << " b: " << b << std::endl << std::endl;

	swap(a, b);

	std::cout << std::endl << "[main] after swap, a: " << a << " b: " << b << std::endl;

	return 0;
}