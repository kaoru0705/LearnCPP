#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

struct Person {
    std::string name;   // �̸�
    int age;       // ����
    float height;	 // Ű
    float weight;	 // ������
};

void print_preson_all(std::vector<Person>& vec) {
    for (std::vector<Person>::iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << "�̸�: " << it->name << "\t > " << "����: " << it->age << ", " << "Ű: " << it->height << ", " << "������: " << it->weight << std::endl;
    }
}

// Person ����ü�� ���� ��(ù ��° ������ ���̰� ������ true)
bool compare(const Person& lhs, const Person& rhs) {
    return lhs.age < rhs.age;
}

int main() {
    Person p[5] {
        {"Brain", 24, 180, 70},
        {"Jessica", 22, 165, 55},
        {"James", 30, 170, 65},
        {"Tom", 12, 155, 46},
        {"Mary", 18, 172, 62}
    };

    std::vector<Person> vec;
    vec.push_back(p[0]);
    vec.push_back(p[1]);
    vec.push_back(p[2]);
    vec.push_back(p[3]);
    vec.push_back(p[4]);

    std::cout << "-----���� ��-----" << std::endl;
    print_preson_all(vec);
    std::cout << std::endl;

    // ����� ���� �������� ����
    sort(vec.begin(), vec.end(), compare);

    std::cout << "-----���� ��-----" << std::endl;
    print_preson_all(vec);

    return 0;
}
