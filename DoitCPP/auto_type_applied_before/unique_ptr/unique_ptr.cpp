#include <iostream>
#include <memory>

class class_object {
public:
    class_object() {
        std::cout << "메모리가 할당 되었습니다." << std::endl;
    };
    ~class_object() {
        std::cout << "메모리가 해제 되었습니다." << std::endl;
    };
    void print_out() {
        std::cout << "객체의 함수를 호출합니다." << std::endl;
    };
};

int main() {
    // 스마트 포인터로 메모리 누수 방지
    std::unique_ptr<class_object> unique_pointer{ new class_object() };
    unique_pointer->print_out();

    auto unique_pointer2{ std::make_unique<class_object>() };
    unique_pointer2->print_out();

    return 0;
}