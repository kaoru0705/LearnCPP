#include <iostream>
#include <string>

int main() {
    int customer_num = 0;

    std::cout << "���� �湮 �մ�: ";
    std::cin >> customer_num;   // �մ� �� �Է�

    std::string *bread = new std::string[customer_num];  // �մ� ����ŭ string �迭 ����

    // �Է¹��� �մ� ����ŭ �ݺ�
    for (int i = 0; i < customer_num; i++) {
        bread[i] = "��_" + std::to_string(i);       // ����_���ڡ� ���·� �迭�� ���� 
    }

    std::cout << std::endl << "--����� ��--" << std::endl;
    for (int i = 0; i < customer_num; i++) {
        std::cout << *(bread + i) << std::endl;   // ����� �� ���(������ ���� ����)
    }

    delete[] bread;   // string �迭 ����

    return 0;
}
