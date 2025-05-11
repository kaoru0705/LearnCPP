#include <iostream>


void func_throw() {
    std::cout << "func_throw()" << std::endl;
    std::cout << "throw -1" << std::endl;
    throw - 1;   // 정수 형식 예외 던지기
    std::cout << "after throw -1" << std::endl;
}

int main() {
    try {
        func_throw();
    }
    catch (int exec) {   // 정수 형식 예외 받기
        std::cout << "catch " << exec << std::endl;
    }

    return 0;
}
