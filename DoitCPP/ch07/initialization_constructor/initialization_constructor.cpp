#include <iostream>
#include <random>

class character {
public:
    character() {
        std::cout << "character Ŭ���� ������" << std::endl;
    };
};

class monster {
public:
    monster() {
        std::cout << "monster Ŭ���� ������" << std::endl;
    };
};

//���� A�� �⺻ Monster Ŭ�����κ��� ���
class monster_a : public monster, character {
public:
    monster_a() : monster_a(10, 10) {
        std::cout << "monster_a Ŭ���� ������" << std::endl;
    };

    monster_a(int x, int y) : location{ x, y } {
        std::cout << "monster_a Ŭ���� ������ (�Ű����� �߰�)" << std::endl;
    };

    void show_location() {
        std::cout << "��ġ(" << location[0] << " , " << location[1] << ")" << std::endl;
    };

private:
    int location[2];
};

int main() {
    monster_a forest_monster;
    forest_monster.show_location();

    return 0;
}