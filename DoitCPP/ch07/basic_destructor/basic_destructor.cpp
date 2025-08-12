#include <iostream>
#include <random>

class character {
public:
    character() {
        std::cout << "character 클래스 생성자" << std::endl;
    };
    ~character() {
        std::cout << "charactor 클래스 소멸자" << std::endl;
    }
};

class monster {
public:
    monster() {
        std::cout << "monster 클래스 생성자" << std::endl;
    };
    ~monster() {
        std::cout << "monster 클래스 소멸자" << std::endl;
    };
};

//몬스터 A는 기본 Monster 클래스로부터 상속
class monster_a : public monster, character {
public:
    monster_a() {
        std::cout << "monster_a 클래스 생성자" << std::endl;
    };

    ~monster_a() {
        std::cout << "monster_a 클래스 소멸자" << std::endl;
    }
};

int main() {
    monster_a forest_monster;
    return 0;
}