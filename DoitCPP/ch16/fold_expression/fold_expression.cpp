#include <iostream>

template<typename doll>
doll show_doll(doll doll_name) {
	return "'" + doll_name + "' 안쪽에 ";
}

template<typename... dolls>
std::string find_doll(dolls... doll_list) {
	// 폴드 표현식 사용
	return (show_doll(doll_list) + ...);
}

int main() {
	std::cout << "첫번째 마트료시카 ";
	std::cout << find_doll(std::string{"대형"}, std::string{"중형"}, std::string{"소형"});
	std::cout << "있습니다." << std::endl << std::endl;

	std::cout << "두번째 마트료시카 ";
	std::cout << find_doll(std::string{"특대형"}, std::string{"대형"}, std::string{"중형"}, std::string{"소형"}, std::string{"극소형"});
	std::cout << "있습니다." << std::endl;

	return 0;
}