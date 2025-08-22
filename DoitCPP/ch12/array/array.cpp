#include <iostream>
#include <array>

int main() {
    // 크기가 5인 std::array 생성
    std::array<int, 5> myArray;

    // 배열 초기화
    myArray = { 1, 2, 3, 4, 5 };

    // 배열 출력
    std::cout << "배열 출력: ";
    for (int i = 0; i < 5; i++) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    // 배열 크기 출력
    std::cout << "배열 크기: " << myArray.size() << std::endl;

    // 배열의 첫 번째 요소 출력
    std::cout << "첫 번째 요소: " << myArray.at(0) << std::endl;

    // 배열의 두 번째 요소 변경
    myArray[1] = 10;

    // 변경된 배열 출력
    std::cout << "변경된 배열: ";
    for (int i = 0; i < 5; i++) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
