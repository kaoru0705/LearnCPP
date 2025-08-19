#include <iostream>
#include <list>
#include <random>
#include <cmath>


const int forest_terrain_type = 0;
const int cyber_terrain_type = 1;
const int urban_terrain_type = 2;

const int monster_a_type = 0;
const int monster_b_type = 1;
const int monster_c_type = 2;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dis(0, 99);
std::uniform_int_distribution<int> select(0, 2);

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
    virtual void find_route(player& target_player) = 0;
    virtual bool attach_target(player* target_player) = 0;
    virtual void check_target(player& target_player) = 0;
    virtual void attack_special(player& target_player) = 0;
    virtual void set_location(int x, int y) { monster_body.set_location(x, y); };
    int get_monster_type() { return monster_type; };

protected:
    int calculate_distance(player& target_player);
    character* target_player = nullptr;
    int monster_type;

private:
    character monster_body;
};

int monster::calculate_distance(player& target_player) {
    return (int)sqrt(pow(target_player.get_location(true) - monster_body.get_location(true), 2) +
        pow(target_player.get_location(false) - monster_body.get_location(false), 2));
}

class terrain {
public:
    // �������� ġȯ ��Ģ �ؼ��ϴ� ���� ���� �Լ� �� ����
    virtual void allocate_monster(monster* mon) = 0;
    virtual void bost_monster(monster* mon) = 0;
    void set_start_location(int x, int y) { start_location_x = x; start_location_y = y; };
    void set_end_location(int x, int y) { end_location_x = x; end_location_y = y; };

protected:
    int terrain_type;
    void update_monster_list(monster* mon);

private:
    int start_location_x;
    int start_location_y;
    int end_location_x;
    int end_location_y;
    std::list<monster*> mon_list;

};

void terrain::update_monster_list(monster* mon) {
    mon_list.push_back(mon);
}

class forest_terrain : public terrain {
public:
    forest_terrain() {
        terrain_type = forest_terrain_type;
    };
    virtual void allocate_monster(monster* mon) override;
    virtual void bost_monster(monster* mon) override;
};

// �θ�� ������ �Լ� �ñ״�ó�� ��������� Ư���ִ� �ൿ ����
void forest_terrain::allocate_monster(monster* mon) {
    if (monster_a_type == mon->get_monster_type()) {
        update_monster_list(mon);
        std::cout << "Monster A�� ���� ��ġ �մϴ�." << std::endl;
    }
}

// �θ�� ������ �Լ� �ñ״�ó�� ��������� Ư���ִ� �ൿ ����
void forest_terrain::bost_monster(monster* mon) {
    if (monster_a_type == mon->get_monster_type()) {
        std::cout << "����A�� �������� ���� �� ���� ���ϴ�." << std::endl;
    }
}

class cyber_terrain : public terrain {
public:
    cyber_terrain() {
        terrain_type = cyber_terrain_type;
    };
    virtual void allocate_monster(monster* mon) override;
    virtual void bost_monster(monster* mon) override;
};

// �θ�� ������ �Լ� �ñ״�ó�� ��������� Ư���ִ� �ൿ ����
void cyber_terrain::allocate_monster(monster* mon) {
    update_monster_list(mon);
    std::cout << "��� ������ Monster�� ���̹� ������ ��ġ �մϴ�." << std::endl;
}

// �θ�� ������ �Լ� �ñ״�ó�� ��������� Ư���ִ� �ൿ ����
void cyber_terrain::bost_monster(monster* mon) {
    std::cout << "��� ���Ͱ� ���̹� ���������� �ӵ��� ���� ���ϴ�." << std::endl;
}

class urban_terrain : public terrain {
public:
    urban_terrain() {
        terrain_type = urban_terrain_type;
    };
    virtual void allocate_monster(monster* mon) override;
    virtual void bost_monster(monster* mon) override;
};

// �θ�� ������ �Լ� �ñ״�ó�� ��������� Ư���ִ� �ൿ ����
void urban_terrain::allocate_monster(monster* mon) {
    if (monster_a_type != mon->get_monster_type()) {
        update_monster_list(mon);
        std::cout << "Monster B, C�� ���ɿ� ��ġ �մϴ�." << std::endl;
    }
}

// �θ�� ������ �Լ� �ñ״�ó�� ��������� Ư���ִ� �ൿ ����
void urban_terrain::bost_monster(monster* mon) {
    if (monster_c_type == mon->get_monster_type()) {
        update_monster_list(mon);
        std::cout << "Monster C�� ���ɿ� ���� ���� ���ϴ�." << std::endl;
    }
}

//Monster factory
class monster_factory
{
public:
    static void create_monster(const int terrain_type, int count);
    static void destroy_monster();
    static void create_terrain();
    static void destroy_terrain();
    static monster* get_monster(int index);
    static int get_monster_count();
    static void initialize_monster();

private:
    static monster* create_monster(const int terrain_type, terrain* terrain_inst);
    static std::list<monster*> mon_list;
    static int mon_count;
    static terrain* terrain_inst[3];
};

std::list<monster*> monster_factory::mon_list = {};
int monster_factory::mon_count = 0;
terrain* monster_factory::terrain_inst[] = { nullptr, };

//���� A�� �߻� Ŭ���� Monster Ŭ�����κ��� ���
class monster_a : public monster {
public:
    monster_a() {
        monster_type = monster_a_type;
    };
    virtual void find_route(player& target_player) override;
    virtual bool attach_target(player* target_player) override;
    virtual void check_target(player& target_player) override;
    virtual void attack_special(player& target_player) override;
};

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
    monster_b() {
        monster_type = monster_b_type;
    };
    virtual void find_route(player& target_player) override;
    virtual bool attach_target(player* target_player) override;
    virtual void check_target(player& target_player) override;
    virtual void attack_special(player& target_player) override;
};

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
    monster_c() {
        monster_type = monster_c_type;
    };
    virtual void find_route(player& target_player) override;
    virtual bool attach_target(player* target_player) override;
    virtual void check_target(player& target_player) override;
    virtual void attack_special(player& target_player) override;
};

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
    create_monster(forest_terrain_type, 2);
    create_monster(cyber_terrain_type, 3);
    create_monster(urban_terrain_type, 1);
}

void monster_factory::create_terrain() {
    terrain_inst[0] = new forest_terrain();
    terrain_inst[1] = new cyber_terrain();
    terrain_inst[2] = new urban_terrain();

    for (auto object : terrain_inst) {
        object->set_start_location(dis(gen), dis(gen));
        object->set_end_location(dis(gen), dis(gen));
    }
}

void monster_factory::destroy_terrain() {
    for (auto inst : terrain_inst) {
        delete inst;
    }
}


monster* monster_factory::create_monster(const int terrain_type, terrain* terrain_inst) {
    monster* new_mon = nullptr;
    switch (terrain_type) {
    case forest_terrain_type:
        new_mon = new monster_a();
        break;
    case cyber_terrain_type:
        new_mon = new monster_b();
        break;
    case urban_terrain_type:
        new_mon = new monster_c();
        break;
    }

    // ������ ������� monster Ŭ������ ��ĳ���� �Ͽ� ������ �帧 ����
    terrain_inst->allocate_monster(new_mon);
    terrain_inst->bost_monster(new_mon);
    mon_list.push_back(new_mon);
    mon_count++;
    return new_mon;
}

void monster_factory::destroy_monster() {
    for (auto mon : mon_list) {
        delete mon;
    }
}

void monster_routine(monster* mon, player target_player) {
    mon->attach_target(&target_player);
    mon->find_route(target_player);
    mon->check_target(target_player);
}

void monster_factory::create_monster(const int terrain_type, int count) {
    monster* mon = nullptr;

    for (int i = 0; i < count; ++i) {
        mon = monster_factory::create_monster(terrain_type, terrain_inst[select(gen)]);
        mon->set_location(dis(gen), dis(gen));
    }
}

int main() {
    int mon_count, i;
    player target_player_dummy;

    target_player_dummy.set_location(dis(gen), dis(gen));
    monster_factory::create_terrain();
    monster_factory::initialize_monster();

    mon_count = monster_factory::get_monster_count();
    for (i = 0; i < mon_count; ++i) {
        std::cout << std::endl;
        monster_routine(monster_factory::get_monster(i), target_player_dummy);
    }

    monster_factory::destroy_monster();
    monster_factory::destroy_terrain();

    return 0;
}