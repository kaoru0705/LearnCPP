#include <iostream>

class character {
public:
	character() : hp{ 100 }, power{ 100 } {};

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
	void attack(player target_player) {};
	virtual void attack_special(player target_player);   // ���� �Լ� ����
};

void monster::attack_special(player target_player) {
	std::cout << "�⺻ ���� : ������ - 10 hp" << std::endl;
}

//���� A�� �⺻ Monster Ŭ�����κ��� ���
class monster_a : public monster, character {
public:
	//���� �Լ� �������̵� ���� 
	virtual void attack_special(player target_player) override;
};

// ���� �Լ� �������̵�
void monster_a::attack_special(player target_player) {
	std::cout << "���ޱ� ���� : ������ - 15 hp" << std::endl;
}

//���� B�� �⺻ Monster Ŭ�����κ��� ���
class monster_b : public monster, character {
public:
	//��ӹ��� �Լ� �������̵�
	virtual void attack_special(player target_player) override;
};

void monster_b::attack_special(player target_player) {
	std::cout << "���� ���� : ������ - 0 hp" << std::endl;
}

//���� C�� �⺻ Monster Ŭ�����κ��� ���
class monster_c : public monster, character {
public:
	//��ӹ��� �Լ� �������̵�
	virtual void attack_special(player target_player) override;
};

void monster_c::attack_special(player target_player) {
	std::cout << "���� ���� ���� : ������ - 100 hp" << std::endl;
}

int main() {
	player player_1;

	monster_a forest_monster;

	monster& mon = forest_monster;   // ��ĳ���� �߻�
	monster_a& mon_a = forest_monster;

	std::cout << std::endl << "�θ� Ŭ������ ��ĳ���� �� ����" << std::endl;
	mon.attack_special(player_1);  // monster_a�� �������̵� �Լ� ȣ��

	std::cout << std::endl << "�ڽ� Ŭ������ ����" << std::endl;
	mon_a.attack_special(player_1);

	std::cout << std::endl << "���� �����ڷ� ����" << std::endl;
	mon_a.monster::attack_special(player_1);

	return 0;
}