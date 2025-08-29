#include <iostream>
#include <compare>

struct _tag {
    int number;
    char alphabet;
    auto operator<=>(const _tag& object) const {
        return number <=> object.number;
    }
};

using DATA = struct _tag;

DATA data_element[5] { {4, 'a'}, {1, 'c'}, {8, 'b'}, {2, 'z'}, {4, 'd'} };

int main() {

    std::cout << std::boolalpha << "0��°�� 3��° ���Һ��� Ů�ϴ� : ";
    std::cout << ((data_element[0] <=> data_element[3]) > 0) << std::endl;

    std::cout << "1��°�� 2��° ���Һ��� Ů�ϴ� : ";
    std::cout << (data_element[1] > data_element[2]) << std::endl;

    return 0;
}