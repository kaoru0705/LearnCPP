#include <iostream>
#include <string>

class bank {
private:
	int safe; //금고
	std::string bank_name;

public:
	bank(std::string name) : bank_name{ name } { safe = 0; };  //기본 생성자  
	~bank() {};
	void use_counter(int _in, int _out);  //입출금 창구 함수
	void transfer_account(int safe);      // 계좌 변경 함수
	void reset_account();                 // 계좌 초기화
	int get_safe() { return safe; };      // 금고 금액 반환
	bank& deposit_interest(int interest); // 이자 입금
	bank& withdraw_utility(int utility);  // 공과금 출금
	bank& withdraw_tax(int tax);          // 세금 출금

	std::string get_bank_name() { return bank_name; };
};

void bank::use_counter(int _in, int _out) {
	safe += _in;
	safe -= _out;
	std::cout << bank_name << " 처리 - 입금: " << _in << ", 출금: " << _out << std::endl;
}

void bank::transfer_account(int safe) {
	this->safe = safe;
	std::cout << bank_name << "으로 계좌 이동: " << safe << std::endl;
}

void bank::reset_account() {
	this->safe = 0;
	std::cout << bank_name << " 계좌가 초기화 되었습니다." << std::endl;
}

bank& bank::deposit_interest(int interest) {
	safe += interest;
	std::cout << bank_name << " 이자 지급: " << interest << std::endl;
	return *this;
}

bank& bank::withdraw_utility(int utility) {
	safe -= utility;
	std::cout << bank_name << " 공과금 납부: " << utility << std::endl;
	return *this;
}

bank& bank::withdraw_tax(int tax) {
	safe -= tax;
	std::cout << bank_name << " 세금 납부: " << tax << std::endl;
	return *this;
}

int main() {
	bank rich_bank{ "부유한 은행" }, global_bank{ "세계적 은행" };
	rich_bank.use_counter(50, 10);
	std::cout << std::endl;

	global_bank.transfer_account(rich_bank.get_safe());
	rich_bank.reset_account();
	std::cout << std::endl;

	// 함수 체이닝 호출(함수가 차례로 호출됨)
	global_bank.deposit_interest(10).withdraw_utility(1).withdraw_tax(2);
	std::cout << std::endl;
	std::cout << global_bank.get_bank_name() << "잔액: " << global_bank.get_safe() << std::endl;

	return 0;
}

//bank& 가 맞는 이유
//bank = 타입 이름
//
//& = 참조 타입을 만든다는 표시
//
//bank & = "bank 타입 객체를 참조하는 것"
//
//즉,
//
//cpp
//복사
//편집
//bank & ref = someBank;
//이건 "someBank라는 bank 객체를 참조하는 ref"라는 뜻이에요.
// this = &richbank bank & ref = richbank 이므로 bank&를 반환해야 될 때는 당연히 this*이다.