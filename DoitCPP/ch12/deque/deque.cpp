#include <iostream>
#include <deque>


int main() {
    std::deque<int> myDeque;

    // �� ���ʿ� �� �߰�
    myDeque.push_back(2);
    myDeque.push_back(3);
    myDeque.push_back(4);

    // �� ���ʿ� �� �߰�
    myDeque.push_front(1);
    myDeque.push_front(0);

    // �� ���
    std::cout << "deque ���: ";
    for (const int& value : myDeque) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    myDeque.pop_front();   // ù ��° ��� ����
    myDeque.pop_back();  // ������ ��� ����

    // ���� �� �� ���
    std::cout << "���� �� deque ���: ";
    for (const int& value : myDeque) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // �� ũ�� Ȯ��
    std::cout << "deque ũ��: " << myDeque.size() << std::endl;

    // ���� ������� Ȯ��
    std::cout << "deque�� ����°�? " << (myDeque.empty() ? "��" : "�ƴϿ�") << std::endl;

    // ���� ù ��°�� ������ ���� ���
    std::cout << "deque ù ��° ����: " << myDeque.front() << std::endl;
    std::cout << "deque ������ ����: " << myDeque.back() << std::endl;

    return 0;
}