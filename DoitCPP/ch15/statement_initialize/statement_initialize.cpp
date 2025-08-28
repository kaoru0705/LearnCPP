#include <iostream>
#include <array>
#include <algorithm>

constexpr int even{0};
constexpr int odd {1};

int main() {
    std::array<int, 5> data_array{ 47, 23, 58, 10, 36 };

    // if 문에 초기화 구문 사용
    if (auto element = data_array[3]; element > 20) {
        std::cout << "네 번째 요소값은 20보다 큽니다." << std::endl;
    }
    else {
        std::cout << "네 번째 요소값은 20보다 작거나 같습니다." << std::endl;
    }

    // switch 문에 초기화 구문 사용
    switch (auto element = data_array[4] % 2; element) {
    case odd:
        std::cout << "다섯 번째 요소값은 홀수 입니다." << std::endl;
        break;
    case even:
        std::cout << "다섯 번째 요소값은 짝수 입니다." << std::endl;
        break;
    }

    // 범위 기반 for 문에 초기화 구문 사용
    for (std::sort(data_array.begin(), data_array.end()); auto && element : data_array) {
        std::cout << element << ", ";
    }
    std::cout << std::endl;

    return 0;
}