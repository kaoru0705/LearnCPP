#include <iostream>
#include <iomanip>
/* https://en.cppreference.com/w/cpp/types/numeric_limits/digits10 */
// std::setprecision(std::numeric_limits<double>::digits10 + 1) �̰� ���� ������� �����÷ο쳪 ���� ���� ��ȿ���ڸ� ������ �� �ִ�. +1�� �ִ� ��ȿ�ڸ����̴�.
int main() {
    float float_value = 9.87654321f;
    double double_value = 9.87654321987654321;
    long double long_double_value = 9.87654321987654321l;

    std::cout << "float : " << sizeof(float) << " bytes" << std::endl;
    std::cout << "float_value : " <<
        std::setprecision(std::numeric_limits<float>::digits10 + 1) <<
        float_value << std::endl << std::endl;

    std::cout << "float : " << sizeof(float) << " bytes" << std::endl;
    std::cout << "float_value : "  << float_value << std::endl << std::endl;


    std::cout << "double : " << sizeof(double) << " bytes" << std::endl;
    std::cout << "double_value : " << 
        std::setprecision(std::numeric_limits<double>::digits10 + 1) <<
        double_value << std::endl << std::endl;

    std::cout << "long double : " << sizeof(long double) << " bytes" << std::endl;
    std::cout << "long_double_value : " <<
        std::setprecision(std::numeric_limits<long double>::digits10 + 1) <<
        long_double_value << std::endl << std::endl;

    return 0;
}
