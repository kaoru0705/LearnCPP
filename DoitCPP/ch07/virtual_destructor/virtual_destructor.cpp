#include <iostream>
#include <random>

class monster {
public:
    monster() {
        std::cout << "monster Ŭ���� ������" << std::endl;
    };
    virtual ~monster() {
        std::cout << "monster Ŭ���� �Ҹ���" << std::endl;
    };
};

//���� A�� �⺻ Monster Ŭ�����κ��� ���
class monster_a : public monster {
public:
    monster_a() {
        std::cout << "monster_a Ŭ���� ������" << std::endl;
    };
    virtual ~monster_a() {
        std::cout << "monster_a Ŭ���� �Ҹ���" << std::endl;
    }
};

int main() {
    monster* forest_monster{ new monster_a{} };
    delete forest_monster;
    return 0;
}