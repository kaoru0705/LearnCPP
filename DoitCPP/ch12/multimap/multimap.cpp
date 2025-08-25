#include <iostream>
#include <string>
#include <map>

int main() {
    std::multimap<std::string, int> scores;

    // ��Ƽ �ʿ� ����(Ű-�� ��) ����
    scores.insert(std::make_pair("Bob", 85));
    scores.insert(std::make_pair("Jane", 90));
    scores.insert(std::make_pair("Tom", 70));
    scores.insert(std::make_pair("Bob", 100));  // �ߺ� Ű ���
    scores.insert(std::make_pair("Dumb", 10));
    scores.insert(std::make_pair("Apk", 0));


    // ��Ƽ ���� ũ�⸦ ���
    std::cout << "multimap ũ��: " << scores.size() << std::endl;

    // Ư�� Ű�� �ش��ϴ� ������ ���� ���ϱ�
    int count = scores.count("Bob");
    std::cout << "����Ǿ� �ִ� Bob ������ ����: " << count << std::endl;

    // Ư�� Ű�� ���� ������ ���� ���ϱ�
    auto range = scores.equal_range("Bob"); // equal_range�� second�� key���� ū ù ��° ���Ҹ� ����Ű�� iterator. ��, "Bob" ������ ù ���� "Dumb"�� ����Ų��.
    if (range.first != scores.end()) {
        std::cout << "Bob�� ��� ����: ";
        for (auto it{ range.first }; it != range.second; ++it) {
            std::cout << it->second << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Bob�� ������ ����Ǿ� ���� ����" << std::endl;
    }
    std::cout << std::endl;

    // Ư�� Ű�� �ش��ϴ� ��� ���� ����
    scores.erase("Bob");  //Bob ���� ����

    // ��Ƽ ���� ũ�� ���
    std::cout << "Bob ���� ���� ��, multimap ũ��: " << scores.size() << std::endl << std::endl;

    // ��Ƽ ���� ��ȸ�ϸ� ��� Ű�� �� ���
    std::cout << "---multimap ��� ���� ���---" << std::endl;
    for (const auto& pair : scores) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}