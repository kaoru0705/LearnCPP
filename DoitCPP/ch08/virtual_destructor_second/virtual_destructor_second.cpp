#include <iostream>

//�⺻ Monster Ŭ����
class monster {
public:
	monster();
	//~monster();
	virtual ~monster();
private:
	int* dummy;
};

monster::monster() {
	std::cout << "monster() ������ ȣ��" << std::endl;
	dummy = new int;
}

monster::~monster() {
	std::cout << "~monster() �Ҹ��� ȣ��" << std::endl;
	delete dummy;
}

//���� A�� �⺻ Monster Ŭ�����κ��� ���
class monster_a : public monster {
public:
	monster_a();
	//~monster_a();
	virtual ~monster_a();
private:
	int* dummy_a;
};

monster_a::monster_a() {
	std::cout << "monster_a() ������ ȣ��" << std::endl;
	dummy_a = new int;
}

monster_a::~monster_a() {
	std::cout << "~monster_a() �Ҹ��� ȣ��" << std::endl;
	delete dummy_a;
}

int main() {
	monster* mon = new monster_a();   // �θ� Ŭ������ ��ĳ����
	delete mon;
	return 0;
}