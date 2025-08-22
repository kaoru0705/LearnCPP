#include <iostream>
#include <vector>

// 같은 타입의 여러 객체를 저장할 수 있는 container, * operator overloading을 통해 마치 포인터처럼 사용할 수있는 iterator
int main() {
    std::vector<int> vec;

    for (int i = 0; i < 5; i++)
        vec.push_back(i);

    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;

    vec.begin();
    std::cout << vec[2] << std::endl;

    return 0;
}
