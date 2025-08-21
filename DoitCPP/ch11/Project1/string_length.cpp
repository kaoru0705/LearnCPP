#include <iostream>
#include <string>

int main() {
	std::string str1{ "Hello" };

	std::cout << str1 << std::endl;

	std::cout << str1.length() << std::endl;
	std::cout << str1.size() << std::endl;

	return 0;
}
