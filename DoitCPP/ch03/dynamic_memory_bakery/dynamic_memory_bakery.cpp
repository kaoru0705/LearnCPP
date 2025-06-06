#include <iostream>
#include <string>

int main() {
    int customer_num = 0;

    std::cout << "오늘 방문 손님: ";
    std::cin >> customer_num;   // 손님 수 입력

    std::string* bread{ new std::string[customer_num] };  // 손님 수만큼 string 배열 생성

    // 입력받은 손님 수만큼 반복
    for (int i = 0; i < customer_num; i++) {
        bread[i] = "빵_" + std::to_string(i);       // ‘빵_숫자’ 형태로 배열에 저장 
    }

    std::cout << std::endl << "--생산된 빵--" << std::endl;
    for (int i = 0; i < customer_num; i++) {
        std::cout << *(bread + i) << std::endl;   // 생산된 빵 출력(포인터 연산 참고)
    }

    delete[] bread;   // string 배열 삭제

    return 0;
}
