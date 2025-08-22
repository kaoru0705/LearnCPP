#include <iostream>
#include <vector>

// 벡터의 모든 원소를 출력하는 함수
template <typename T>
void print_vector_all(std::vector<T>& vec) {
    std::cout << "벡터 내 원소 개수 : " << vec.size() << std::endl;

    // 벡터의 모든 원소 출력
    for (typename std::vector<T>::iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << "---------------------" << std::endl;
}

int main() {
    std::vector<int> vec;
    vec.push_back(0);
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    std::cout << "원본" << std::endl;
    print_vector_all(vec);

    // 벡터에 원소 삽입
    vec.insert(vec.begin() + 3, 25);    // vec[3] 앞에 25 추가
    std::cout << "insert 결과" << std::endl;
    print_vector_all(vec);

    // 벡터에서 원소 삭제
    vec.erase(vec.begin() + 3);         // vec[3] 제거
    std::cout << "erase 결과" << std::endl;
    print_vector_all(vec);

    return 0;
}