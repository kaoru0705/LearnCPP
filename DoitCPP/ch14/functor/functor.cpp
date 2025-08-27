#include <iostream>

struct bomb {
    void operator()() {
        std::cout << "꽝!" << std::endl;
    }

    void operator()(int range) {
        std::cout << "반경 " << range << "m내 플레이어 공격!" << std::endl;
    }
};

int main() {
    bomb mine;

    mine();
    mine(30);

    return 0;
}