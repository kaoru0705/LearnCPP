#include <iostream>
#include <vector>

// ���� Ÿ���� ���� ��ü�� ������ �� �ִ� container, * operator overloading�� ���� ��ġ ������ó�� ����� ���ִ� iterator
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
