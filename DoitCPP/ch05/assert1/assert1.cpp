#include <iostream>
#include <cassert>  


void print_number(int* _pt_int) {
	assert(_pt_int != NULL);
	std::cout << *_pt_int << std::endl;
}

int main() {
	int a = 100;
	int* b = NULL;
	int* c = NULL;

	b = &a;
	print_number(b);

	// c�� NULL�� ���·� ���� ����
	print_number(c);

	return 0;
}
