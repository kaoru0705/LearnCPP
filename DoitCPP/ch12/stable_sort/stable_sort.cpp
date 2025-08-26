#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

bool compare_pairs(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
    return a.first < b.first;
}

int main() {
    std::vector<std::pair<int, std::string>> pairs {
      {5, "apple"},
      {2, "orange"},
      {5, "banana"},
      {3, "grape"}
    };

    // std::stable_sort를 사용하여 pair를 첫 번째 요소에 따라 안정 정렬
    stable_sort(pairs.begin(), pairs.end(), compare_pairs);

    // 정렬된 결과 출력
    for (std::vector<std::pair<int, std::string>>::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
        const std::pair<int, std::string>& pair = *it;
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
