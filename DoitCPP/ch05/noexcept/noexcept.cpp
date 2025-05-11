#include <iostream>

void real_noexcept() noexcept
{
	std::cout << "real_noexcept" << std::endl;
}

void fake_noexcept() noexcept
{
	std::cout << "fake_noexcept" << std::endl;
	throw 1;
}

int main() {
	real_noexcept();

	std::cout << noexcept(real_noexcept()) << std::endl;
	try
	{
		fake_noexcept();
	}
	catch (int exec)
	{
		std::cout << "catch " << exec << std::endl;
	}

	return 0;
}