#include <iostream>

class character {
public:
	character() : hp{ 100 }, power{ 100 } {};

protected:
	int hp;
	int power;
};

//Player 클래스
class player : public character {
public:
	player() {};
};

//기본 Monster 클래스
class monster {
public:
	monster() {};
	void attack(player target_player) {};
	virtual void attack_special(player target_player);   // 가상 함수 선언
};

void monster::attack_special(player target_player) {
	std::cout << "기본 공격 : 데미지 - 10 hp" << std::endl;
}

//몬스터 A는 기본 Monster 클래스로부터 상속
class monster_a : public monster, character {
public:
	//가상 함수 오버라이드 선언 
	virtual void attack_special(player target_player) override;
};

// 가상 함수 오버라이딩
void monster_a::attack_special(player target_player) {
	std::cout << "인텡글 공격 : 데미지 - 15 hp" << std::endl;
}

//몬스터 B는 기본 Monster 클래스로부터 상속
class monster_b : public monster, character {
public:
	//상속받은 함수 오버라이딩
	virtual void attack_special(player target_player) override;
};

void monster_b::attack_special(player target_player) {
	std::cout << "가상 공격 : 데미지 - 0 hp" << std::endl;
}

//몬스터 C는 기본 Monster 클래스로부터 상속
class monster_c : public monster, character {
public:
	//상속받은 함수 오버라이딩
	virtual void attack_special(player target_player) override;
};

void monster_c::attack_special(player target_player) {
	std::cout << "강력 뇌전 공격 : 데미지 - 100 hp" << std::endl;
}

int main() {
	player player_1;

	monster_a forest_monster;

	monster& mon = forest_monster;   // 업캐스팅 발생
	monster_a& mon_a = forest_monster;

	std::cout << std::endl << "부모 클래스로 업캐스팅 후 공격" << std::endl;
	mon.attack_special(player_1);  // monster_a의 오버라이딩 함수 호출

	std::cout << std::endl << "자식 클래스로 공격" << std::endl;
	mon_a.attack_special(player_1);

	std::cout << std::endl << "범위 연산자로 공격" << std::endl;
	mon_a.monster::attack_special(player_1);

	return 0;
}