#include <iostream>
#include <string>

class bank {
private:
	int safe; //�ݰ�
	std::string bank_name;

public:
	bank(std::string name) : bank_name{ name } { safe = 0; };  //�⺻ ������  
	~bank() {};
	void use_counter(int _in, int _out);  //����� â�� �Լ�
	void transfer_account(int safe);      // ���� ���� �Լ�
	void reset_account();                 // ���� �ʱ�ȭ
	int get_safe() { return safe; };      // �ݰ� �ݾ� ��ȯ
	bank& deposit_interest(int interest); // ���� �Ա�
	bank& withdraw_utility(int utility);  // ������ ���
	bank& withdraw_tax(int tax);          // ���� ���

	std::string get_bank_name() { return bank_name; };
};

void bank::use_counter(int _in, int _out) {
	safe += _in;
	safe -= _out;
	std::cout << bank_name << " ó�� - �Ա�: " << _in << ", ���: " << _out << std::endl;
}

void bank::transfer_account(int safe) {
	this->safe = safe;
	std::cout << bank_name << "���� ���� �̵�: " << safe << std::endl;
}

void bank::reset_account() {
	this->safe = 0;
	std::cout << bank_name << " ���°� �ʱ�ȭ �Ǿ����ϴ�." << std::endl;
}

bank& bank::deposit_interest(int interest) {
	safe += interest;
	std::cout << bank_name << " ���� ����: " << interest << std::endl;
	return *this;
}

bank& bank::withdraw_utility(int utility) {
	safe -= utility;
	std::cout << bank_name << " ������ ����: " << utility << std::endl;
	return *this;
}

bank& bank::withdraw_tax(int tax) {
	safe -= tax;
	std::cout << bank_name << " ���� ����: " << tax << std::endl;
	return *this;
}

int main() {
	bank rich_bank{ "������ ����" }, global_bank{ "������ ����" };
	rich_bank.use_counter(50, 10);
	std::cout << std::endl;

	global_bank.transfer_account(rich_bank.get_safe());
	rich_bank.reset_account();
	std::cout << std::endl;

	// �Լ� ü�̴� ȣ��(�Լ��� ���ʷ� ȣ���)
	global_bank.deposit_interest(10).withdraw_utility(1).withdraw_tax(2);
	std::cout << std::endl;
	std::cout << global_bank.get_bank_name() << "�ܾ�: " << global_bank.get_safe() << std::endl;

	return 0;
}

//bank& �� �´� ����
//bank = Ÿ�� �̸�
//
//& = ���� Ÿ���� ����ٴ� ǥ��
//
//bank & = "bank Ÿ�� ��ü�� �����ϴ� ��"
//
//��,
//
//cpp
//����
//����
//bank & ref = someBank;
//�̰� "someBank��� bank ��ü�� �����ϴ� ref"��� ���̿���.
// this = &richbank bank & ref = richbank �̹Ƿ� bank&�� ��ȯ�ؾ� �� ���� �翬�� this*�̴�.