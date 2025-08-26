#include <iostream>
#include <algorithm>
#include <vector>


// ������ ���Ҹ� ������� ���
template <typename T>
void print_vector_all(std::vector<T>& vec) {
    for (typename std::vector<T>::iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec { 7, 6, 3, 5, 4, 1, 2, 0, 8 };

    // ������ ���Ҹ� ������������ ����
    sort(vec.begin(), vec.end());
    print_vector_all(vec);

    return 0;
}
