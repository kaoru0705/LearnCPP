#include <iostream>
#include <list>

class character {
public:
    character() : hp{ 100 }, power{ 100 } {};

protected:
    int hp;
    int power;
};

//character Ŭ������ ��� ���� player Ŭ����
class player : public character {
public:
    player() {};
};

//�߻� Ŭ���� Monster
class monster {
public:
    monster();             // ������
    virtual ~monster();    // �Ҹ���
    virtual void find_route() = 0;                            // ���� ���� �Լ�
    virtual void attack_special(player target_player) = 0;    // ���� ���� �Լ�
};

monster::monster() {
    std::cout << "Monster �θ� Ŭ���� ������" << std::endl;
}

monster::~monster() {
    std::cout << "Monster �θ� Ŭ���� �Ҹ���" << std::endl;
}

//���� A�� �߻� Ŭ���� Monster Ŭ�����κ��� ���
class monster_a : public monster {
public:
    virtual void attack_special(player target_player) override;
    virtual void find_route() override;   // ���� ���� �Լ� �������̵� ����
};

void monster_a::attack_special(player target_player) {
    std::cout << "���ޱ� ���� : ������ - 15 hp" << std::endl;
}

// �߻� Ŭ������ ���� ���� �Լ� ����
void monster_a::find_route() {
    std::cout << "���� �켱 Ž��(DFS)" << std::endl;
}

//���� B�� �߻� Ŭ���� Monster Ŭ�����κ��� ���
class monster_b : public monster {
public:
    virtual void attack_special(player target_player) override;
    virtual void find_route() override;
};

void monster_b::attack_special(player target_player) {
    std::cout << "���� ���� : ������ - 0 hp" << std::endl;
}


void monster_b::find_route() {
    std::cout << "�ʺ� �켱 Ž��(BFS)" << std::endl;
}


//���� C�� �߻� Ŭ���� Monster Ŭ�����κ��� ���
class monster_c : public monster {
public:
    virtual void attack_special(player target_player) override;
    virtual void find_route() override;
};

void monster_c::attack_special(player target_player) {
    std::cout << "���� ���� ���� : ������ - 100 hp" << std::endl;
}


void monster_c::find_route() {
    std::cout << "���ͽ�Ʈ�� �ִ� ��� �˰���" << std::endl;
}

// ���� �Լ�
void monster_routine(monster* mon, player target_player) {
    mon->find_route();
    mon->attack_special(target_player);
}

int main() {
    std::list<monster*> mon_list;
    monster_a first_mon;
    monster_b second_mon;
    monster_c third_mon;
    player target_player;

    mon_list.push_back(&first_mon);
    mon_list.push_back(&second_mon);
    mon_list.push_back(&third_mon);

    for (auto mon : mon_list) {
        monster_routine(mon, target_player);
    }

    return 0;
}