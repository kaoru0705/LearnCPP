#include <iostream>
#include <set>

int main() {
    std::multiset<int> myMultiset;

    // �� ����
    myMultiset.insert(5);
    myMultiset.insert(2);
    myMultiset.insert(5);   // �ߺ��� ���� �����

    // Ư�� ���� ���� ���
    int count = myMultiset.count(5);
    std::cout << "����Ǿ� �ִ� 5�� ����: " << count << std::endl;

    // ��Ƽ ��Ʈ�� ��ȸ�ϸ� �� ���
    for (auto it = myMultiset.begin(); it != myMultiset.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // ��Ƽ ��Ʈ�� ũ�� ���
    int size = myMultiset.size();
    std::cout << "multiset ũ��: " << size << std::endl;

    return 0;
}