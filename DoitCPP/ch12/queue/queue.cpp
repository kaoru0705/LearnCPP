#include <iostream>
#include <queue>


int main() {
	std::queue<int> myQueue;

	// �����ϱ�
	myQueue.push(1);
	myQueue.push(2);
	myQueue.push(3);

	std::cout << "ť�� �� ��: " << myQueue.front() << std::endl;  // front
	std::cout << "ť�� �� ��: " << myQueue.back() << std::endl;   // back

	// ������
	myQueue.pop();

	std::cout << "pop �� �� ��: " << myQueue.front() << std::endl;  // pop �� front
	std::cout << "pop �� �� ��: " << myQueue.back() << std::endl;   // pop �� back

	// ������� Ȯ���ϱ�
	std::cout << "ť�� ��� �ֳ���? " << (myQueue.empty() ? "��" : "�ƴϿ�") << std::endl;

	// ũ�� ���ϱ�
	std::cout << "ť�� ũ��: " << myQueue.size() << std::endl;

	return 0;
}
