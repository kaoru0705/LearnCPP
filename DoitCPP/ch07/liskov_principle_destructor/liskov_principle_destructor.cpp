#include <iostream>

class monster {
public:
    monster() {
        std::cout << "monster Ŭ���� ������" << std::endl;
    };
    ~monster() {
        std::cout << "monster Ŭ���� �Ҹ���" << std::endl;
    };
};

//���� A�� �⺻ Monster Ŭ�����κ��� ���
class monster_a : public monster {
public:
    monster_a() {
        std::cout << "monster_a Ŭ���� ������" << std::endl;
    };
    ~monster_a() {
        std::cout << "monster_a Ŭ���� �Ҹ���" << std::endl;
    }
};

int main() {
    monster* forest_monster{ new monster_a{} }; // ���� ���ε�
    delete forest_monster;
    return 0;
}
//��ü�� ������ ���� ���� ���ε��� �ƴ϶�,
//���� ������ Ÿ��(new monster_a)�� �������� ������ ������ �̹� �����˴ϴ�.
//
//�׷��� monster* ��� �θ� Ÿ�� �����ͷ� �޴���,
//new monster_a��� �� ���� �����Ϸ���
//
//"monster_a�� �����ڸ� ȣ���ϰ�, �� ���� monster�� �����ڵ� ȣ��"
//�� �ڵ带 ����ϴ�.
//
//��, �����ڴ� ���� �Լ� ������ ����Ǵ� �� �ƴ϶�,
//��ü ���� ������ ȣ�� ������ �̹� �����Ǵ� ����.
// 
//delete ������ ������ Ÿ���� monster*�Դϴ�.
//
//�θ� �Ҹ��ڰ� ���� �Լ��� �ƴϸ�, C++�� ���� ���ε��� ����մϴ�.
//
//��, monster�� �Ҹ��ڸ� ȣ���ϰ� ���������ϴ�.
//�ڽ��� �Ҹ��ڰ� ���� ȣ����� ������ �ڽ� ��ü ���ҽ��� �������� ���� �� �޸� ���� ����.