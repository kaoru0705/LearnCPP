/* https://en.cppreference.com/w/cpp/iterator/advance.html 
해당 인덱스까지 넘긴 주소를 반환 */
#include <iostream>
#include <list>

const int forest_terrain = 0;
const int cyber_terrain = 1;
const int urban_terrain = 2;

class character {
public:
    character() : hp{100}, power{100} {};

protected:
    int hp;
    int power;
};

//character 클래스를 상속 받은 player 클래스
class player : public character {
public:
    player() {};
};

//Monster 인터페이스
class monster
{
public:
    virtual void find_route() = 0;
    virtual void attack_special(player target_player) = 0;
    virtual ~monster() {};

    static monster* create_monster(const int terrain_type);
    static void destroy_monster();
    static monster* get_monster(const int terrain_type, int index);
    static int get_monster_count(const int terrain_type);

private:
    static std::list<monster*> mon_a_list;
    static std::list<monster*> mon_b_list;
    static std::list<monster*> mon_c_list;
    static int mon_a_count;
    static int mon_b_count;
    static int mon_c_count;
};

std::list<monster*> monster::mon_a_list = {};
std::list<monster*> monster::mon_b_list = {};
std::list<monster*> monster::mon_c_list = {};

int monster::mon_a_count = 0;
int monster::mon_b_count = 0;
int monster::mon_c_count = 0;

//몬스터 A는 추상 클래스 Monster 클래스로부터 상속
class monster_a : public monster {
public:
    virtual void attack_special(player target_player) override;
    virtual void find_route() override;
};

void monster_a::attack_special(player target_player) {
    std::cout << "인텡글 공격 : 데미지 - 15 hp" << std::endl;
}

void monster_a::find_route() {
    std::cout << "깊이 우선 탐색(DFS)" << std::endl;
}

//몬스터 B는 추상 클래스 Monster 클래스로부터 상속
class monster_b : public monster {
public:
    virtual void attack_special(player target_player) override;
    virtual void find_route() override;
};

void monster_b::attack_special(player target_player) {
    std::cout << "가상 공격 : 데미지 - 0 hp" << std::endl;
}


void monster_b::find_route() {
    std::cout << "너비 우선 탐색(BFS)" << std::endl;
}


//몬스터 C는 추상 클래스 Monster 클래스로부터 상속
class monster_c : public monster {
public:
    virtual void attack_special(player target_player) override;
    virtual void find_route() override;
};

void monster_c::attack_special(player target_player) {
    std::cout << "강력 뇌전 공격 : 데미지 - 100 hp" << std::endl;
}


void monster_c::find_route() {
    std::cout << "다익스트라 최단 경로 알고리즘" << std::endl;
}

int monster::get_monster_count(const int terrain_type) {
    switch (terrain_type) {
    case forest_terrain:
        return mon_a_count;
    case cyber_terrain:
        return mon_b_count;
    case urban_terrain:
        return mon_c_count;
    }

    return 0;
}

monster* monster::get_monster(const int terrain_type, int index) {
    monster* new_mon{ nullptr };
    switch (terrain_type) {
    case forest_terrain: {
        auto item{ mon_a_list.begin() };
        std::advance(item, index);
        new_mon = *item;
    }
                       break;
    case cyber_terrain: {
        auto item{ mon_b_list.begin() };
        std::advance(item, index);
        new_mon = *item;
    }
                      break;
    case urban_terrain: {
        auto item{ mon_c_list.begin() };
        std::advance(item, index);
        new_mon = *item;
    }
                      break;
    }

    return new_mon;
}

monster* monster::create_monster(const int terrain_type) {
    monster* new_mon{ nullptr };
    switch (terrain_type) {
    case forest_terrain:
        new_mon = new monster_a();
        mon_a_list.push_back(new_mon);
        mon_a_count++;
        break;
    case cyber_terrain:
        new_mon = new monster_b();
        mon_b_list.push_back(new_mon);
        mon_b_count++;
        break;
    case urban_terrain:
        new_mon = new monster_c();
        mon_c_list.push_back(new_mon);
        mon_c_count++;
        break;
    }

    return new_mon;
}

void monster::destroy_monster() {
    for (auto mon : mon_a_list) {
        delete mon;
    }

    for (auto mon : mon_b_list) {
        delete mon;
    }

    for (auto mon : mon_c_list) {
        delete mon;
    }
}

void monster_routine(monster* mon, player target_player) {
    mon->find_route();
    mon->attack_special(target_player);
}

void create_monster(const int terrain_type, int count) {
    for (int i = 0; i < count; ++i) {
        monster::create_monster(terrain_type);
    }
}

void attact_all(const int terrain_type) {
    int mon_count, i;
    player target_player_dummy;

    mon_count = monster::get_monster_count(terrain_type);
    for (i = 0; i < mon_count; ++i) {
        monster_routine(monster::get_monster(terrain_type, i), target_player_dummy);
    }
}

int main() {
    create_monster(forest_terrain, 5);
    create_monster(cyber_terrain, 7);
    create_monster(urban_terrain, 6);

    attact_all(forest_terrain);
    attact_all(cyber_terrain);
    attact_all(urban_terrain);

    monster::destroy_monster();
    return 0;
}