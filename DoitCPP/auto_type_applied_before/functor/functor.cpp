#include <iostream>

struct bomb {
    void operator()() {
        std::cout << "��!" << std::endl;
    }

    void operator()(int range) {
        std::cout << "�ݰ� " << range << "m�� �÷��̾� ����!" << std::endl;
    }
};

int main() {
    bomb mine;

    mine();
    mine(30);

    return 0;
}