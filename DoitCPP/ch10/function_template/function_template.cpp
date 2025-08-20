#include <iostream>
#include <string>

template <typename T>
T data_sum(T operand1, T operand2) {
	return operand1 + operand2;
}

int main() {
	int data1{ 3 }, data2{ 5 };
	double data3{ 4.5 }, data4{ 8.9 };
	std::string data5{ "Hello, " }, data6{ "World!" };
	char data7[]{ "Hello, " }, data8[]{ "New World!" };

	std::cout << "정수형 데이터 합: " << data_sum(data1, data2) << std::endl;
	std::cout << "실수형 데이터 합: " << data_sum(data3, data4) << std::endl;
	std::cout << "문자열 데이터 합: " << data_sum(data5, data6) << std::endl;

	// 사용할 수 없는 인자 예제
	//std::cout << "문자데이터 배열의 합" << data_sum(data7, data8) << std::endl;
	std::cout << "문자데이터 배열의 합: " << data_sum<std::string>(data7, data8) << std::endl;

	return 0;
}
