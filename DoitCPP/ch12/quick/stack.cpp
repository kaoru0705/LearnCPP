#include <iostream>
#include <stack>

int main() {
    std::stack<int> myStack;

    // ���ÿ� ������ �߰�
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // ������ �� ���� �� Ȯ��
    std::cout << "�� �� ���: " << myStack.top() << std::endl;

    // ���ÿ��� ������ ����(�� ���� ������ ������)
    myStack.pop();
    std::cout << "�� �� ��� ���� ��, ���ο� �� �� ���: " << myStack.top()
        << std::endl;

    // ������ ũ��(������ ����) Ȯ��
    std::cout << "���� ũ��: " << myStack.size() << std::endl;

    // ������ ������� Ȯ��
    if (myStack.empty()) {
        std::cout << "������ ������ϴ�." << std::endl;
    }
    else {
        std::cout << "������ ��� ���� �ʽ��ϴ�." << std::endl;
    }

    return 0;
}