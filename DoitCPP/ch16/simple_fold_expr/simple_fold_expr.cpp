#include <iostream>

// ���� ���� ���� ǥ����
template<typename... numbers>
double unary_left(numbers... num_list) {
    return (... / num_list);
}

// ���� ������ ���� ǥ����
template<typename... numbers>
double unary_right(numbers... num_list) {
    return (num_list / ...);
}

// ���� ���� ���� ǥ����
template<typename... numbers>
double binary_left(numbers... num_list) {
    return (10.0 / ... / num_list);
}

// ���� ������ ���� ǥ����
template<typename... numbers>
double binary_right(numbers... num_list) {
    return (num_list / ... / 10.0);
}

int main() {

    std::cout << "���� ���� ���� ǥ����: " <<
        unary_left(1.0, 2.0, 3.0, 4.0, 5.0, 6.0) << std::endl;

    std::cout << "���� ������ ���� ǥ����: " <<
        unary_right(1.0, 2.0, 3.0, 4.0, 5.0, 6.0) << std::endl;

    std::cout << "���� ���� ���� ǥ����: " <<
        binary_left(1.0, 2.0, 3.0, 4.0, 5.0, 6.0) << std::endl;

    std::cout << "���� ������ ���� ǥ����: " <<
        binary_right(1.0, 2.0, 3.0, 4.0, 5.0, 6.0) << std::endl;

    return 0;
}