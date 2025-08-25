#include <iostream>
#include <stack>

int main() {
    std::stack<int> myStack;

    // 스택에 데이터 추가
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // 스택의 맨 위쪽 값 확인
    std::cout << "맨 위 요소: " << myStack.top() << std::endl;

    // 스택에서 데이터 제거(맨 위쪽 데이터 꺼내기)
    myStack.pop();
    std::cout << "맨 위 요소 제거 후, 새로운 맨 위 요소: " << myStack.top()
        << std::endl;

    // 스택의 크기(데이터 개수) 확인
    std::cout << "스택 크기: " << myStack.size() << std::endl;

    // 스택이 비었는지 확인
    if (myStack.empty()) {
        std::cout << "스택이 비었습니다." << std::endl;
    }
    else {
        std::cout << "스택은 비어 있지 않습니다." << std::endl;
    }

    return 0;
}