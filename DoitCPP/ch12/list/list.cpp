#include <iostream>
#include <list> 

int main() {
    std::list<int> myList;

    // ����Ʈ ���ʿ� �� �߰�
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);

    // ����Ʈ ���ʿ� �� �߰�
    myList.push_front(1);
    myList.push_front(0);

    // ����Ʈ ���
    std::cout << "����Ʈ ���: ";
    for (const int& value : myList) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    myList.pop_front();   // ù ��° ��� ����
    myList.pop_back();  // ������ ��� ����

    // ���� �� ����Ʈ ���
    std::cout << "���� �� ����Ʈ ���: ";
    for (const int& value : myList) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // ����Ʈ ũ�� Ȯ��
    std::cout << "����Ʈ ũ��: " << myList.size() << std::endl;

    // ����Ʈ�� ������� Ȯ��
    std::cout << "����Ʈ�� ����°�? " << (myList.empty() ? "��" : "�ƴϿ�") << std::endl;

    return 0;
}