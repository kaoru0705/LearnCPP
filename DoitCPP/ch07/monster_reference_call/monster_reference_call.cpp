#include <iostream>


class character {
public:
	character() : hp(100), power(100) {};

protected:
	int hp;
	int power;
};

//character Ŭ������ ��� ���� player Ŭ����
class player : public character {
public:
	player() {};
};

//�⺻ Monster Ŭ����
class monster {
public:
	monster() {};
	void get_damage(int _damage) {};
	void attack(player target_player) {};
	void attack_special(player target_player);
};

void monster::attack_special(player target_player) {
	std::cout << "�⺻ ���� : ������ - 10 hp" << std::endl;
}

//���� A�� �⺻ Monster Ŭ�����κ��� ���
class monster_a : public monster, character {
public:
	//��ӹ��� �Լ� �������̵� 
	void attack_special(player target_player);
};

void monster_a::attack_special(player target_player) {
	std::cout << "���ޱ� ���� : ������ - 15 hp" << std::endl;
}

//���� B�� �⺻ Monster Ŭ�����κ��� ���
class monster_b : public monster, character {
public:
	//��ӹ��� �Լ� �������̵�
	void attack_special(player target_player);
};

void monster_b::attack_special(player target_player) {
	std::cout << "���� ���� : ������ - 0 hp" << std::endl;
}

//���� C�� �⺻ Monster Ŭ�����κ��� ���
class monster_c : public monster, character {
public:
	//��ӹ��� �Լ� �������̵�
	void attack_special(player target_player);
};

void monster_c::attack_special(player target_player) {
	std::cout << "���� ���� ���� : ������ - 100 hp" << std::endl;
}

int main() {
	player player_1;
	monster_a forest_monster;

	monster& mon = forest_monster;
	monster_a& mon_a = forest_monster;

	std::cout << std::endl << "�θ� Ŭ���� ���۷����� ����" << std::endl;
	mon.attack_special(player_1);

	std::cout << std::endl << "�ڽ� Ŭ���� ���۷����� ����" << std::endl;
	mon_a.attack_special(player_1);


	return 0;
}