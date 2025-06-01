#include <iostream>
#include <cassert>  


void print_number(int* _pt_int) {
	assert(_pt_int != NULL);
	std::cout << *_pt_int << std::endl;
}

int main() {
	int a{ 100 };
	int* b{ nullptr };
	int* c{ nullptr };

	b = &a;
	print_number(b);

	// c는 NULL인 상태로 인자 전달
	print_number(c);

	return 0;
}
