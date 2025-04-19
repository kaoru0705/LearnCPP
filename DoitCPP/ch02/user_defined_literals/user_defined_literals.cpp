#include <iostream>
/* https://en.cppreference.com/w/cpp/language/user_literal#Literal_operators */

const long double km_per_mile = 1.609344L;

// _km ����� ���ͷ� ����
long double operator"" _km(long double val) {
	return val; // km ���ͷ�: �ƹ� �۾� ����  �״�� ��ȯ
}

// _mi ����� ���ͷ� ����
long double operator"" _mi(long double val) {
	return val * km_per_mile; // mi ���ͷ�: mile�� km�� ��ȯ�Ͽ� ��ȯ
}

int main() {
	long double distance_1 = 1.0_km;    // km�� �״�� ����
	long double distance_2 = 1.0_mi;    // mile�� km ������ ��ȯ�Ǿ� ����

	std::cout << distance_1 + distance_2 << " km" << std::endl;   // km������ ���

	return 0;
}