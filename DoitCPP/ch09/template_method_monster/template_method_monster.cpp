#include <iostream>
#include <list>
#include <random>
#include <cmath>

const int forest_terrain = 0;
const int cyber_terrain = 1;
const int urban_terrain = 2;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dis(0, 99);

class character {
public:
    character() : hp{ 100 }, power{ 100 }, location_x{ 0 }, location_y{ 0 } {};
    int get_hp() { return hp; }
    int get_power() { return power; }
    int get_location(bool x) { return x ? location_x : location_y; }
    void set_location(int x, int y) { location_x = x; location_y = y; }

protected:
    int hp;
    int power;
    int location_x;
    int location_y;
};

//character Ŭ������ ��� ���� player Ŭ����
class player : public character {
public:
    player() {};
};

//Monster �������̽�
class monster
{
public:
    // ���ø� ������ ���� ���� ���� �Լ� ����
    virtual void find_route(player& target_player) = 0;
    virtual bool attach_target(player* target_player) = 0;
    virtual void check_target(player& target_player) = 0;
    virtual void attack_special(player& target_player) = 0;
    virtual void set_location(int x, int y) { monster_body.set_location(x, y); };
    virtual ~monster() {};

protected:
    int calculate_distance(player& target_player);
    character* target_player = nullptr;

private:
    character monster_body;
};

int monster::calculate_distance(player& target_player) {
    return (int)sqrt(pow(target_player.get_location(true) - monster_body.get_location(true), 2) +
        pow(target_player.get_location(false) - monster_body.get_location(false), 2));
}

//Monster factory
class monster_factory
{
public:
    static void create_monster(const int terrain_type, int count);
    static void destroy_monster();
    static monster* get_monster(int index);
    static int get_monster_count();
    static void initialize_monster();

private:
    static monster* create_monster(const int terrain_type);
    static std::list<monster*> mon_list;
    static int mon_count;
};

std::list<monster*> monster_factory::mon_list = {};
int monster_factory::mon_count = 0;

//���� A�� �߻� Ŭ���� Monster Ŭ�����κ��� ���
class monster_a : public monster {
public:
    // ���ø� ���� ������ ���� ���� ���� �Լ� �������̵�
    virtual void find_route(player& target_player) override;
    virtual bool attach_target(player* target_player) override;
    virtual void check_target(player& target_player) override;
    virtual void attack_special(player& target_player) override;
};

// ���� A�� Ưȭ�� ���� ����
void monster_a::attack_special(player& target_player) {
    std::cout << "���ޱ� ���� : ������ - 15 hp" << std::endl;
}

void monster_a::find_route(player& target_player) {
    std::cout << "Ÿ�� ã�� ���� - �ִ� �Ÿ� �켱" << std::endl;
}

bool monster_a::attach_target(player* target_player) {
    if (calculate_distance(*target_player) < 30) {
        this->target_player = target_player;
        std::cout << "�ڵ��� ���鼭 �÷��̾� �Ѿ� ����" << std::endl;
        return true;
    }

    return false;
}

void monster_a::check_target(player& target_player) {
    if (target_player.get_hp() < 40) {
        attack_special(target_player);
        return;
    }
}

//���� B�� �߻� Ŭ���� Monster Ŭ�����κ��� ���
class monster_b : public monster {
public:
    virtual void find_route(player& target_player) override;
    virtual bool attach_target(player* target_player) override;
    virtual void check_target(player& target_player) override;
    virtual void attack_special(player& target_player) override;
};

// ���� B�� Ưȭ�� ���� ����
void monster_b::attack_special(player& target_player) {
    std::cout << "���� ���� : ������ - 0 hp" << std::endl;
}

void monster_b::find_route(player& target_player) {
    std::cout << "Ÿ�� ã�� ���� - �ּ� �ð� �켱" << std::endl;
}

bool monster_b::attach_target(player* target_player) {
    if (calculate_distance(*target_player) > 30) {
        this->target_player = target_player;
        std::cout << "��ġ ������ ���ؼ� ã�� ����" << std::endl;
        return true;
    }

    return false;
}

void monster_b::check_target(player& target_player) {
    if (target_player.get_hp() < 10) {
        attack_special(target_player);
        return;
    }
}


//���� C�� �߻� Ŭ���� Monster Ŭ�����κ��� ���
class monster_c : public monster {
public:
    virtual void find_route(player& target_player) override;
    virtual bool attach_target(player* target_player) override;
    virtual void check_target(player& target_player) override;
    virtual void attack_special(player& target_player) override;
};

// ���� C�� Ưȭ�� ���� ����
void monster_c::attack_special(player& target_player) {
    std::cout << "���� ���� ���� : ������ - 100 hp" << std::endl;
}

void monster_c::find_route(player& target_player) {
    std::cout << "Ÿ�� ã�� ���� - Ÿ�� �ü��� ������ �ʵ���" << std::endl;
}

bool monster_c::attach_target(player* target_player) {
    this->target_player = target_player;
    std::cout << "���� ��� ������ ����" << std::endl;
    return true;
}

void monster_c::check_target(player& target_player) {
    attack_special(target_player);
}

int monster_factory::get_monster_count() {
    return mon_count;
}

monster* monster_factory::get_monster(int index) {
    monster* new_mon = nullptr;
    auto item = mon_list.begin();
    advance(item, index);
    new_mon = *item;

    return new_mon;
}

void monster_factory::initialize_monster() {
    create_monster(forest_terrain, 2);
    create_monster(cyber_terrain, 3);
    create_monster(urban_terrain, 1);
}

monster* monster_factory::create_monster(const int terrain_type) {
    monster* new_mon = nullptr;
    switch (terrain_type) {
    case forest_terrain:
        new_mon = new monster_a();
        break;
    case cyber_terrain:
        new_mon = new monster_b();
        break;
    case urban_terrain:
        new_mon = new monster_c();
        break;
    }

    mon_list.push_back(new_mon);
    mon_count++;
    return new_mon;
}

void monster_factory::destroy_monster() {
    for (auto mon : mon_list) {
        delete mon;
    }
}

void monster_factory::create_monster(const int terrain_type, int count) {
    monster* mon = nullptr;

    for (int i = 0; i < count; ++i) {
        mon = monster_factory::create_monster(terrain_type);
        mon->set_location(dis(gen), dis(gen));
    }
}

// ���� ���� �Լ��� �������� �帧�� ���� �ϴ� ���� �Լ�
void monster_routine(monster* mon, player target_player) {
    mon->attach_target(&target_player);
    mon->find_route(target_player);
    mon->check_target(target_player);
}

int main() {
    int mon_count, i;
    player target_player_dummy;

    target_player_dummy.set_location(dis(gen), dis(gen));
    monster_factory::initialize_monster();

    mon_count = monster_factory::get_monster_count();
    for (i = 0; i < mon_count; ++i) {
        std::cout << std::endl;
        // ���� ������ ��� ���� ��ü ���͸� ��ȸ �ϸ鼭 ������ �帧�� ����
        std::cout << std::endl;
        monster_routine(monster_factory::get_monster(i), target_player_dummy);
    }

    monster_factory::destroy_monster();

    return 0;
}