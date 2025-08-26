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

    // std::stable_sort�� ����Ͽ� pair�� ù ��° ��ҿ� ���� ���� ����
    stable_sort(pairs.begin(), pairs.end(), compare_pairs);

    // ���ĵ� ��� ���
    for (std::vector<std::pair<int, std::string>>::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
        const std::pair<int, std::string>& pair = *it;
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
