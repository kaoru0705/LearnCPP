#include <iostream>
#include <string>

class character {
public:
    character() : hp{100}, power{100}
    {
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
        : monster_type{ "�Ϲ�" }     // ���� �ʱ�ȭ
        , location{ 0,0 }              // ������ �ʱ�ȭ
        , unique_id{ ++total_count } // ��� ���� �ʱ�ȭ
        , target{ attack_target }      // �������� ���� �ʱ�ȭ
    {       
        difficult_level = 10;         // �����ʱ�ȭ
        quiz = new char[1024];        // ���� �޸� �Ҵ�
    };

    ~monster_b() {
        delete[]quiz;
        total_count--;
    };

    monster_b(const monster_b& ref);    // ���� ������ ����(�����ε�) ���⼭ ��ü�� �����ص� �ȴ�.

    //��ӹ��� �Լ� �������̵� 
    virtual void attack_special(player target_player) override {
        std::cout << "���� ���� : ������ - 0 hp" << std::endl;
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

monster_b::monster_b(const monster_b& ref)      // ���� ������ ����(���� ����) ���Ǹ� Ŭ���� �ۿ��� �������� �׻� monster_b::�� �ٿ��� �ȴ�.
    : unique_id(++total_count)
    , target(ref.target)
{
    quiz = new char[1024];
    strcpy_s(quiz, strlen(ref.quiz) + 1, ref.quiz);
    monster_type = ref.monster_type;
    difficult_level = ref.difficult_level;
    location[0] = ref.location[0];
    location[1] = ref.location[1];
}

int main() {
    player first_player;
    monster_b first_mon{ first_player };
    first_mon.set_quiz("��ħ�� �׹�, ���ɿ��� �ι�, ���ῡ�� �ι��� ����?");
    first_mon.set_difficult_level(100);
    first_mon.set_type("�������� ����");
    first_mon.set_location(30, 30);

    monster_b second_mon{ first_mon };
    second_mon.set_quiz("���� ������ ���� ������ �ɱ�?");
    second_mon.set_location(45, 50);


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