#include <iostream>
#include <array>

int main() {
    // ũ�Ⱑ 5�� std::array ����
    std::array<int, 5> myArray;

    // �迭 �ʱ�ȭ
    myArray = { 1, 2, 3, 4, 5 };

    // �迭 ���
    std::cout << "�迭 ���: ";
    for (int i = 0; i < 5; i++) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    // �迭 ũ�� ���
    std::cout << "�迭 ũ��: " << myArray.size() << std::endl;

    // �迭�� ù ��° ��� ���
    std::cout << "ù ��° ���: " << myArray.at(0) << std::endl;

    // �迭�� �� ��° ��� ����
    myArray[1] = 10;

    // ����� �迭 ���
    std::cout << "����� �迭: ";
    for (int i = 0; i < 5; i++) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
