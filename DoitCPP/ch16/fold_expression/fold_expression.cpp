#include <iostream>

template<typename doll>
doll show_doll(doll doll_name) {
	return "'" + doll_name + "' ���ʿ� ";
}

template<typename... dolls>
std::string find_doll(dolls... doll_list) {
	// ���� ǥ���� ���
	return (show_doll(doll_list) + ...);
}

int main() {
	std::cout << "ù��° ��Ʈ���ī ";
	std::cout << find_doll(std::string{"����"}, std::string{"����"}, std::string{"����"});
	std::cout << "�ֽ��ϴ�." << std::endl << std::endl;

	std::cout << "�ι�° ��Ʈ���ī ";
	std::cout << find_doll(std::string{"Ư����"}, std::string{"����"}, std::string{"����"}, std::string{"����"}, std::string{"�ؼ���"});
	std::cout << "�ֽ��ϴ�." << std::endl;

	return 0;
}