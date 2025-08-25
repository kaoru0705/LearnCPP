#include <iostream>
#include <queue>


int main() {
	std::queue<int> myQueue;

	// 삽입하기
	myQueue.push(1);
	myQueue.push(2);
	myQueue.push(3);

	std::cout << "큐의 맨 앞: " << myQueue.front() << std::endl;  // front
	std::cout << "큐의 맨 뒤: " << myQueue.back() << std::endl;   // back

	// 꺼내기
	myQueue.pop();

	std::cout << "pop 후 맨 앞: " << myQueue.front() << std::endl;  // pop 후 front
	std::cout << "pop 후 맨 뒤: " << myQueue.back() << std::endl;   // pop 후 back

	// 비었는지 확인하기
	std::cout << "큐가 비어 있나요? " << (myQueue.empty() ? "네" : "아니오") << std::endl;

	// 크기 구하기
	std::cout << "큐의 크기: " << myQueue.size() << std::endl;

	return 0;
}
