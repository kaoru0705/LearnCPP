#include <iostream>
#include <string>

class character {
public:
    character() : hp(100), power(100), location{ 0,0 }, level(1) {
    };
    void move(int x, int y) {};
    void move(int x[], int y[], int spot_count) {}
    void get_damage(int _damage) {};
    int get_hp() { return hp; };
    int get_level() { return level; };

protected:
    int hp;
    int power;
    int location[2];
    int level;
};

class player : public character {
public:
    player() {};
};

//�⺻ Monster Ŭ����
class monster {
public:
    void attack(player target_player) {};
    virtual void attack_special(player target_player);
};

void monster::attack_special(player target_player) {
    std::cout << "�⺻ ���� : ������ - 10 hp" << std::endl;
}

//���� C�� �⺻ Monster Ŭ�����κ��� ���
class monster_c : public monster, public character {
public:
    //��ӹ��� �Լ� �������̵�
    void attack_special(player target_player) override;
    monster_c operator+(monster_c& operand);
    void set_level(int level_value) { level = level_value; };
    void set_hp(int hp_value) { hp = hp_value; };
};

// ���� ������ �����ε� ����
monster_c monster_c::operator+(monster_c& operand) {
    monster_c result_monster;
    result_monster.set_level(level + operand.get_level());
    return result_monster;
}

void monster_c::attack_special(player target_player) {
    std::cout << "���� ���� ���� : ������ - 100 hp" << std::endl;
}

int main() {

    monster_c monster_c_obj1, monster_c_obj2;
    monster_c_obj2.set_level(2);
    monster_c new_monster_c_obj = monster_c_obj1 + monster_c_obj2;

    std::cout << "��ü�� ����C #1 Level[" << monster_c_obj1.get_level()
        << "], ����C #2 Level[" << monster_c_obj2.get_level()
        << "]" << std::endl;

    std::cout << "��ü �� ����C Level[" << new_monster_c_obj.get_level()
        << "]" << std::endl;

    return 0;
}