#include <iostream>


class bank {
private:
	int safe;    // �ݰ� 

public:
	bank();      // �⺻ ������  
	void use_counter(int _in, int _out);   // ����� â�� �Լ� 
};

bank::bank() {
	safe = 1000;    // ���� �ݰ� �ʱ� �ݾ� ���� 
	std::cout << "���� �ݰ� : " << safe << std::endl;
	std::cout << std::endl;
}

void bank::use_counter(int _in, int _out) {
	safe += _in;     // �Ա� 
	safe -= _out;    // ��� 

	std::cout << "�Ա� : " << _in << std::endl;
	std::cout << "��� : " << _out <<std::endl;
	std::cout << "�ݰ� : " << safe <<std::endl;
	std::cout << std::endl;
}

int main() {
	bank my_bank; // my_bank �ν��Ͻ� ����

	my_bank.use_counter(0, 20);     // ��� 20 
	my_bank.use_counter(50, 0);     // �Ա� 50 
	my_bank.use_counter(100, 50);   // �Ա� 100, ��� 50 

	return 0;
}
