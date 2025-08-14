#include <iostream>

// ĳ������ Ư���� ������ �ִ� ĳ���� Ŭ����
class character {
public:
    character() : hp{ 100 }, power{ 100 } {};
    int get_hp() { return hp; };
    int get_power() { return power; };
protected:
    int hp;
    int power;
};

//character Ŭ������ ��� ���� player Ŭ����
class player {
public:
    player() {};
private:
    character main_body;
};

//Monster Ŭ����
class monster {
public:
    monster() {};
    void get_damage(int _damage) {};
    virtual void attack(player target_player) {
        std::cout << " ���� : ������ - 10 hp" << std::endl;
    };
};

class monster_2nd_gen : public monster {
public:
    virtual void attack(player target_player) override {
        std::cout << " ���ο� ���� : ������ - 30 hp" << std::endl;
    };
};

//���� A�� monster, charactoer Ŭ������ ������������ ����
class monster_a {
public:
    void attack(player target_player) {
        main_role.attack(target_player);
    };
private:
    character main_body;
    monster main_role;
};

//���� B�� monster, charactoer Ŭ������ ��׸����̼����� ����
class monster_b {
public:
    // ���۷��� ��� ������ �ʱ�ȭ ����Ʈ�� �ʱ�ȭ ����
    monster_b(character& ref_character, monster& ref_monster)
        : main_body{ ref_character }, main_role{ ref_monster } {
    };
    void attack(player target_player) {
        main_role.attack(target_player);
    };
private:
    character& main_body;
    monster& main_role;
};

int main() {
    // ��׸����̼ǿ� ������ ��ü ���� - ���� Ŭ������ ���� �ֱ� �ٸ�
    character chararater_obj;
    monster monster_obj;
    monster_2nd_gen monster_new_obj;

    player player_1;

    // ���������� ��ü�� �����ֱⰡ ���� ��ü���� ���� ����
    monster_a forest_monster;

    // ��׸����̼��� ���ؼ� �ܺ��� ��ü�� ������ ����
    monster_b tutorial_monster{ chararater_obj, monster_obj };
    monster_b urban_monster{ chararater_obj, monster_new_obj };
    std::cout << "���� A ����" << std::endl;
    tutorial_monster.attack(player_1);

    std::cout << std::endl << "���� B ����" << std::endl;
    forest_monster.attack(player_1);
    urban_monster.attack(player_1);

    return 0;
}
