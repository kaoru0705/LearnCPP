#include <iostream>
#include <algorithm>
#include <vector>


int main() {
    // ���ĵ��� ���� ����
    std::vector<int> numbers { 8, 3, 1, 7, 4, 5, 9, 2, 6 };

    // ���� ����
    sort(numbers.begin(), numbers.end());

    // ����ڿ��� ���� �Է� �ޱ�
    int target;
    std::cout << "�����̳ʿ��� �˻��ϰ� ���� ���ڸ� �Է��غ�����: ";
    std::cin >> target;

    // ���� Ž��
    bool found = binary_search(numbers.begin(), numbers.end(), target);

    if (found) {
        std::cout << "ã�ҽ��ϴ�." << std::endl;
    }
    else {
        std::cout << "����Ǿ� ���� �ʽ��ϴ�." << std::endl;
    }

    return 0;
}
