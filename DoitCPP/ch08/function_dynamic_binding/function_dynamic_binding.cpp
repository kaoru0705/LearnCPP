#include <iostream>


class character {
public:
	character() : hp{ 100 }, power{ 100 }
	{};
	void get_damage(int _damage) {};

protected:
	int hp;
	int power;
};

//Player Ŭ����
class player : public character {
public:
	player() {};
};

//�⺻ Monster Ŭ����
class monster {
public:
	monster() {};
	virtual void attack_special(player target_player);
};

void monster::attack_special(player target_player) {
	std::cout << "�⺻ ���� : ������ - 10 hp" << std::endl;
}

//���� A�� �⺻ Monster Ŭ�����κ��� ���
class monster_a : public monster, character {
public:
	//��ӹ��� �Լ� �������̵� 
	virtual void attack_special(player target_player) override;
};

void monster_a::attack_special(player target_player) {
	std::cout << "���ޱ� ���� : ������ - 15 hp" << std::endl;
}

int main() {
	player player_1;

	monster mother_monster;
	monster_a forest_monster;

	mother_monster.attack_special(player_1);

	monster* mon = &forest_monster;
	std::cout << std::endl << "�θ� Ŭ������ ���ɽ��� �� ����" << std::endl;
	mon->attack_special(player_1);

	std::cout << std::endl << "�θ� Ŭ������ �����Ͽ� ����" << std::endl;
	mon->::monster::attack_special(player_1);

	mon = &mother_monster;
	std::cout << std::endl << "�θ� Ŭ������ ����" << std::endl;
	mon->attack_special(player_1);

	return 0;
}