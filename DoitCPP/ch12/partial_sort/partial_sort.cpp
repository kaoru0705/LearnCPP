#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers = { 7, 2, 5, 1, 8, 9, 3, 6, 4 };

    // numbers ���Ϳ��� ���� ���� 3���� ��Ҹ� ����
    partial_sort(numbers.begin(), numbers.begin() + 3, numbers.end());

    // ���ĵ� ��� ���
    for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}