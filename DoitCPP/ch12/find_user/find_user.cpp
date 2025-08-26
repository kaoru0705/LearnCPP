#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class my_class {
public:
    int value;
    std::string name;

    // == ������ �����ε�
    bool operator==(const my_class& other) const {
        return value == other.value && name == other.name;
    }
};

int main() {
    std::vector<my_class> objects { {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"} };

    // my_class Ŭ������ ��� ��� �������� ���� ��ü�� ã��
    std::vector<my_class>::iterator it{ find(objects.begin(), objects.end(), my_class{ 3, "three" }) };

    if (it != objects.end()) {
        std::cout << "ã�� ��ġ: " << distance(objects.begin(), it) << std::endl;
    }
    else {
        std::cout << "ã�� �� ����" << std::endl;
    }

    std::cout << objects[0].name << std::endl;

    return 0;
}
