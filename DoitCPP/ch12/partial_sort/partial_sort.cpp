#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers = { 7, 2, 5, 1, 8, 9, 3, 6, 4 };

    // numbers 벡터에서 가장 작은 3개의 요소만 정렬
    partial_sort(numbers.begin(), numbers.begin() + 3, numbers.end());

    // 정렬된 결과 출력
    for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}