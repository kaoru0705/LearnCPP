#include <iostream>
#include <array>
#include <algorithm>

constexpr int even{0};
constexpr int odd {1};

int main() {
    std::array<int, 5> data_array{ 47, 23, 58, 10, 36 };

    // if ���� �ʱ�ȭ ���� ���
    if (auto element = data_array[3]; element > 20) {
        std::cout << "�� ��° ��Ұ��� 20���� Ů�ϴ�." << std::endl;
    }
    else {
        std::cout << "�� ��° ��Ұ��� 20���� �۰ų� �����ϴ�." << std::endl;
    }

    // switch ���� �ʱ�ȭ ���� ���
    switch (auto element = data_array[4] % 2; element) {
    case odd:
        std::cout << "�ټ� ��° ��Ұ��� Ȧ�� �Դϴ�." << std::endl;
        break;
    case even:
        std::cout << "�ټ� ��° ��Ұ��� ¦�� �Դϴ�." << std::endl;
        break;
    }

    // ���� ��� for ���� �ʱ�ȭ ���� ���
    for (std::sort(data_array.begin(), data_array.end()); auto && element : data_array) {
        std::cout << element << ", ";
    }
    std::cout << std::endl;

    return 0;
}