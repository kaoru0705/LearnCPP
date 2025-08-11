/*https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists*/
#include <iostream>
#include <string>

class character {
public:
    character() : hp(100), power(100) {
    };

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
    void attack(player target_player) {};
    virtual void attack_special(player target_player);
};

void monster::attack_special(player target_player) {
    std::cout << "�⺻ ���� : ������ - 10 hp" << std::endl;
}


//���� A�� �⺻ Monster Ŭ�����κ��� ���
class monster_b : public monster, character {
public:
    monster_b(player& attack_target)
        : monster_type("�Ϲ�"),         // direct-initilization
        location{ 0,0 },                // uniform-initilization or list-initialization or brace-initialization
        unique_id(++total_count),       // ��� ���� �ʱ�ȭ
        target(attack_target) {         // �������� ���� �ʱ�ȭ
        difficult_level = 10;           // copy-initilization
        quiz = new char[1024];          // ���� �޸� �Ҵ�
    };

    ~monster_b() {
        delete[]quiz;
        total_count--;
    };

    void set_quiz(const char* new_quiz) { strcpy_s(quiz, 1024, new_quiz); };
    void set_type(std::string type) { monster_type = type; };
    void set_difficult_level(int level) { difficult_level = level; };
    void set_location(int x, int y) { location[0] = x; location[1] = y; };
    char* get_quiz() { return quiz; };
    std::string get_type() { return monster_type; };
    int get_difficult_level() { return difficult_level; };
    int get_x_location() { return location[0]; };
    int get_y_location() { return location[1]; };
    static int get_total_count() { return total_count; };

private:
    const int unique_id;
    player& target;
    static int total_count;
    char* quiz;
    std::string monster_type;
    int difficult_level;
    int location[2];
};

int monster_b::total_count = 0; // ���� ���� �ʱ�ȭ

int main() {
    player first_player;
    monster_b first_mon{ first_player };
    first_mon.set_quiz("��ħ�� �׹�, ���ɿ��� �ι�, ���ῡ�� �ι��� ����?");
    first_mon.set_difficult_level(100);
    first_mon.set_type("�������� ����");
    first_mon.set_location(30, 30);
    std::cout << "������ ����? : " << monster_b::get_total_count() << std::endl;
    monster_b second_mon{ first_player };
    second_mon.set_quiz("���� ������ ���� ������ �ɱ�?");
    second_mon.set_location(45, 50);
    std::cout << "������ ����? : " << monster_b::get_total_count() << std::endl;

    std::cout << "[" << first_mon.get_x_location() << " , " << first_mon.get_y_location()
        << "] ù��° ����(" << first_mon.get_type() << " - "
        << first_mon.get_difficult_level()
        << ")�� ���� �������� : " << first_mon.get_quiz() << std::endl;

    std::cout << "[" << second_mon.get_x_location() << " , " << second_mon.get_y_location()
        << "] �ι�° ����(" << second_mon.get_type() << " - "
        << second_mon.get_difficult_level()
        << ")�� ���� �������� : " << second_mon.get_quiz() << std::endl;

    return 0;
}
