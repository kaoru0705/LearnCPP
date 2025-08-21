#include <iostream>
#include <vector>
#include <algorithm>

// ��� ������ ��� ����ü
struct Person {
    std::string name;    // �̸�
    int age;        // ����
    float height;   // Ű
    float weight;   // ������
};

// ���Ϳ� ����� ��� ���� ��� �Լ�
void print_person_all(std::vector<Person>& vec) {
    for (std::vector<Person>::iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << "�̸�: " << it->name << "\t > " << "����: " << it->age << ", " << "Ű: " << it->height << ", " << "������: " << it->weight << std::endl;
    }
}

int main() {
    // Person ����ü �迭 ����
    Person p[5] {
        {"Brain", 24, 180, 70},
        {"Jessica", 22, 165, 55},
        {"James", 30, 170, 65},
        {"Tom", 12, 155, 46},
        {"Mary", 18, 172, 62}
    };

    // from_vector�� Person �迭 ������� �ֱ�
    std::vector<Person> from_vector;
    from_vector.push_back(p[0]);
    from_vector.push_back(p[1]);
    from_vector.push_back(p[2]);
    from_vector.push_back(p[3]);
    from_vector.push_back(p[4]);

    // from_vector ���
    std::cout << "-----from_vector-----" << std::endl;
    print_person_all(from_vector);
    std::cout << std::endl;

    // to_vector�� from_vector�� ���ҵ� "���� ����" ����
    std::vector<Person> to_vector;
    copy(from_vector.begin(), from_vector.end(), back_inserter(to_vector));

    // ���� ��, to_vector ���
    std::cout << "-----to_vector-----" << std::endl;
    print_person_all(to_vector);
    std::cout << std::endl;

    // from_vector�� ù ��° ��� ����
    from_vector[0].name = "Chris";
    from_vector[0].age = 5;
    from_vector[0].height = 110;
    from_vector[0].weight = 20;

    // ���� ��, from_vector ���
    std::cout << "-----from_vector-----" << std::endl;
    print_person_all(from_vector);
    std::cout << std::endl;

    // to_vector ���
    std::cout << "-----to_vector-----" << std::endl;
    print_person_all(to_vector);
    std::cout << std::endl;

    return 0;
}