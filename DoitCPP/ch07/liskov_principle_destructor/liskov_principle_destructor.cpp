#include <iostream>

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
class monster_a : public monster {
public:
    monster_a() {
        std::cout << "monster_a 클래스 생성자" << std::endl;
    };
    ~monster_a() {
        std::cout << "monster_a 클래스 소멸자" << std::endl;
    }
};

int main() {
    monster* forest_monster{ new monster_a{} }; // 정적 바인딩
    delete forest_monster;
    return 0;
}
//객체를 생성할 때는 정적 바인딩이 아니라,
//실제 생성할 타입(new monster_a)이 무엇인지 컴파일 시점에 이미 결정됩니다.
//
//그래서 monster* 라는 부모 타입 포인터로 받더라도,
//new monster_a라고 쓴 순간 컴파일러는
//
//"monster_a의 생성자를 호출하고, 그 전에 monster의 생성자도 호출"
//로 코드를 만듭니다.
//
//즉, 생성자는 가상 함수 개념이 적용되는 게 아니라,
//객체 생성 시점에 호출 순서가 이미 고정되는 거죠.
// 
//delete 시점에 포인터 타입은 monster*입니다.
//
//부모 소멸자가 가상 함수가 아니면, C++은 정적 바인딩을 사용합니다.
//
//즉, monster의 소멸자만 호출하고 끝나버립니다.
//자식의 소멸자가 전혀 호출되지 않으니 자식 객체 리소스는 해제되지 않죠 → 메모리 누수 가능.