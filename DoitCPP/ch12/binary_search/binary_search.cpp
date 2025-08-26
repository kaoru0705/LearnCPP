#include <iostream>
#include <algorithm>
#include <vector>


int main() {
    // 정렬되지 않은 벡터
    std::vector<int> numbers { 8, 3, 1, 7, 4, 5, 9, 2, 6 };

    // 정렬 수행
    sort(numbers.begin(), numbers.end());

    // 사용자에게 숫자 입력 받기
    int target;
    std::cout << "컨테이너에서 검색하고 싶은 숫자를 입력해보세요: ";
    std::cin >> target;

    // 이진 탐색
    bool found = binary_search(numbers.begin(), numbers.end(), target);

    if (found) {
        std::cout << "찾았습니다." << std::endl;
    }
    else {
        std::cout << "저장되어 있지 않습니다." << std::endl;
    }

    return 0;
}
