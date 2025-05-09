#include <iostream>
#include <bitset>

int main() {
	int a = 13;
	int b = 27;
	int c = a & b; //  비트 연산자 AND 사용
	int d = a | b; //  OR
	int e = a ^ b; //  XOR
	/*int f = a >> -1;
	int g = a << 32;*/ //warnings


	std::cout << "a = " << std::bitset<8>(a) << " : " << a << std::endl;
	std::cout << "b = " << std::bitset<8>(b) << " : " << b << std::endl;
	std::cout << "c = " << std::bitset<8>(c) << " : " << c << std::endl;
	std::cout << "d = " << std::bitset<32>(d) << " : " << d << std::endl;
	std::cout << "e = " << std::bitset<8>(e) << " : " << e << std::endl;
	//std::cout << "f = " << std::bitset<8>(f) << " : " << f << std::endl;


	return 0;
}
