#include <iostream>
#include <random>

class character {
public:
    character() {
        std::cout << "character Ŭ���� ������" << std::endl;
    };
    ~character() {
        std::cout << "charactor Ŭ���� �Ҹ���" << std::endl;
    }
};

class monster {
public:
    monster() {
        std::cout << "monster Ŭ���� ������" << std::endl;
    };
    ~monster() {
        std::cout << "monster Ŭ���� �Ҹ���" << std::endl;
    };
};

//���� A�� �⺻ Monster Ŭ�����κ��� ���
class monster_a : public monster, character {
public:
    monster_a() {
        std::cout << "monster_a Ŭ���� ������" << std::endl;
    };

    ~monster_a() {
        std::cout << "monster_a Ŭ���� �Ҹ���" << std::endl;
    }
};

int main() {
    monster_a forest_monster;
    return 0;
}