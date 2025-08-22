#include <iostream>
#include <vector>

// ������ ��� ���Ҹ� ����ϴ� �Լ�
template <typename T>
void print_vector_all(std::vector<T>& vec) {
    std::cout << "���� �� ���� ���� : " << vec.size() << std::endl;

    // ������ ��� ���� ���
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

    std::cout << "����" << std::endl;
    print_vector_all(vec);

    // ���Ϳ� ���� ����
    vec.insert(vec.begin() + 3, 25);    // vec[3] �տ� 25 �߰�
    std::cout << "insert ���" << std::endl;
    print_vector_all(vec);

    // ���Ϳ��� ���� ����
    vec.erase(vec.begin() + 3);         // vec[3] ����
    std::cout << "erase ���" << std::endl;
    print_vector_all(vec);

    return 0;
}