#include <iostream>
#include <string>
#include <map>

int main() {
    std::multimap<std::string, int> scores;

    // 멀티 맵에 원소(키-값 쌍) 삽입
    scores.insert(std::make_pair("Bob", 85));
    scores.insert(std::make_pair("Jane", 90));
    scores.insert(std::make_pair("Tom", 70));
    scores.insert(std::make_pair("Bob", 100));  // 중복 키 허용
    scores.insert(std::make_pair("Dumb", 10));
    scores.insert(std::make_pair("Apk", 0));


    // 멀티 맵의 크기를 출력
    std::cout << "multimap 크기: " << scores.size() << std::endl;

    // 특정 키에 해당하는 원소의 개수 구하기
    int count = scores.count("Bob");
    std::cout << "저장되어 있는 Bob 점수의 갯수: " << count << std::endl;

    // 특정 키를 가진 원소의 범위 구하기
    auto range = scores.equal_range("Bob"); // equal_range의 second는 key보다 큰 첫 번째 원소를 가리키는 iterator. 즉, "Bob" 다음의 첫 원소 "Dumb"을 가리킨다.
    if (range.first != scores.end()) {
        std::cout << "Bob의 모든 점수: ";
        for (auto it{ range.first }; it != range.second; ++it) {
            std::cout << it->second << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Bob의 점수는 저장되어 있지 않음" << std::endl;
    }
    std::cout << std::endl;

    // 특정 키에 해당하는 모든 원소 삭제
    scores.erase("Bob");  //Bob 정보 제거

    // 멀티 맵의 크기 출력
    std::cout << "Bob 정보 제거 후, multimap 크기: " << scores.size() << std::endl << std::endl;

    // 멀티 맵을 순회하며 모든 키와 값 출력
    std::cout << "---multimap 모든 원소 출력---" << std::endl;
    for (const auto& pair : scores) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}