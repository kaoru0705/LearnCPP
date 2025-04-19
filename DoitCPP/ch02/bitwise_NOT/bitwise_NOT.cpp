#include <iostream>

int main() {

	int value = 0x00000000;

	value = ~value;
	std::cout << std::hex << value << std::endl;

	return 0;
}