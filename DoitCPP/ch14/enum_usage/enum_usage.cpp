#include <iostream>
#include <typeinfo>

enum class monster_enum : char
{
    monster_a_type, monster_b_type = 'b', monster_c_type = 'c'
};

enum struct terrain_enum : int
{
    forest_terrain_type, cyber_terrain_type, urban_terrain_type
};

enum weapon_enum
{
    gun_type, machine_gun_type, arrow_type = 10
};

class monster {
public:
    monster(monster_enum monster_type, terrain_enum terrain_type, weapon_enum weapon_type)
        : monster_type_definition{ monster_type },
        main_field{ terrain_type },
        main_weapon{ weapon_type }
    {
    };

private:
    monster_enum monster_type_definition;
    terrain_enum main_field;
    weapon_enum main_weapon;

    friend void print_monster_location(monster& mon) {
        switch (mon.main_field) {
        case terrain_enum::forest_terrain_type:
            std::cout << "숲 공간";
            break;
        case terrain_enum::cyber_terrain_type:
            std::cout << "사이버 공간";
            break;
        case terrain_enum::urban_terrain_type:
            std::cout << "도시 공간";
            break;
        }
    }

    friend void print_monster_weapon(monster& mon) {
        switch (mon.main_weapon) {
        case gun_type:
            std::cout << "권총";
            break;
        case machine_gun_type:
            std::cout << "기관총";
            break;
        case arrow_type:
            std::cout << "화살";
            break;
        }
    }
};

int main()
{
    monster monster_in_forest{ monster{
        monster_enum::monster_a_type,
        terrain_enum::forest_terrain_type,
        gun_type } };

    monster monster_with_arrow{ monster{
        monster_enum::monster_b_type,
        terrain_enum::cyber_terrain_type,
        arrow_type } };

    std::cout << "첫번째 몬스터는 ";
    print_monster_location(monster_in_forest);
    std::cout << "(이)가 활동 지형이고, " << std::endl;
    print_monster_weapon(monster_in_forest);
    std::cout << " 무기를 주로 다룬다." << std::endl << std::endl;

    std::cout << "두번째 몬스터는 ";
    print_monster_location(monster_with_arrow);
    std::cout << "(이)가 활동 지형이고, " << std::endl;
    print_monster_weapon(monster_with_arrow);
    std::cout << " 무기를 주로 다룬다." << std::endl;
}
