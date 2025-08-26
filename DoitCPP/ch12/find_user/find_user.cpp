#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class my_class {
public:
    int value;
    std::string name;

    // == 연산자 오버로딩
    bool operator==(const my_class& other) const {
        return value == other.value && name == other.name;
    }
};

int main() {
    std::vector<my_class> objects { {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"} };

    // my_class 클래스의 모든 멤버 변수까지 같은 객체를 찾음
    std::vector<my_class>::iterator it{ find(objects.begin(), objects.end(), my_class{ 3, "three" }) };

    if (it != objects.end()) {
        std::cout << "찾은 위치: " << distance(objects.begin(), it) << std::endl;
    }
    else {
        std::cout << "찾을 수 없음" << std::endl;
    }

    std::cout << objects[0].name << std::endl;

    return 0;
}
