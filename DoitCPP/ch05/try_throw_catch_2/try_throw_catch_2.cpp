#include <iostream>


int main() {
    try {
        int input;
        std::cout << "정수 중 하나를 입력해보세요 : ";
        std::cin >> input;

        // 입력받은 숫자가 양수이면
        if (input > 0) {
            std::cout << "throw 1" << std::endl;
            throw 1;   // 예외 1 발생(정수 형식 예외)
        }

        // 입력받은 숫자가 음수이면
        if (input < 0) {
            std::cout << "throw -1.0f" << std::endl;
            throw - 1.0f;   // 예외 1.0f 발생(부동소수점 형식 예외)
        }

        // 입력받은 숫자가 0이면
        if (input == 0) {
            std::cout << "throw Z" << std::endl;
            throw 'Z';   // 예외 Z 발생 (문자 형식 예외)
        }
    }
    catch (int a) {   // 정수 형식 예외 받기
        std::cout << "catch " << a << std::endl;
    }
    catch (...) {   // 처리되지 않은 나머지 예외 모두 받기
        std::cout << "catch all" << std::endl;
    }

    return 0;
}
