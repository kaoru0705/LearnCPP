#include <iostream>
#include <cstdlib>  // exit�� set_terminate �Լ� ����� ���� �߰�


// ���� ó�� �Լ� 
void myterminate() {
	std::cout << "myterminate called" << std::endl;
	exit(-1);      // ���α׷��� ������������ ����
}

int main(void) {
	set_terminate(myterminate);    // ���� ó�� �Լ��� myterminate�� ����

	throw 1;    // ó������ �ʴ� ���ܸ� ����

	return 0;   // �� ���� ������� ����, ������ ���ܰ� �������� ����
}