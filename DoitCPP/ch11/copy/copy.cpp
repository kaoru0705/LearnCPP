#include <iostream>
#include <vector>
#include <algorithm>

// 사람 정보를 담는 구조체
struct Person {
    std::string name;    // 이름
    int age;        // 나이
    float height;   // 키
    float weight;   // 몸무게
};

// 벡터에 저장된 사람 정보 출력 함수
void print_person_all(std::vector<Person>& vec) {
    for (std::vector<Person>::iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << "이름: " << it->name << "\t > " << "나이: " << it->age << ", " << "키: " << it->height << ", " << "몸무게: " << it->weight << std::endl;
    }
}

int main() {
    // Person 구조체 배열 생성
    Person p[5] {
        {"Brain", 24, 180, 70},
        {"Jessica", 22, 165, 55},
        {"James", 30, 170, 65},
        {"Tom", 12, 155, 46},
        {"Mary", 18, 172, 62}
    };

    // from_vector에 Person 배열 순서대로 넣기
    std::vector<Person> from_vector;
    from_vector.push_back(p[0]);
    from_vector.push_back(p[1]);
    from_vector.push_back(p[2]);
    from_vector.push_back(p[3]);
    from_vector.push_back(p[4]);

    // from_vector 출력
    std::cout << "-----from_vector-----" << std::endl;
    print_person_all(from_vector);
    std::cout << std::endl;

    // to_vector에 from_vector의 원소들 "깊은 복사" 수행
    std::vector<Person> to_vector;
    copy(from_vector.begin(), from_vector.end(), back_inserter(to_vector));

    // 복사 후, to_vector 출력
    std::cout << "-----to_vector-----" << std::endl;
    print_person_all(to_vector);
    std::cout << std::endl;

    // from_vector의 첫 번째 요소 수정
    from_vector[0].name = "Chris";
    from_vector[0].age = 5;
    from_vector[0].height = 110;
    from_vector[0].weight = 20;

    // 수정 후, from_vector 출력
    std::cout << "-----from_vector-----" << std::endl;
    print_person_all(from_vector);
    std::cout << std::endl;

    // to_vector 출력
    std::cout << "-----to_vector-----" << std::endl;
    print_person_all(to_vector);
    std::cout << std::endl;

    return 0;
}