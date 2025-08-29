#include <iostream>

// 매개변수 팩을 이용한 가변 인자 템플릿 – 말단 함수용
template<typename doll>
// 매개변수 팩의 마지막 인자를 연산 하기 위한 함수
void find_doll(doll doll_name) {
	std::cout << "'" << doll_name << "'(이)가 ";
}

// 매개변수 팩을 이용한 가변 인자 템플릿 – 재귀 함수 용
template<typename doll, typename... dolls>
// find_dell 함수 오버로딩
void find_doll(doll doll_name, dolls... doll_list) {
	std::cout << "'" << doll_name << "' 안쪽에 ";
	// 재귀 호출
	find_doll(doll_list...);

}

int main() {
	std::cout << "첫 번째 마트료시카 ";
	// 가변 인자로 함수 호출
	find_doll("대형", "중형", "소형");
	std::cout << "있습니다." << std::endl << std::endl;

	std::cout << "두 번째 마트료시카 ";
	// 가변 인자로 함수 호출
	find_doll("특대형", "대형", "중형", "소형", "극소형");
	std::cout << "있습니다." << std::endl;

	return 0;
}