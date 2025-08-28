#include <iostream>
#include <array>


int main(void) {
    std::array<int, 10> numbers{ 7, 8, 2, 5, 3, 9, 0, 4, 1, 6 };

    // for ���� Ȱ�� �迭 ���
    for (int i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " , ";
    }
    std::cout << std::endl;

    void* test = nullptr;

    // ���� ��� for ���� Ȱ�� �迭 ���
    for (auto& value : numbers) {
        std::cout << value << " , ";
    }
    std::cout << std::endl;

    return 0;
}