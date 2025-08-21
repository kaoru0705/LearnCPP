#include <iostream>
#include <random>

int main() {
    std::random_device rng;

    for (int i = 0; i < 10; i++) {
        auto result{ rng() };
        std::cout << result << std::endl;
    }

    return 0;
}
