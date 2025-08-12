#include <iostream>
#include <random>

class monster {
public:
    monster() {
        std::cout << "monster 클래스 생성자" << std::endl;
    };
    virtual ~monster() {
        std::cout << "monster 클래스 소멸자" << std::endl;
    };
};

//몬스터 A는 기본 Monster 클래스로부터 상속
class monster_a : public monster {
public:
    monster_a() {
        std::cout << "monster_a 클래스 생성자" << std::endl;
    };
    virtual ~monster_a() {
        std::cout << "monster_a 클래스 소멸자" << std::endl;
    }
};

int main() {
    monster* forest_monster{ new monster_a{} };
    delete forest_monster;
    return 0;
}