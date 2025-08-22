#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;

    for (int i = 0; i < 3; i++)
        vec.push_back(i);

    for (std::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
        std::cout << *it << std::endl;

    return 0;
}
