#include <iostream>
#include <set>


int main() {
    std::set<int> mySet;

    // �� ����
    mySet.insert(5);
    mySet.insert(2);
    mySet.insert(8);

    // �� 5�� ��Ʈ�� �ִ��� Ȯ��
    if (mySet.find(5) != mySet.end()) {
        std::cout << "5�� set�� ����Ǿ� ����" << std::endl;
    }

    // ��Ʈ�� ��ȸ�ϸ� �� ���
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // ��Ʈ�� ũ�� ���
    int size = mySet.size();
    std::cout << "set ũ��: " << size << std::endl;

    return 0;
}