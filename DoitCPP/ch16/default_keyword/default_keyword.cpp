#include <iostream>

class monster_a {
public:
    // �����Ϸ� �Ǵ� �� �����ϴ� �⺻ ������ ���
    monster_a() = default;
    monster_a(int init_hp, int init_power)
        : hp(init_hp), power(init_power) {
    };
    int hp, power;
};

class monster_b {
public:
    // �ƹ� ������ ���� �ʴ� �⺻ ������ ����
    monster_b() {};
    monster_b(int init_hp, int init_power)
        : hp(init_hp), power(init_power) {
    };
    int hp, power;
};

class monster_c {
public:
    // �Ű����� ���� �⺻ ������ ���� ���� ����
    monster_c(int init_hp, int init_power)
        : hp(init_hp), power(init_power) {
    };
    int hp, power;
};

int main() {

    // �⺻ ������ ����Ͽ� ��ü ����
    monster_a mon_a{};

    // �ƹ� ������ ���� �ʴ� �⺻ �����ڸ� ����Ͽ� ��ü ����
    monster_b mon_b{};

    // ���� C�� �Ű������� ���� �⺻ �����ڰ� ����
    // �Ʒ� �ڵ� ó�� ��ü�� ������ �ȵ˴ϴ�.
    //monster_c mon_c{};

    std::cout << "���� A(" << mon_a.hp << ", " << mon_a.power << ")" << std::endl;
    std::cout << "���� B(" << mon_b.hp << ", " << mon_b.power << ")" << std::endl;
}
