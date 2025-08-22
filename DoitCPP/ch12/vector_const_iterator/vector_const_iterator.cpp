#include <iostream>
#include <vector>


int main() {
	std::vector<int> vec;
	vec.push_back(0);
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	std::vector<int>::const_iterator const_it = vec.cbegin();
	std::cout << *const_it << std::endl;

	++const_it;
	std::cout << *const_it << std::endl;

	const_it = vec.cend();
	--const_it;
	std::cout << *const_it << std::endl;

	return 0;
}
