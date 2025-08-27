#include <iostream>
#include <memory>

class class_object {
public:
    class_object() {
        std::cout << "�޸𸮰� �Ҵ� �Ǿ����ϴ�." << std::endl;
    };
    ~class_object() {
        std::cout << "�޸𸮰� ���� �Ǿ����ϴ�." << std::endl;
    };
    void print_out() {
        std::cout << "��ü�� �Լ��� ȣ���մϴ�." << std::endl;
    };
};

int main() {
    // ����Ʈ �����ͷ� �޸� ���� ����
    std::unique_ptr<class_object> unique_pointer{ new class_object() };
    unique_pointer->print_out();

    auto unique_pointer2{ std::make_unique<class_object>() };
    unique_pointer2->print_out();

    return 0;
}