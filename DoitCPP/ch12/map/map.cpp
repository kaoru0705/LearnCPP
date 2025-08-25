#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<std::string, int> scores;
    
    // Ű-�� �� ����
    scores.insert(std::make_pair("Bob", 85));
    scores.insert(std::make_pair("Jane", 90));
    scores.insert(std::make_pair("Tom", 70));

    // �� ũ�� ���
    std::cout << "map ũ��: " << scores.size() << std::endl;

    // Ư�� Ű�� �ش��ϴ� �� �˻�
    auto it = scores.find("Bob");
    if (it != scores.end()) {
        std::cout << "Bob�� ���� �˻� ���: " << it->second << std::endl;
    }
    else {
        std::cout << "Bob�� ������ ����Ǿ� ���� ����" << std::endl;
    }
    std::cout << std::endl;

    // Ư�� Ű�� �ش��ϴ� Ű-�� ����
    scores.erase("Bob");  //Bob ���� ����

    // �� ũ�� ���
    std::cout << "Bob ���� ���� ��, map ũ��: " << scores.size() << std::endl << std::endl;

    // ���� ��ȸ�ϸ� ��� Ű�� �� ���
    std::cout << "---map ��� ���� ���---" << std::endl;
    for (const auto& pair : scores) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}